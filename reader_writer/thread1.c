#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


extern pthread_rwlock_t rwlock;


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
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        print1(100);
        pthread_rwlock_unlock(&rwlock);
    }

    return NULL;
}

