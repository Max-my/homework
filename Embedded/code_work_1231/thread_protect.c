#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *cleanup(char *arg)
{
    printf("clean the str: %s\n", arg);
    free(arg);
}
void *thread(char *arg)
{
    pthread_cleanup_push((void *)cleanup, arg);
    printf("thread is running...\n");
    pthread_exit((void *)1);
    pthread_cleanup_pop(1);
}
int main()
{
    char *str;
    str = malloc(20*sizeof(char));
    str[0] = 't';
    str[1] = 'e';
    str[2] = 's';
    str[3] = 't';
    str[4] = '\0';
    printf("Main thread get str: %s\n", str);
    pthread_t tid;
    if(pthread_create(&tid, NULL, (void *)thread, str) != 0)
    {
        perror("thread is not created!\n");
        return -1;
    }
    if(pthread_join(tid, NULL) != 0)
    {
        perror("thread is not exit!\n");
        return -2;
    }
    if(*str == NULL)
        printf("clean up success\n");
    return 0;
}