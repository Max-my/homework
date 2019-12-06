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
