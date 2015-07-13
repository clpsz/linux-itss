#使用方法
```
cd mutex/
make
./_main
make good
./_main
```
对比可以发现，不使用mutex同步的话，两个线程的打印会交叉

#补充
##另外一个加锁操作函数：
```
pthread_mutex_trylock(pthread_mutex_t *)
```
这个函数在加锁失败时不会会让线程进入睡眠状态，它直接失败返回，所以需要自己判断返回值。
##还有一个加锁函数：
```
pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,
                        const struct timespec *restrict tsptr);
```
使用这个函数可以指定一个超时时间，在这个超时时间到来之前如果没有获得锁，则失败返回，不会一直阻塞。

#总结
mutex是最用的线程间同步方式，主要保护不同的线程之间不会同时操作同一数据结构
