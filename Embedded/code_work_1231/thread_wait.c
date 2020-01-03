#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void *thread()
{
    time_t lt = time(NULL);
    printf("thread is created on : %s", ctime(&lt));
    printf("thread is running...\n");
    sleep(3);
    return (void *)1;
}
int main()
{
    pthread_t tid;
    if(pthread_create(&tid, NULL, (void *)thread, NULL) != 0)
    {
        perror("thread is not created!\n");
        return -1;
    }
    if(pthread_join(tid, NULL) != 0)
    {
        perror("thread is not exit!\n");
        return -2;
    }
    time_t lt = time(NULL);
    printf("thread exits on : %s", ctime(&lt));
    return 0;
}