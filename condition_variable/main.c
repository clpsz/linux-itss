#include <stdio.h>
#include <pthread.h>

void *thread1(void *dummy);
void *thread2(void *dummy);


pthread_cond_t con_var = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;


int main()
{
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    return 0;
}
