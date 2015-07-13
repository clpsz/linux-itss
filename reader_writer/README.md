#使用方法
```
$cd reader_writer
$make
$./_main
```
#补充
##另外一组加锁函数：
```
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
```
和其它的trylock一样，这个函数在无法获取到锁时直接失败返回，而不会阻塞。
##另外一组加锁函数：
```
int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock,
                               const struct timespec *restrict tsptr);
int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock,
                               const struct timespec *restrict tsptr);
```
这组函数在给定时间内无法获取到锁的话，会失败返回。
##释放资源
```
用pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
```
如果在初始化读写的时候，分配了其它资源，需要使来上面这个函数释放掉这些资源。这个函数执行之后，读写变成了未初始化的状态，对未初始化状态的读写锁执行操作的结果是未定义的。如果需要再次使用它的话，可以再次执行初始化函数来初始化。

#总结
读写锁用于对于同一组资源既有读，也有写的行为，且读操作的频率远大于写的情况。在持有读锁的情况下，其它线程也可以获取到读锁，但是不能获取到写锁，在持有写锁的情况下，其它线程无法获取到任一种锁。

一般的实现会做这样的处理，在读锁被持有的情况下，如果有写锁的请求，会阴塞掉后面的读锁请求，以防止在读频率太高的情况下写线程被“饿死”；
