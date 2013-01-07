///
/// @file  EratBig.h
///
/// Copyright (C) 2013 Kim Walisch, <kim.walisch@gmail.com>
///
/// This file is distributed under the New BSD License. See the
/// LICENSE file in the top level directory.
///

#ifndef ERATBIG_H
#define ERATBIG_H

#include "config.h"
#include "WheelFactorization.h"

#include <stdint.h>
#include <vector>
#include <list>

namespace soe {

/// EratBig is an implementation of the segmented sieve of
/// Eratosthenes optimized for big sieving primes that have very few
/// multiples per segment.
///
class EratBig: public Modulo210Wheel_t {
public:
  EratBig(uint64_t, uint_t, uint_t);
  ~EratBig();
  void crossOff(uint8_t*);
private:
  typedef std::list<Bucket*>::iterator PointerIterator_t;
  enum {
    BUCKETS_PER_ALLOC = config::MEMORY_PER_ALLOC / sizeof(Bucket)
  };
  const uint_t limit_;
  /// log2 of SieveOfEratosthenes::sieveSize_
  const uint_t log2SieveSize_;
  const uint_t moduloSieveSize_;
  /// Vector of bucket lists, holds the sieving primes
  std::vector<Bucket*> lists_;
  /// List of empty buckets
  Bucket* stock_;
  /// Pointers of the allocated buckets
  std::list<Bucket*> pointers_;
  void setListsSize(uint_t);
  void init();
  static void moveBucket(Bucket&, Bucket*&);
  void pushBucket(Bucket*&);
  void store(uint_t, uint_t, uint_t);
  void crossOff(uint8_t*, Bucket&);
  Bucket*& getList(uint_t*);
  DISALLOW_COPY_AND_ASSIGN(EratBig);
};

} // namespace soe

#endif
