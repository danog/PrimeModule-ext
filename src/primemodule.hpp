#pragma once
/*
 * This taken from the source code of tgnet library v. 1.0
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Nikolai Kudashov, 2015.
 */

#include <cstdint>
#include <cstdlib>
#include <stdexcept>

namespace PrimeModule {
    inline uint64_t gcd(uint64_t a, uint64_t b) {
        while (a != 0 && b != 0) {
            while ((b & 1) == 0) {
                b >>= 1;
            }
            while ((a & 1) == 0) {
                a >>= 1;
            }
            if (a > b) {
                a -= b;
            } else {
                b -= a;
            }
        }
        return b == 0 ? a : b;
    }

    // Factorize the provided semiprime, throws an std::runtime_error on failure
    uint32_t factorize(uint64_t number) {
        int32_t it = 0, i, j;
        uint64_t g = 0;
        for (i = 0; i < 3 || it < 1000; i++) {
            uint64_t t = ((lrand48() & 15) + 17) % number;
            uint64_t x = (long long)lrand48() % (number - 1) + 1, y = x;
            int32_t lim = 1 << (i + 18);
            for (j = 1; j < lim; j++) {
                ++it;
                uint64_t a = x, b = x, c = t;
                while (b) {
                    if (b & 1) {
                        c += a;
                        if (c >= number) {
                            c -= number;
                        }
                    }
                    a += a;
                    if (a >= number) {
                        a -= number;
                    }
                    b >>= 1;
                }
                x = c;
                uint64_t z = x < y ? number + x - y : x - y;
                g = PrimeModule::gcd(z, number);
                if (g != 1) {
                    break;
                }
                if (!(j & (j - 1))) {
                    y = x;
                }
            }
            if (g > 1 && g < number) {
                break;
            }
        }

        if (g > 1 && g < number) {
            return (uint32_t)g;
        } else {
            throw std::runtime_error("Factorization failed!");
        }
    }
}