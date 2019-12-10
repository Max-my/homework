#include <sys/types.h>
#include <unistd.h>
//#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/wait.h>
#include <assert.h>
using namespace std;
int main()
{
	pid_t pid,pr;
	pid = vfork();
	assert(pid >= 0);
	if(pid == 0)
	{
		cout<<"I am the child process, ID is "<<getpid()<<endl;
		time_t lt = time(NULL);
		cout<<"The local time is: "<<ctime(&lt)<<endl;
		sleep(3);
		exit(0);
	}
	else
	{
		//pr = wait(NULL);
		cout<<"I am the parent process, ID is "<<getpid()<<endl;
		time_t lt = time(NULL);
		cout<<"The local time is: "<<ctime(&lt)<<endl;
	}
	return 0;
}
