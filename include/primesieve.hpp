///
/// @file   primesieve.hpp
/// @brief  primesieve C++ API. primesieve is a library for fast
///         prime number generation, in case an error occurs a
///         primesieve::primesieve_error exception (derived form
///         std::runtime_error) is thrown.
///
/// Copyright (C) 2024 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the BSD License.
///

#ifndef PRIMESIEVE_HPP
#define PRIMESIEVE_HPP

#define PRIMESIEVE_VERSION "12.4"
#define PRIMESIEVE_VERSION_MAJOR 12
#define PRIMESIEVE_VERSION_MINOR 4

#include <primesieve/iterator.hpp>
#include <primesieve/primesieve_error.hpp>
#include <primesieve/StorePrimes.hpp>

#include <stdint.h>
#include <string>
#include <bigint.h>

namespace primesieve {

/// Appends the primes <= stop to the end of the primes vector.
/// @vect: std::vector or other vector type that is API compatible
///        with std::vector.
///
template <typename T, typename vect>
inline void generate_primes(T stop, vect* primes)
{
  if (primes)
    store_primes(0, stop, *primes);
}

/// Appends the primes inside [start, stop] to the end of the primes vector.
/// @vect: std::vector or other vector type that is API compatible
///        with std::vector.
///
template <typename T, typename vect>
inline void generate_primes(T start, T stop, vect* primes)
{
  if (primes)
    store_primes(start, stop, *primes);
}

/// Appends the first n primes to the end of the primes vector.
/// @vect: std::vector or other vector type that is API compatible
///        with std::vector.
///
template <typename T, typename vect>
inline void generate_n_primes(T n, vect* primes)
{
  if (primes)
    store_n_primes(n, 0, *primes);
}

/// Appends the first n primes >= start to the end of the primes vector.
/// @vect: std::vector or other vector type that is API compatible
///        with std::vector.
///
template <typename T, typename vect>
inline void generate_n_primes(T n, T start, vect* primes)
{
  if (primes)
    store_n_primes(n, start, *primes);
}

/// Find the nth prime.
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
/// Note that each call to nth_prime(n, start) incurs an
/// initialization overhead of O(sqrt(start)) even if n is tiny.
/// Hence it is not a good idea to use nth_prime() repeatedly in a
/// loop to get the next (or previous) prime. For this use case it
/// is better to use a primesieve::iterator which needs to be
/// initialized only once.
///
/// @param n  if n = 0 finds the 1st prime >= start, <br/>
///           if n > 0 finds the nth prime > start, <br/>
///           if n < 0 finds the nth prime < start (backwards).
///
template <typename T>
T nth_prime(T n, T start = 0);

/// Count the primes within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
/// Note that each call to count_primes() incurs an initialization
/// overhead of O(sqrt(stop)) even if the interval [start, stop]
/// is tiny. Hence if you have written an algorithm that makes
/// many calls to count_primes() it may be preferable to use
/// a primesieve::iterator which needs to be initialized only once.
///
template <typename T>
T count_primes(uint64_t start, uint64_t stop);

/// Count the twin primes within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
template <typename T>
T count_twins(T start, uint64_t stop);

/// Count the prime triplets within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
template <typename T>
T count_triplets(T start, T stop);

/// Count the prime quadruplets within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
template <typename T>
T count_quadruplets(T start, T stop);

/// Count the prime quintuplets within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///\ntemplate <typename T>template <typename T>
template <typename T>
T count_quintuplets(T start, T stop);

/// Count the prime sextuplets within the interval [start, stop].
/// By default all CPU cores are used, use
/// primesieve::set_num_threads(int threads) to change the
/// number of threads.
///
template <typename T>
T count_sextuplets(T start, T stop);

/// Print the primes within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_primes(T start, T stop);

/// Print the twin primes within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_twins(T start, T stop);

/// Print the prime triplets within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_triplets(T start, T stop);

/// Print the prime quadruplets within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_quadruplets(T start, T stop);

/// Print the prime quintuplets within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_quintuplets(T start, T stop);

/// Print the prime sextuplets within the interval [start, stop]
/// to the standard output.
///
template <typename T>
void print_sextuplets(T start, T stop);

/// Returns the largest valid stop number for primesieve.
/// @return 2^64-1 (UINT64_MAX).
///
template <typename T>
T get_max_stop();

/// Get the current set sieve size in KiB.
int get_sieve_size();

/// Get the current set number of threads.
int get_num_threads();

/// Set the sieve size in KiB (kibibyte).
/// The best sieving performance is achieved with a sieve size
/// of your CPU's L1 or L2 cache size (per core).
/// @pre sieve_size >= 16 && <= 8192.
///
void set_sieve_size(int sieve_size);

/// Set the number of threads for use in
/// primesieve::count_*() and primesieve::nth_prime().
/// By default all CPU cores are used.
///
void set_num_threads(int num_threads);

/// Get the primesieve version number, in the form “i.j”.
std::string primesieve_version();

}

#endif
