#使用方法
```
$cd condition_variable
$make
$./_main
```
可以看到在thread1唤醒thread0后，thread0才继承执行并打印出消息

#补充
##等待条件变量函数有另外一个版本:
```
int pthread_cond_timedwait(pthread_cond_t *restrict cond,
                       pthread_mutex_t *restrict mutex,
                       const struct timespec *restrict tsptr);
```
这个函数可以指定一个超时时间，在超时时间到达之后失败返回
##发送信息的变量也有另外一个版本：
```
int pthread_cond_broadcast(pthread_cond_t * cond);
```
如果有多个线程在等待一个条件变量的话，pthread_cond_signal只会唤醒其中的一个线程，而pthread_cond_broadcast会唤醒所有正在等待的线程。
##释放资源
```
int pthread_cond_destroy(pthread_cond_t *cond);
```
如果在初始化条件变量的时候，分配了其它资源，需要使用上面这个函数来释放掉这些资源。这个函数执行之后，条件变量变成了未初始化的状态，对未初始化状态的条件变量操作的结果是未定义的。如果需要再次使用这个条件变量的话，可以再次执行初始化函数来初始化这个条件变量。

#总结
条件变量可以看作是线程间的信号，让一个线程等待另外一个线程发送信号，收到信号后才继续执行。条件变量可能是除mutex之外，第二常用的线程间同步方式。
