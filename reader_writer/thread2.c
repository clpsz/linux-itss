#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


extern pthread_rwlock_t rwlock;


void print2(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "2");
    }
    fprintf(stderr, "\n");
}

void *thread2(void *cmd)
{
    while(1)
    {
        pthread_rwlock_wrlock(&rwlock);
        print2(100);
        pthread_rwlock_unlock(&rwlock);
    }

    return NULL;
}

