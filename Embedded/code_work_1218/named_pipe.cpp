#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <assert.h>
#define FIFO "myfifo"
using namespace std;
int main(int argc, char** argv){
    pid_t pid, pr;
    pid = fork();
    assert(pid >= 0);
    if(pid == 0){
        int fd, nwrite;
        char w_buf[100];
        fd = open(FIFO, O_WRONLY | O_NONBLOCK, 0);
        assert(argc > 1);
        strcpy(w_buf, argv[1]);
        if((nwrite = write(fd, w_buf, 100)) == -1){
            if(errno == EAGAIN)
                cout<<"The FIFO has not been read yet. Please try later!"<<endl;
        }
        else
            cout<<"Write "<<w_buf<<" to the FIFO"<<endl;
    }
    else{
        pr = wait(NULL);
        char r_buf[100];
        int fd, nread;
        if((mkfifo(FIFO, O_CREAT | O_EXCL) < 0) && (errno != EEXIST))
            cout<<"Can't create fifoserver!"<<endl;
        memset(r_buf, 0, sizeof(r_buf));
        fd = open(FIFO, O_RDONLY | O_NONBLOCK, 0);
        if(fd == -1){
            perror("open");
            exit(1);
        }
        memset(r_buf, 0, sizeof(r_buf));
        if((nread = read(fd, r_buf, 100)) == -1){
            if(errno == EAGAIN)
                cout<<"No data yet!"<<endl;
        }
        cout<<"Read "<<r_buf<<" from FIFO"<<endl;
        unlink(FIFO);
    }
    return 0;
}