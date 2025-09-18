#include "tiny_kv_store.hpp"
#include <string>

namespace tiny_kv {

template <typename Key, typename Value>
TinyKVStore<Key, Value>::TinyKVStore(TinyKVStore &&kv_store) {
    this->_map = std::move(kv_store._map);
}

template <typename Key, typename Value>
auto TinyKVStore<Key, Value>::operator=(TinyKVStore &&kv_store) -> TinyKVStore & {
    if (this != &kv_store) {
        this->_map = std::move(kv_store._map);
    }
    return *this;
}

template <typename Key, typename Value>
auto TinyKVStore<Key, Value>::Get(Key key) -> std::optional<Value> {\
    if (this->In(key))
        return this->_map[key];
    return std::nullopt;
}

template <typename Key, typename Value>
auto TinyKVStore<Key, Value>::Set(Key key, Value&& value) -> bool {
    if (this->In(key))
        return false;
    this->_map[key] = std::move(value); // use move semantics to avoid copy
    return true;
}

template <typename Key, typename Value>
auto TinyKVStore<Key, Value>::Delete(Key key) -> bool {
    if (!this->In(key))
        return false;
    auto itr = this->_map.find(key);
    this->_map.erase(itr);
    return true;
}


// need to explictly instantiation
// if the implementation of template class outside the header file
template class TinyKVStore<std::string, std::string>;

}; // tiny_kv
