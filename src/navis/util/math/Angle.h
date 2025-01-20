/**
 * --------------------------------------------------
 *
 * @file    Angle.h
 * @brief   Angle Helper Functions
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#ifndef NAVIS_UTIL_MATH_ANGLE_H_
#define NAVIS_UTIL_MATH_ANGLE_H_

#include <cmath>

namespace navis
{
    namespace util
    {
        /**
         * @brief Convert unit from degree to radians
         * @param degree Degree unit value
         */
        double deg2rad(const double &degree)
        {
            return degree / 180.0 * M_PI;
        }

        /**
         * @brief Convert unit from radians to degree
         * @param radians Radian unit value
         */
        double rad2deg(const double &radians)
        {
            return radians * 180.0 / M_PI;
        }

        /**
         * @brief Wrap around -PI to PI
         * @param radians Radian unit value
         */
        double mod2pi(double radians)
        {
            radians = fmod(radians, M_2_PI);

            if(radians < -M_PI)
            {
                return radians + M_2_PI;
            }

            else if(radians > M_PI)
            {
                return radians - M_2_PI;
            }

            return radians;
        }

        // @TODO More helper functions

    } // namespace util

} // namespace navis

#endif // NAVIS_UTIL_MATH_ANGLE_H_
