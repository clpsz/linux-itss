#include <stdio.h>
#include <pthread.h>


void *thread0(void *cmd);
void *thread1(void *cmd);

#if defined(USING_MUTEX)
pthread_mutex_t mutex;
#endif


int main(void)
{
    pthread_t tid0, tid1;
    int ret;

#if defined(USING_MUTEX)
    pthread_mutex_init(&mutex, NULL);
#endif

    ret = pthread_create(&tid0, NULL, thread0, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
    }
    ret = pthread_create(&tid1, NULL, thread1, NULL);
    if (ret != 0)
    {
        perror("pthread_create");
    }

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);

    return 0;
}

