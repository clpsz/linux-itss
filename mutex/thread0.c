#include <stdio.h>
#include <unistd.h>
#include <pthread.h>



#if defined(USING_MUTEX)
extern pthread_mutex_t mutex;
#endif



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
#if defined(USING_MUTEX)
        pthread_mutex_lock(&mutex);
        print0(100);
        pthread_mutex_unlock(&mutex);
#else
        print0(100);
#endif
    }

    return NULL;
}

