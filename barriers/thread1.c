#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


extern pthread_barrier_t barrier;

void print1(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "1");
    }
    fprintf(stderr, "\n");
}

void *thread1(void *cmd)
{
    print1(100);
    fprintf(stderr, "waiting for barrier in thread1\n");

    sleep(1);
    pthread_barrier_wait(&barrier);

    return NULL;
}

