#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_cond_t con_var;
extern pthread_mutex_t lock;


void *thread1(void *dummy)
{
    int code;

    sleep(2); // weait 2s to test
    pthread_mutex_lock(&lock);
    code = pthread_cond_signal(&con_var);
    if (code)
    {
        perror("signal");
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

