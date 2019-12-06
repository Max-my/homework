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
