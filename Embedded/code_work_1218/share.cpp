#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main(int argc, char** argv){
    int shmid;
    char *p_addr, *c_addr;
    if(argc != 2){
        fprintf(stderr, "Usage:%s\n\a", argv[0]);
        exit(1);
    }
    key_t key = ftok("a", 66);
    if((shmid = shmget(key, 1024, IPC_CREAT | 0600)) == -1){
        fprintf(stderr, "Create share memory error:%s\n\a", strerror(errno));
        exit(1);
    }
    if(fork()){
        p_addr = (char *)shmat(shmid, 0, 0);
        memset(p_addr, '\0', 1024);
        strncpy(p_addr, argv[1], 1024);
        printf("Writes:%s\n", p_addr);
        wait(NULL);
        exit(0);
    }
    else{
        sleep(1);
        c_addr = (char *)shmat(shmid, 0, 0);
        printf("Reads:%s\n", c_addr);
        exit(0);
    }
    return 0;
}
