#include <unordered_map>


#ifndef TINY_KV_STORE_H
#define TINY_KV_STORE_H

namespace tiny_kv {

template <typename Key, typename Value>
class TinyKVStore {

  public:

    TinyKVStore() = default;
    ~TinyKVStore() = default;

    TinyKVStore(TinyKVStore &&kv_store); // move constructor
    auto operator=(TinyKVStore &&kv_store) -> TinyKVStore &; // move assignment operator

    TinyKVStore(TinyKVStore &kv_store) = delete; // no copy constructor
    auto operator=(TinyKVStore &kv_store) -> TinyKVStore & = delete; // no copy assignment operator
    
    // common api
    auto Get(Key key) -> Value;
    void Set(Key key, Value value);
    inline auto Size() -> size_t {
        return this->_map.size();
    }

  private:

    std::unordered_map<Key, Value> _map;
};

}; // tiny_kv

#endif