#include<stdio.h>
#include<iostream>
#define MAXSIZE 100
using namespace std;

int main()
{
  int nums[MAXSIZE+5];
  int i=0;
  cout<<"请输入待排序序列，以空格隔开，回车结束！"<<endl;
  for(i=0; i<MAXSIZE+5; i++)
  {
    if(i>=MAXSIZE)
    {
      cout<<"输入序列数量超出最大值，第"<<MAXSIZE<<"个数据后的序列将被舍去"<<endl;
      break;
    }
    cin>>nums[i];
    if(getchar()=='\n')
      break;
  }
  int len=i+1;
  int flag=1;
  while(flag)
  {
    flag=0;
    for(int j=0; j<len-1; j++)
    {
      if(nums[j]>nums[j+1])
      {
        flag=1;
        int temp=nums[j];
        nums[j]=nums[j+1];
        nums[j+1]=temp;
      }
    }
    len--;
  }
  for(int k=0; k<=i; k++)
  {
    cout<<nums[k]<<" ";
  }
  cout<<endl;
  return 0;
}
