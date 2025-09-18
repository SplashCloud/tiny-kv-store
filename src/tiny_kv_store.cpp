#include "tiny_kv_store.hpp"


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
auto TinyKVStore<Key, Value>::Get(Key key) -> Value {
    // TODO
}

template <typename Key, typename Value>
void TinyKVStore<Key, Value>::Set(Key key, Value value) {
    // TODO
}


}; // tiny_kv
