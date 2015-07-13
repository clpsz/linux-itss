#include <stdio.h>
#include <pthread.h>

void *thread0(void *dummy);
void *thread1(void *dummy);

pthread_spinlock_t slock;


int main()
{
    pthread_t tid0, tid1;


    // only accessable from this process
    pthread_spin_init(&slock, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&tid0, NULL, thread0, NULL);
    pthread_create(&tid1, NULL, thread1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    
    return 0;
}

