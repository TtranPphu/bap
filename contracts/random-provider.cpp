#include <random-provider.hpp>

using namespace eosio;

randomprovider::randomprovider(checksum256 random_seed) {
  raw_values = random_seed.extract_as_byte_array();
  offset = 0;
}

uint64_t randomprovider::get_uint64() {
  if (offset > 24) {
    regenerate_raw_values();
  }

  uint64_t value = 0;
  for (int i = 0; i < 8; i++) {
    value = (value << 8) + raw_values[offset];
    offset++;
  }
  return value;
}

uint32_t randomprovider::get_rand(uint32_t max_value) {
  return get_uint64() % ((uint64_t)max_value);
}

void randomprovider::regenerate_raw_values() {
  capi_checksum256* new_hash = new capi_checksum256();
  sha256((char*)raw_values.data(), 32, new_hash);
  std::copy(std::begin(new_hash->hash), std::end(new_hash->hash),
            std::begin(raw_values));
  offset = 0;
}