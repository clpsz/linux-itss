#include <stdio.h>
#include <pthread.h>

void *thread0(void *dummy);
void *thread1(void *dummy);

pthread_barrier_t barrier;


int main()
{
    pthread_t tid0, tid1;

    // only accessable from this process
    pthread_barrier_init(&barrier, NULL, 3);

    pthread_create(&tid0, NULL, thread0, NULL);
    pthread_create(&tid1, NULL, thread1, NULL);

    fprintf(stderr, "waiting for barrier in main\n");
    pthread_barrier_wait(&barrier);




    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    
    return 0;
}

