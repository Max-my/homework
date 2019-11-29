#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
  float score[20];
  int A,B,C;
  A=B=C=0;
  cout<<"请输入20个学生的成绩："<<endl;
  int i=0;
  for(i=0; i<20; i++)
  {
    cin >> score[i];
    if(score[i]>100.0001 || score[i]<0)
    {
      cout<<"第"<<i+1<<"个数据输入错误，请重新输入！"<<endl;
      i--;
    }
    else if(score[i]>=80)
      A++;
    else if(score[i]>=60)
      B++;
    else
      C++;
  }
  cout<<"A:"<<A<<endl<<"B:"<<B<<endl<<"C:"<<C<<endl;
  return 0;
}
