#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void my_signal(int sign_no){
    if(sign_no == SIGSTOP){
        printf("\nI have get SIGSTOP\n");
    }
}
int main(){
    printf("Waiting for signal SIGSTOP\n");
    signal(SIGSTOP, my_signal);
    pause();
    exit(0);
}