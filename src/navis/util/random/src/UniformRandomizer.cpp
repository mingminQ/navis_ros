/**
 * --------------------------------------------------
 *
 * @file    UniformRandomizer.cpp
 * @brief   Uniform Randomizer Class Source
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#include "navis/util/random/UniformRandomizer.h"

/**
 * @brief Class constructor
 * @param NONE Always sets a different random seed
 */
navis::util::UniformRandomizer::UniformRandomizer()
  : navis::base::Randomizer()
{
}

/**
 * @brief Class constructor
 * @param localSeed Set to the specified instance seed
 */
navis::util::UniformRandomizer::UniformRandomizer(std::uint_fast64_t localSeed) 
  : navis::base::Randomizer(localSeed)
{
}

/**
 * @brief Local random seed setter method and reset distribution
 * @param localSeed Local random seed
 */
void navis::util::UniformRandomizer::setLocalSeed(std::uint_fast64_t localSeed)
{
    navis::base::Randomizer::setLocalSeed(localSeed);
    m_uniformDist.reset();
}

/**
 * @brief Real random number generation method by uniform distribution
 * @param lowerBound Lower boundary of the result (default : 0.0)
 * @param upperBound Upper boundary of the result (default : 1.0)
 */
double navis::util::UniformRandomizer::uniformDouble(double lowerBound, double upperBound)
{
    assert(lowerBound < upperBound);
    return (upperBound - lowerBound) * m_uniformDist(m_generator) + lowerBound;
}

/**
 * @brief Integer random number generation method by uniform distribution
 * @param lowerBound Lower boundary of the result
 * @param upperBound Upper boundary of the result
 */
int navis::util::UniformRandomizer::uniformInt(int lowerBound, int upperBound)
{
    auto result = (int)floor(uniformDouble((double)lowerBound, (double)(upperBound) + 1.0));
    return (result > upperBound) ? upperBound : result;
}

/**
 * @brief Boolean random number generation method by uniform distribution
 */
bool navis::util::UniformRandomizer::uniformBool()
{
    return m_uniformDist(m_generator) < 0.5;
}

// @TODO DataType uniformQuaternion()

// @TODO DataType uniformEulerRPY()

// @TODO add sphere data uniform randomization
