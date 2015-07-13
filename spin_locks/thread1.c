#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


extern pthread_spinlock_t slock;

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
        pthread_spin_lock(&slock);
        print1(100);
        pthread_spin_unlock(&slock);
        usleep(1);
    }

    return NULL;
}

