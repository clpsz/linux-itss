#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_rwlock_t rwlock;


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
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        print0(100);
        pthread_rwlock_unlock(&rwlock);
    }

    return NULL;
}

