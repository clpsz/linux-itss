#include "debug.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_cond_t con_var;
pthread_mutex_t lock;


void *thread1(void *dummy)
{
    pthread_mutex_lock(&lock);
    pthread_cond_wait(&con_var, &lock);

    printf("thread1 waken up\n");

    return NULL;
}

