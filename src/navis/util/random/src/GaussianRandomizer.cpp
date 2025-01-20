/**
 * --------------------------------------------------
 *
 * @file    GaussianRandomizer.cpp
 * @brief   Gaussian Randomizer Class Source
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#include "navis/util/random/GaussianRandomizer.h"

/**
 * @brief Class constructor
 * @param NONE Always sets a different random seed
 */
navis::util::GaussianRandomizer::GaussianRandomizer() 
  : navis::base::Randomizer()
{
}

/**
 * @brief Class constructor
 * @param localSeed Set to the specified instance seed
 */
navis::util::GaussianRandomizer::GaussianRandomizer(std::uint_fast64_t localSeed) 
  : navis::base::Randomizer(localSeed)
{
}

/**
 * @brief Local random seed setter method and reset distribution
 * @param localSeed Local random seed
 */
void navis::util::GaussianRandomizer::setLocalSeed(std::uint_fast64_t localSeed)
{
    navis::base::Randomizer::setLocalSeed(localSeed);
    m_normalDist.reset();
}

/**
 * @brief Real random number generation method by gaussian distribution
 * @param mean Mean of the gaussian distribution (default : 0.0)
 * @param stdDev Standard deviation of the gausian distribution (default : 1.0)
 */
double navis::util::GaussianRandomizer::gaussianDouble(const double &mean, const double &stdDev)
{
    return m_normalDist(m_generator) * stdDev + mean;
}

/**
 * @brief Real random number generation method by folded gaussian distribution
 * @param lowerBound Lower boundary of the result
 * @param upperBound Upper boundary of the result
 * @param bias Foucusing value around upper boundary
 */
double navis::util::GaussianRandomizer::foldedGaussianDouble(const double &lowerBound, const double &upperBound, const double &bias)
{
    assert(lowerBound < upperBound);
    double mean = upperBound - lowerBound;
    double half = gaussianDouble(mean, mean / bias);

    half = (half > mean) ? (2.0 * mean - half) : half;
    double result = (half >= 0.0) ? (half + lowerBound) : lowerBound;
    
    return (result > upperBound) ? upperBound : result;
}

/**
 * @brief Integer random number generation method by folded gaussian distribution
 * @param lowerBound Lower boundary of the result
 * @param upperBound Upper boundary of the result
 * @param bias Foucusing value around upper boundary
 */
int navis::util::GaussianRandomizer::foldedGaussianInt(const int &lowerBound, const int &upperBound, const double &bias)
{
    auto result = (int)floor(foldedGaussianDouble((double)lowerBound, (double)(upperBound) + 1.0, bias));
    return (result > upperBound) ? upperBound : result;
}
