#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_cond_t con_var;
extern pthread_mutex_t lock;


void *thread0(void *dummy)
{
    pthread_mutex_lock(&lock);
    pthread_cond_wait(&con_var, &lock);
    pthread_mutex_unlock(&lock);

    printf("thread1 waken up\n");

    return NULL;
}

