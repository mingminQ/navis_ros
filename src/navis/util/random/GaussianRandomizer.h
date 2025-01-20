/**
 * --------------------------------------------------
 *
 * @file    GaussianRandomizer.h
 * @brief   Gaussian Randomizer Class Definition
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#ifndef NAVIS_UTIL_RANDOM_GAUSSIANRANDOMIZER_H_
#define NAVIS_UTIL_RANDOM_GAUSSIANRANDOMIZER_H_

#include "navis/util/random/base/Randomizer.h"

#include <memory>
#include <random>
#include <cassert>
#include <cstdint>
#include <algorithm>

namespace navis
{
    namespace util
    {
        /**
         * @brief   navis::util::GaussianRandomizer
         * @details Gaussian random number generator utility
         */
        class GaussianRandomizer : public navis::base::Randomizer
        {
            private:

                /**
                 * @brief Normal gaussian probability distribution
                 */
                std::normal_distribution<> m_normalDist{0, 1};

            public:

                /**
                 * @brief Class constructor
                 * @param NONE Always sets a different random seed
                 * @param localSeed Set to the specified instance seed
                 */
                GaussianRandomizer();
                GaussianRandomizer(std::uint_fast64_t localSeed);

                /**
                 * @brief Class destructor
                 */
                ~GaussianRandomizer() override = default;

                /**
                 * @brief Local random seed setter method and reset distribution
                 * @param localSeed Local random seed
                 */
                void setLocalSeed(std::uint_fast64_t localSeed) override;

                /**
                 * @brief Real random number generation method by gaussian distribution
                 * @param mean Mean of the gaussian distribution (default : 0.0)
                 * @param stdDev Standard deviation of the gausian distribution (default : 1.0)
                 */
                double gaussianDouble(const double &mean = 0.0, const double &stdDev = 1.0);

                /**
                 * @brief Real random number generation method by folded gaussian distribution
                 * @param lowerBound Lower boundary of the result
                 * @param upperBound Upper boundary of the result
                 * @param bias Foucusing value around upper boundary
                 */
                double foldedGaussianDouble(const double &lowerBound = 0.0, const double &upperbound = 1.0, const double &bias = 1.0);

                /**
                 * @brief Integer random number generation method by folded gaussian distribution
                 * @param lowerBound Lower boundary of the result
                 * @param upperBound Upper boundary of the result
                 * @param bias Foucusing value around upper boundary
                 */
                int foldedGaussianInt(const int &lowerBound, const int &upperBound, const double &bias = 1.0);

        }; // class GaussianRandomizer

    } // namespace util

} // namespace navis

#endif // NAVIS_UTIL_RANDOM_GAUSSIANRANDOMIZER_H_
