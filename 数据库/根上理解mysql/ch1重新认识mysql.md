## 客户端服务器架构

mysql的服务端是什么

- 工作：与数据打交道，但可能不是直接和数据，因为还有存储引擎帮忙做这个事
- 服务端名称 mysqld 

客户端是什么？

- 工作
- 客户端名称 mysql

数据库

实例是什么？



如何启动mysql

- mysqld
- `mysqld_safe`
- `mysql.server start`--间接调用`mysqld_safe`

- `mysqld_multi`





## 连接过程

### tcp/ip

默认端口3306



### 命名管道和共享内存



### unix域套接字文件



## 服务器处理客户端请求

本质上是客户端给服务器发送一个文本（命令）

然后服务器返回数据

自己画下架构图？

### 连接管理

- 通过上面三种方法连接
- 线程怎么分配
  - 连接线程只有一个不销毁
  - 每个客户端分配一个处理线程
- 网络中如何保证安全

### 查询缓存



### 解析与优化

查询缓存没有命中（实际现在也没有了）

这时我们需要认识客户端的文本（指令）



- 语法分析

- 查询优化
  - 能查看如何优化的吗？explain命令



### 存储引擎

存储引擎是什么？

功能是啥？

本质是什么？



## 常见存储引擎







