#使用方法
```
cd mutex/
make
./_main
make good
./_main

```

对比可以发现，不使用mutex同步的话，两个线程的打印会交叉
--

#总结
mutex是最用的线程间同步方式，主要保护不同的线程之间不会同时操作同一数据结构
