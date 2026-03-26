#include <algorithm>
#include <cmath>
#include <cstdio>
#include<stdio.h>
#include <cstring>
#include <iostream>
#include <string>
#include <random>
#define ll long long
#define mod 998244353
#define maxn 200005
#include<queue>
#include<vector>
#include<stack>
typedef long long LL;
using namespace std;
int n,m;
priority_queue<int>q[300005];
int a[300005];
int c[35];
struct sss
{
    int x;
    int y;
}b[300005];
queue<int>v;

bool cmp(sss a,sss b)
{
    if(a.x!=b.x)
    return a.x<b.x;
    return a.y<b.y;
}
signed main()
{
    int i,j,k,t,u,cnt1,cnt2,cnt3,ans,res;
    int x,y,xx,yy;
    cin>>n;
  for(i=0;i<n;i++)
    cin>>b[i].x>>b[i].y;
  sort(b,b+n,cmp);
  x=(b[0].x+b[n-1].x);
  y=(b[0].y+b[n-1].y);
  for(i=1;i<=n/2;i++)
    {
        xx=(b[i].x+b[n-1-i].x);
        yy=(b[i].y+b[n-1-i].y);

        if(xx!=x||y!=yy) {cout<<"no\n";return 0;}
    }
    cout<<"yes\n";

}

//  7 6 5 6 5 2 1 1

	 			  	  	 		 		 							  				