/*
 * This taken from the source code of tgnet library v. 1.0
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Nikolai Kudashov, 2015.
 */

#include "primemodule.h"
#include "primemodule.hpp"

extern "C" int64_t factorize(uint64_t number)
{
    try {
        return PrimeModule::factorize(number);
    } catch (...) {
        return -1;
    }
}
extern "C" int32_t factorizeFFI(const char *number)
{
    try {
        return PrimeModule::factorize(std::stoull(number));
    } catch (...) {
        return -1;
    }
}