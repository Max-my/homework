#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
void *create(char *quit)
{
    printf("new thread is created...\n");
    if(quit[0] == 'r'){//return 
        return (void *)8;
    }
    else if(quit[0] == 'p'){//pthread_exit
        pthread_exit((void *)5);
    }
    else if(quit[0] == 'e'){//exit
        exit(0);
    }
}
int main(int argc, char **argv)
{
    if(argc<2)
    {
        perror("The format error!\n");
        return 1;
    }
    pthread_t tid;
    void *temp;
    if(pthread_create(&tid, NULL, (void *)create, argv[1]) != 0)
    {
        perror("thread is not created!\n");
        return -1;
    }
    if(pthread_join(tid, &temp) != 0)
    {
        perror("thread is not exit!\n");
        return -2;
    }
    printf("thread is exit code %d \n", (int)temp);
    return 0;
}