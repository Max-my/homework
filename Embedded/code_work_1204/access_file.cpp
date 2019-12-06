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
