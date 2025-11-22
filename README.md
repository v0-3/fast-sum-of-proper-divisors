# fast-sum-of-proper-divisors

A high-performance C implementation for computing the **sum of proper divisors** of a 32-bit integer using **prime-factor decomposition**.
The core function, `fast_sum_proper_divisors(uint32_t n)`, is optimized for speed and suitable for numerical analysis, number theory research, or competitive programming.

This project uses a precomputed list of primes (`primes.h`) to accelerate factorization.

---

## Features

- Modern C (C11) implementation
- Prime-factor decomposition for sub-millisecond performance
- Strict fixed-width integer usage (`uint32_t`)
- Safe argument parsing with overflow protection
- Clean separation between algorithm (`fastdiv.c`) and prime table (`primes.h`)

---

## Build Instructions

Ensure that the following files exist:

- `fastdiv.c` – contains the refactored implementation and `main()`
- `primes.h` – defines the prime table (`P[]`, `P_COUNT`)

Then compile:

```bash
cc -std=c11 -O2 -Wall -Wextra -o fastdiv fastdiv.c
```

---

### Basic execution

```
./fastdiv <number>
```

If no number is provided, the program defaults to:

```
21387312
```

### Example

```
$ ./fastdiv 100
Sum of proper divisors for (100): 117
```

---

## How It Works

The algorithm decomposes the input value into prime factors using the list in `primes.h`.
For each prime factor `p` whose exponent is `k`, it uses the closed-form divisor-sum formula:

```
1 + p + p^2 + ... + p^k
```

Multiplying this term over all prime factors yields the full divisor sum.
Subtracting `n` produces the **proper** divisor sum.
