#include <iostream>
#include "tiny_kv_store.hpp"

int main () {
    std::cout << "TinyKVStore" << std::endl;
    tiny_kv::TinyKVStore<int, int> kv_store;
}