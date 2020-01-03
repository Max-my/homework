#include <stdio.h>
#include <pthread.h>
struct myArg{
    int num;
    char *str;
};
void *myThread(struct myArg *arg)
{
    printf("The thread receive num: %d and str: %s\n",arg->num,arg->str);
}
int main(int argc, char ** argv)
{
    if(argc<3)
    {
        perror("The format error!\n");
        return 1;
    }
    struct myArg myarg;
    myarg.num = (int)(argv[1][0]-'0');
    myarg.str = argv[2];
    pthread_t id;
    if(pthread_create(&id, NULL, (void *)myThread, &myarg) != 0)
    {
        perror("Create thread error!\n");
        return 1;
    }
    pthread_join(id, NULL);
    return 0;
}