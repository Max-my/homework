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
