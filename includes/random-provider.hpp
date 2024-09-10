#pragma once

#include <eosio/system.hpp>

#include "../capi/eosio/crypto.h"

class randomprovider {
 public:
  randomprovider(eosio::checksum256 random_seed);

  uint64_t get_uint64();

  uint32_t get_rand(uint32_t max_value);

 private:
  void regenerate_raw_values();

  std::array<uint8_t, 32> raw_values;
  int offset;
};