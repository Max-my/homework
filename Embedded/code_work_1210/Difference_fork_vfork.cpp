#include <sys/types.h>
#include <unistd.h>
//#include <stdio.h>
#include <iostream>
#include <time.h>
#include <sys/wait.h>
#include <assert.h>
using namespace std;
int main(int argc, char **argv)
{
	assert(argc>1);
	pid_t pid;
	int a = 1;
	if(argv[1][0]=='f')
	{
		pid = fork();
		assert(pid >= 0);
		if(pid == 0)
		{
			a++;
			cout<<"I am the child process, ID is "<<getpid()<<endl;
			cout<<"a = "<<a<<endl<<endl;
		}
		else
		{
			a++;
			cout<<"I am the parent process, ID is "<<getpid()<<endl;
			cout<<"a = "<<a<<endl<<endl;
		}
	}
	else
	{
		pid = vfork();
		assert(pid >= 0);
		if(pid == 0)
		{
			a++;
			cout<<"I am the child process, ID is "<<getpid()<<endl;
			cout<<"a = "<<a<<endl<<endl;
			_exit(0);
		}
		else
		{
			a++;
			cout<<"I am the parent process, ID is "<<getpid()<<endl;
			cout<<"a = "<<a<<endl<<endl;
		}
	}
	return 0;
}
