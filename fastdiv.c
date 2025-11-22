#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

/*
 * Compute the sum of proper divisors of n using factorization into primes.
 *
 * Assumptions:
 * - The array P and its size P_COUNT are defined in primes.h as the list
 *   of ascending prime numbers (e.g., up to sqrt(UINT32_MAX) or similar).
 * - 1 <= n <= UINT32_MAX
 *
 * Note:
 * - This implementation does not guard against overflow in intermediate
 *   products. For very large inputs, sum may overflow uint32_t.
 */
uint32_t fast_sum_proper_divisors(uint32_t n)
{
    if (n <= 1U) {
        return 0U;  /* 0 and 1 have no proper divisors with positive sum */
    }

    uint32_t x   = n;
    uint32_t sum = 1U;

    for (size_t i = 0U; i < P_COUNT; ++i) {
        const uint32_t p = P[i];

        /* No need to continue once p > sqrt(x). Avoids using floating point. */
        if (p > x / p) {
            break;
        }

        if (x % p == 0U) {
            uint32_t sub = p + 1U;
            x /= p;

            while (x % p == 0U) {
                x /= p;
                /* sub = 1 + p + p^2 + ... + p^k */
                sub = sub * p + 1U;
            }

            sum *= sub;
        }
    }

    /* If x > 1 here, x is prime and contributes (1 + x) to the divisor sum. */
    if (x > 1U) {
        sum *= (x + 1U);
    }

    /* Convert sum of all divisors to sum of proper divisors by subtracting n. */
    return sum - n;
}

/* Parse a uint32_t from a C string. Returns true on success, false on error. */
static bool parse_uint32(const char *str, uint32_t *out_value)
{
    if (str == NULL || out_value == NULL) {
        return false;
    }

    errno = 0;
    char   *endptr = NULL;
    unsigned long value = strtoul(str, &endptr, 10);

    if (errno != 0 || endptr == str || *endptr != '\0') {
        return false;
    }
    if (value > UINT32_MAX) {
        return false;
    }

    *out_value = (uint32_t)value;
    return true;
}

int main(int argc, char *argv[])
{
    uint32_t n = 21387312U;

    if (argc > 1) {
        if (!parse_uint32(argv[1], &n)) {
            fprintf(stderr, "Error: invalid unsigned integer: '%s'\n", argv[1]);
            return EXIT_FAILURE;
        }
    }

    const uint32_t result = fast_sum_proper_divisors(n);

    printf("Sum of proper divisors for (%" PRIu32 "): %" PRIu32 "\n", n, result);

    return EXIT_SUCCESS;
}
