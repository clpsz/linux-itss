#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


extern pthread_barrier_t barrier;

void print0(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "0");
    }
    fprintf(stderr, "\n");
}

void *thread0(void *cmd)
{
    print0(100);
    fprintf(stderr, "waiting for barrier in thread0\n");

    sleep(1);
    pthread_barrier_wait(&barrier);

    return NULL;
}

