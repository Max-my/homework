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
