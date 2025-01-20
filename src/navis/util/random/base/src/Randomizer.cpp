/**
 * --------------------------------------------------
 *
 * @file    Randomizer.cpp
 * @brief   Randomizer Base Class Source
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#include "navis/util/random/base/Randomizer.h"

#include <chrono>
#include <mutex>
#include <limits>

namespace
{
    class SeedGenerator
    {
        // "SeedGenerator" members
        private:

            bool m_isSeedGenerated {false};
            std::uint_fast64_t m_initialSeed;

            std::mutex m_generatorMutex;
            std::ranlux24_base m_generator;
            std::uniform_int_distribution<> m_uniformDist;

        // "SeedGenerator" methods
        public:

            /**
             * @brief Class constructor
             */
            SeedGenerator()
              : m_initialSeed(std::chrono::duration_cast<std::chrono::microseconds>(
                                std::chrono::high_resolution_clock::now().time_since_epoch()).count())
              , m_generator(m_initialSeed)
              , m_uniformDist(1, std::numeric_limits<int>::max())
            {    
            }

            /**
             * @brief Global random seed setter method
             *        Thread-safe operation method by mutex lock
             */
            void setSeed(std::uint_fast64_t seed)
            {
                std::lock_guard<std::mutex> syncLock(m_generatorMutex);

                if(seed > 0)
                {
                    if(m_isSeedGenerated)
                    {
                        // @TODO WARNING MESSEGE "[SeedGenerator]: Random number generation already started. Changing seed now will not lead to deterministic sampling."
                    }
                    else
                    {
                        m_initialSeed = seed;
                    }
                }

                else
                {
                    if(m_isSeedGenerated)
                    {
                        // @TODO WARNING MESSEGE "[SeedGenerator]: Random generator seed cannot be 0. Seed has been igonored."
                        return;
                    }
                    // @TODO WARNING MESSEGE "[SeedGenerator]: Random generator seed cannot be 0. Using 1 instead."
                    seed = 1;
                }

                m_generator.seed(seed);
            }

            /**
             * @brief Global random seed getter method
             *        Thread-safe operation method by mutex lock
             */
            std::uint_fast64_t getInitialSeed()
            {
                std::lock_guard<std::mutex> syncLock(m_generatorMutex);
                return m_initialSeed;
            }

            /**
             * @brief Global random seed getter method
             *        Thread-safe operation method by mutex lock
             */
            std::uint_fast64_t getNextSeed()
            {
                std::lock_guard<std::mutex> syncLock(m_generatorMutex);
                m_isSeedGenerated = true;
                return m_uniformDist(m_generator);
            }

    }; // class SeedGenerator

    /**
     * @brief anonymous::Seed Generator Functions
     *        Below are singleton functions
     */
    std::once_flag g_seedGeneratorFlag;
    std::unique_ptr<SeedGenerator> g_seedGenerator;

    /**
     * @brief Seed generator initialization function
     *        It can be called only once in a process
     */
    void initSeedGenerator()
    {
        g_seedGenerator.reset(new SeedGenerator());
    }

    /**
     * @brief Seed generator object getter function
     *        It can be called only once in a process
     */
    SeedGenerator &getSeedGenerator()
    {
        std::call_once(g_seedGeneratorFlag, &initSeedGenerator);
        return *g_seedGenerator;
    }

} // namespace

/**
 * @brief Class constructor
 * @param NONE Always sets a different random seed
 */
navis::base::Randomizer::Randomizer()
  : m_localSeed(getSeedGenerator().getNextSeed())
  , m_generator(m_localSeed)
{
    // @TODO add shpere data
}

/**
 * @brief Class constructor
 * @param localSeed Set to the specified instance seed
 */
navis::base::Randomizer::Randomizer(std::uint_fast64_t localSeed)
  : m_localSeed(localSeed)
  , m_generator(m_localSeed)
{
    // @TODO add shpere data
}

/**
 * @brief Class destructor
 * @param localSeed Set to the specified instance seed
 */
navis::base::Randomizer::~Randomizer()
{
}

/**
 * @brief Global random seed setter method
 * @param gloabalSeed Global random seed that is global variable
 */
void navis::base::Randomizer::setGlobalSeed(std::uint_fast64_t globalSeed)
{
    getSeedGenerator().setSeed(globalSeed);
}

/**
 * @brief Global random seed getter method
 */
std::uint_fast64_t navis::base::Randomizer::getGlobalSeed()
{
    return getSeedGenerator().getInitialSeed();
}

/**
 * @brief Local random seed setter method and reset distribution
 * @param localSeed Local random seed
 * @details Derivated class must add distribution resert function
 */
void navis::base::Randomizer::setLocalSeed(std::uint_fast64_t localSeed)
{
    m_localSeed = localSeed;
    m_generator.seed(m_localSeed);
}

/**
 * @brief Local random seed getting method
 */
std::uint_fast64_t navis::base::Randomizer::getLocalSeed()
{
    return m_localSeed;
}
