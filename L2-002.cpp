#include "bits/stdc++.h"
using namespace std;
#define list lis
const int N=1e5+3;
struct node
{
    int value;
    int next;    
}list[N];
bool vis[N];
int ans[N],del[N],k1,k2;
int main()
{
    int head,n;
    scanf("%d %d",&head, &n);
    while(n--)
    {
        int id;
        scanf("%d",&id);
        scanf("%d %d",&list[id].value, &list[id].next);
    }
    int p=head;
    while(p!=-1)
    {
        int m=abs(list[p].value);
        if(vis[m]==0)
        {
            ans[k1++]=p;
            vis[m]=1;
        }
        else
        {
            del[k2++]=p;
        }
        p=list[p].next;        
    }
    for(int i=0; i<k1-1; i++)
    {
        printf("%05d %d %05d\n",ans[i],list[ans[i]].value, list[ans[i]].next);
    }
    printf("%05d %d -1\n",ans[k1-1],list[ans[k1-1]].value);
    if(k2>0)
    {
        for(int i=0; i<k2-1; i++)
        {
            printf("%05d %d %05d\n",del[i],list[del[i]].value, list[del[i]].next);
        }
        printf("%05d %d -1\n",del[k1-1],list[del[k1-1]].value);
    }

    return 0;
}