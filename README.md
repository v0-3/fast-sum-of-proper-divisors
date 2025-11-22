# fast-sum-of-proper-divisors

A highly optimized implementation for computing the **sum of proper divisors** of an integer.  
Written in **C** for maximum performance, leveraging prime factorization to achieve significant speedups compared to naive divisor-scanning approaches.

---

## Overview

This project provides a fast function for computing the sum of proper divisors:

```c
unsigned int fast_sum(unsigned int n);
```

The implementation is located in **[fast.c](./fast.c)**.  
It relies on prime factor decomposition and therefore requires including **[primes.h](./primes.h)**.

The algorithm is designed for:

- High-performance number theory computations  
- Large-scale divisor sum evaluations  
- Situations where repeated or batch computations are needed  
- Environments where raw speed is critical and C is preferred

---

## Files

- **fast.c**  
  Contains the implementation of `fast_sum`, using prime factorization for efficient divisor-sum computation.

- **primes.h**  
  Provides prime-related utilities required by the algorithm (e.g., factorization logic or precomputed primes).

---

## Usage

Include the necessary header and call `fast_sum()`:

```c
#include "primes.h"
#include "fast.h"

unsigned int result = fast_sum(100);  // returns 117
```

---

© Luis Maya Aranda. All rights reserved.  
Licensed under the MIT License.
