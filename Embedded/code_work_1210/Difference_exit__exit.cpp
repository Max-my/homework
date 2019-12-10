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
	pid_t pid;
	pid = fork();
	assert(pid >= 0);
	if(pid == 0)
	{
		cout<<endl<<"This is _exit test :"<<endl;
		cout<<"This is the content in the buffer000";
		_exit(0);
	}
	else
	{
		cout<<endl<<"This is exit test :"<<endl;
		cout<<"This is the content in the buffer";
		exit(0);
	}
	return 0;
}
