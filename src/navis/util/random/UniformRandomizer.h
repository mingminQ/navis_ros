/**
 * --------------------------------------------------
 *
 * @file    UniformRandomizer.h
 * @brief   Uniform Randomizer Class Definition
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#ifndef NAVIS_UTIL_RANDOM_UNIFORMRANDOMIZER_H_
#define NAVIS_UTIL_RANDOM_UNIFORMRANDOMIZER_H_

#include "navis/util/random/base/Randomizer.h"

namespace navis
{
    namespace util
    {
        /**
         * @brief   navis::util::UniformRandomizer
         * @details Uniform random number generator utility
         */
        class UniformRandomizer : public navis::base::Randomizer
        {
            // "UniformRandomizer" members
            private:

                /**
                 * @brief Uniform probability distribution
                 */
                std::uniform_real_distribution<> m_uniformDist{0, 1};

            // "UniformRandomizer" methods
            public:

                /**
                 * @brief Class constructor
                 * @param NONE Always sets a different random seed
                 * @param localSeed Set to the specified instance seed
                 */
                UniformRandomizer();
                UniformRandomizer(std::uint_fast64_t localSeed);

                /**
                 * @brief Class destructor
                 */
                ~UniformRandomizer() override = default;

                /**
                 * @brief Local random seed setter method and reset distribution
                 * @param localSeed Local random seed
                 */
                void setLocalSeed(std::uint_fast32_t localSeed) override;

                /**
                 * @brief Real random number generation method by uniform distribution
                 * @param lowerBound Lower boundary of the result (default : 0.0)
                 * @param upperBound Upper boundary of the result (default : 1.0)
                 */
                
                double uniformDouble(double lowerBound = 0.0, double upperBound = 1.0);
                /**
                 * @brief Integer random number generation method by uniform distribution
                 * @param lowerBound Lower boundary of the result
                 * @param upperBound Upper boundary of the result
                 */
                int uniformInt(int lowerBound, int upperBound);

                /**
                 * @brief Boolean random number generation method by uniform distribution
                 */
                bool uniformBool();

                // @TODO DataType uniformQuaternion()

                // @TODO DataType uniformEulerRPY()

                // @TODO add sphere data uniform randomization

        }; // class UniformRandomizer

    } // namespace util
    
} // namespace navis

#endif // NAVIS_UTIL_RANDOM_UNIFORMRANDOMIZER_H_
