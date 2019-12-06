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
