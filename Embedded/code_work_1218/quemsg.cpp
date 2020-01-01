#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>
#define MAX_TEXT 512
struct msg_st{
    long int msg_type;
    char text[BUFSIZ];
};
int main(){
    msg_st data, data1;
    char buf[BUFSIZ];
    int msgid = -1;
    long int msgtype = 0;
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if(msgid == -1){
        fprintf(stderr, "Msgget failed with error:%d\n", errno);
        exit(EXIT_FAILURE);
    }
    pid_t pid, pr;
    pid = fork();
    if(pid < 0){
        printf("Error in fork!\n");
        return 0;
    }
    else if(pid == 0){
        printf("Enter some text:");
        fgets(buf, BUFSIZ, stdin);
        data.msg_type = 1;
        strcpy(data.text, buf);
        if(msgsnd(msgid, (void*)&data, MAX_TEXT, 0) == -1){
            fprintf(stderr, "Msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        time_t lt = time(NULL);
        printf("The local time is: %s", ctime(&lt), "\n");
        sleep(3);
    }
    else{
        pr = wait(NULL);
        if(msgrcv(msgid, (void*)&data1, BUFSIZ, msgtype, 0) == -1){
            fprintf(stderr, "Msgrcv failed with error: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("\nYou wrote: %s", data1.text);
        time_t lt = time(NULL);
        printf("The local time is: %s", ctime(&lt), "\n");
    }
}

