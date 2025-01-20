/**
 * --------------------------------------------------
 *
 * @file    Randomizer.h
 * @brief   Randomizer Base Class Definition
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#ifndef NAVIS_UTIL_RANDOM_BASE_RANDOMIZER_H_
#define NAVIS_UTIL_RANDOM_BASE_RANDOMIZER_H_

#include <memory>
#include <random>
#include <cassert>
#include <cstdint>
#include <algorithm>

namespace navis
{
    namespace base
    {
        /**
         * @brief   navis::base::Randomizer
         * @details Global random seed and local random seed methods
         */
        class Randomizer
        {
            // "Randomizer" members
            protected:

                std::uint_fast64_t m_localSeed;
                std::mt19937 m_generator;

            // "Randomizer" methods
            private:

                /**
                 * @brief operator overloading
                 * @details non-copyable settings
                 */
                Randomizer(const Randomizer &) = delete;
                const Randomizer &operator=(const Randomizer &) = delete;

            protected:

                /**
                 * @brief Class constructor
                 * @param NONE Always sets a different random seed
                 * @param localSeed Set to the specified instance seed
                 */
                Randomizer();
                Randomizer(std::uint_fast64_t localSeed);

                /**
                 * @brief Class destructor
                 */
                virtual ~Randomizer();

            public:
                
                /**
                 * @brief Global random seed setter method
                 * @param gloabalSeed Global random seed that is global variable
                 */
                static void setGlobalSeed(std::uint_fast64_t globalSeed);

                /**
                 * @brief Global random seed getter method
                 */
                static std::uint_fast64_t getGlobalSeed();

                /**
                 * @brief Local random seed setter method and reset distribution
                 * @param localSeed Local random seed
                 */
                virtual void setLocalSeed(std::uint_fast64_t localSeed);

                /**
                 * @brief Local random seed getting method
                 */
                std::uint_fast64_t getLocalSeed();

                /**
                 * @brief Shuffle order
                 * @param begin First iterator of the class
                 * @param end   Last iterator of the class
                 */
                template <typename ClassIterator>
                void shuffle(ClassIterator begin, ClassIterator end)
                {
                    std::shuffle(begin, end, m_generator);
                }

        }; // class Randomizer

    } // namespace base

} // namespace navis

#endif // NAVIS_UTIL_RANDOM_RANDOMIZER_H_
