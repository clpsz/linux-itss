#include <stdio.h>
#include <pthread.h>

void *thread0(void *dummy);
void *thread1(void *dummy);


pthread_cond_t con_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


int main()
{
    pthread_t tid0, tid1;

    pthread_create(&tid0, NULL, thread0, NULL);
    pthread_create(&tid1, NULL, thread1, NULL);

    pthread_join(tid0, NULL);
    pthread_join(tid1, NULL);
    
    return 0;
}
