#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#define MAX_SIZE 20
using namespace std;
int main(){
    int fd1[2],fd2[2];
    int res = pipe(fd1);
    assert(res >= 0);
    res = pipe(fd2);
    assert(res >= 0);
    pid_t pid;
    pid = fork();
    if(pid == 0){
        char sendc[MAX_SIZE], sendp[MAX_SIZE];
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], sendp, MAX_SIZE);
        cout<<"Child reads: "<<sendp<<endl;
        cout<<"Child writes:> ";
        cin>>sendc;
        write(fd2[1], sendc, strlen(sendc)+1);
        close(fd1[0]);
        close(fd2[1]);
    }
    else if (pid > 0){
        char sendc[MAX_SIZE], sendp[MAX_SIZE];
        close(fd1[0]);
        close(fd2[1]);
        cout<<"Parent writes:> ";
        cin>>sendp;
        write(fd1[1], sendp, strlen(sendp)+1);
        read(fd2[0], sendc, MAX_SIZE);
        cout<<"Parent reads: "<<sendc<<endl;
        close(fd1[1]);
        close(fd2[0]);
    }
    return 0;
}