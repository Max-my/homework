// 判断一个文件是否存在
#include "code_work.h"
int main(int argc, char **argv)
{
	assert(argc>1);
	if(access(argv[1], F_OK)==0)
		cout<<"This file is exit!\n";
	else
		cout<<"This file isn't exit!\n";
	return 0;
}
// 计算循环代码运行时间
#include "code_work.h"
using namespace std;
int main()
{
	int n;
	cout<<"input loop times:"<<endl;
	cin>>n;
	struct timeval tv;
	assert(gettimeofday(&tv,NULL)==false);
	long sec = tv.tv_sec;
	long usec = tv.tv_usec;
	for(int i=0; i<n; i++)
		for(int j=0; j<5000; j++);
	assert(gettimeofday(&tv,NULL)==false);
	sec = tv.tv_sec - sec;
	usec = tv.tv_usec - usec;
	cout<<"The total time is: "<<sec+usec*1e-6<<"s"<<endl;
	return 0;	
}
// 文件流操作写字符
#include "code_work.h"
int main(int argc, char **argv)
{
	assert(argc>1);
	FILE *fp = fopen(argv[1], "w");
	assert(fp!=NULL);
	char ch;
	ch = getchar();
	while(ch!='\n')
	{
		assert(fputc(ch,fp)!=-1);
		ch = getchar();
	}
	cout<<"Write file finish!"<<endl;
	return 0;
}
// 创建文件并设置新文件权限
#include "code_work.h"
void CreateFile(char *filename, char *mask)
{
    umask(0000);
    int a=mask[0]-'0';
    int b=mask[1]-'0';
    int c=mask[2]-'0';
    assert(creat(filename,a*64+b*8+c)!=-1);
    cout<<"Create file "<<filename<<" success!"<<endl;
}
int main(int argc, char *argv[])
{
	assert(argc>2);
	CreateFile(argv[1],argv[2]);
	return 0;
}
// 从文件读取20个字符
#include "code_work.h"
int main(int argc, char **argv)
{
	assert(argc>1);
	int fd = open(argv[1],O_RDONLY);
	assert(fd!=-1);
	char buf[20];
	int rd = read(fd, buf, 20);
	assert(rd!=-1);
	for(int i=0; i<20; i++)
		cout<<buf[i];
	cout<<endl;
	close(fd);
	return 0;
}
// 文件流读文件内容并打印
#include "code_work.h"
int main(int argc, char **argv)
{
	assert(argc>1);
	FILE *fp = fopen(argv[1], "r");
	assert(fp!=NULL);
	char ch = fgetc(fp);
	while(ch!=EOF)
	{
		putchar(ch);
		ch = fgetc(fp);
	}
	fclose(fp);
	return 0;
}
// 以字符串形式显示本地时间
#include "code_work.h"
using namespace std;
int main()
{
	time_t t = time(NULL);
	struct tm *local = localtime(&t);
	cout<<"The local time is: "<<asctime(local)<<endl;
	return 0;
}
// 创建一个文件并打开写入"Hello, welcome to Beijing!"
#include "code_work.h"
int main(int argc, char **argv)
{
	int fd = open(argv[1],O_RDWR);
	assert(fd!=-1);
	char str[]="Hello, welcome to Beijing!\n";
    assert(write(fd, str, sizeof(str)-1) != -1);
	cout<<"Write success!"<<endl;
	close(fd);	
	return 0;
}
// 整合头文件
#ifndef CODE_WORK_H
#define CODE_WORK_H

#include <iostream>
using namespace std;
#include <stdio.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <assert.h>

#endif
