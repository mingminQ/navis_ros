/**
 * --------------------------------------------------
 *
 * @file    ForwardDeclaration.h
 * @brief   Forward Declaration Macro Definition
 * @author  Minkyu Kil
 * @date    2025-01-01
 * @version 1.0
 *
 * Copyright (c) 2025, Minkyu Kil
 * All rights reserved
 *
 * --------------------------------------------------
 */

#ifndef NAVIS_UTIL_FORWARDDECLARATION_H_
#define NAVIS_UTIL_FORWARDDECLARATION_H_

#include <memory>

/**
 * @brief NAVIS_CLASS_FORWARD
 * @param CLASS_NAME Name of the class
 */
#define NAVIS_CLASS_FORWARD(CLASS_NAME)                 \
    class CLASS_NAME;                                   \
    using CLASS_NAME##Ptr = std::shared_ptr<CLASS_NAME>

#endif // NAVIS_UTIL_FORWARDDECLARATION_H_
