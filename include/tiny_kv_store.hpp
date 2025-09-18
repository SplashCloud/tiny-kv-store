#include <optional>
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
    auto Get(Key key) -> std::optional<Value>; // using the std::optinal to unified manage 'value' and 'no value'
    auto Set(Key key, Value&& value) -> bool;
    auto Delete(Key key) -> bool;

    inline auto Size() -> size_t {
        return this->_map.size();
    }

  protected:

    inline auto In(Key key) -> bool {
        return this->_map.find(key) != this->_map.end();
    }

  private:

    std::unordered_map<Key, Value> _map;
};

}; // tiny_kv

#endif