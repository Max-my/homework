#include "bits/stdc++.h"
using namespace std;
const int N=1005;
int n,d;
struct moon
{
    double wei;
    double val;
    double price;
    bool friend operator <(moon a, moon b)
    {  
        return a.price-b.price>=0.0001;
    }
}cake[N];
int main()
{
    int t;
    scanf("%d %d",&n,&d);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&t);
        cake[i].wei=t;
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&t);
        cake[i].val=t;
        cake[i].price=t/cake[i].wei;
    }
    sort(cake, cake+n);
    double ans=0;
    int res=d;
    for(int i=0; i<n; i++)
    {
        if(cake[i].wei-res>=0.0001)
        {
            ans+=res*cake[i].price;
            break;
        }
        else
        {
            ans+=cake[i].wei*cake[i].price;
            res-=cake[i].wei;
        }
    }
    
    printf("%.2f",ans);
}