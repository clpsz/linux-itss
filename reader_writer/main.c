#include <stdio.h>
#include <pthread.h>

void *thread0(void *dummy);
void *thread1(void *dummy);
void *thread2(void *dummy);

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;


int main()
{
    pthread_t tid0, tid1, tid2;

    pthread_create(&tid0, NULL, thread0, NULL);
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    return 0;
}
