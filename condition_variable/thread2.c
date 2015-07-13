#include "debug.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_cond_t con_var;
pthread_mutex_t lock;


void *thread2(void *dummy)
{
    int code;

    usleep(1000); // 1ms
    pthread_mutex_lock(&lock);
    code = pthread_cond_signal(&con_var);
    if (code)
    {
        perror("signal");
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

