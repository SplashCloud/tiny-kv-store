# Implementation of Tiny KV Store

## Version-1

### 设计

- 模板类支持不同类型的Key和Value
- API
    - Get、Set、Delete
    - 持久化：Load、Save（序列化/反序列化）
- 线程安全
    - 支持多线程操作同一个KV Store

### 问题

- Key和Value不同的类型对API的设计和实现是否会存在不同的考量？
- 在实现KV Store的时候，需要注意什么？
- 如何实现持久化？如果Value是一个复合类型的话，以什么样的格式存储？
- 如何实现线程安全？如何测试多线程操作？
