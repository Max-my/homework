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
