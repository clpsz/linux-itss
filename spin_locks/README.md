#使用方法
```
$cd spin_locks
$make
$./_main
```

#补充
##另外一个加锁函数：
```
pthread_spin_trylock(pthread_spinlock_t *lcok);
```
和其它的trylock一样，这个函数在无法获取到锁时直接失败返回，而不会spin
##释放资源
如果在初始化自旋锁的时候，分配了其它资源，需要使用pthread_spin_destroy(pthread_spinlock_t *lock)来释放掉这些资源。

#总结
spin lock在无法获取到锁的时候不会进入睡眠，而是忙等待，直到获取到锁为止。所以一般只用在需要等待很短时间，又不能忍受被重新调试的开销的场合。

在用户空间中，spin锁的用途有限。但是在非实时多任务系统中，在时间片用完之后，即使是忙等待也会被重新调度，所以作用不大。可能在实时且不支持抢占的操作系统上还有点用。
