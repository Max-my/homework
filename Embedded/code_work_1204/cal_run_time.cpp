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
