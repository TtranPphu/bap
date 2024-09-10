#include <atomicassets-interface.hpp>
#include <eosio/action.hpp>
#include <eosio/asset.hpp>
#include <eosio/binary_extension.hpp>
#include <eosio/eosio.hpp>
#include <eosio/system.hpp>
#include <pet.hpp>

using namespace std;
using namespace eosio;
using namespace atomicassets;

CONTRACT bap : public contract {
 public:
  using contract::contract;
};