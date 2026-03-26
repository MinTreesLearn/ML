#include<iostream>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
#include<map>
#include<cmath>
#include<cstdio>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
const int inf=0x3f3f3f3f,hamod=1e9+7,HAmod=1e9+9,mod=200907,N=1e6+10,maxn=1e5+10;
const double pi=acos(-1.0);
typedef long long ll;
#define mp make_pair
#define eps 1e-8
//#define lighting ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
#define lighting ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);
ll n,a[N],m[N],maxx,tem,tt2,tt1,an[N];
signed main()
{
    cin>>n;
    for(ll i=1;i<=n;i++) cin>>m[i];
    for(ll i=1;i<=n;i++)
    {
        tem=0;
        tt1=tt2=m[i];
        tem+=m[i];
        a[i]=m[i];
        for(ll j=i+1;j<=n;j++)
        {
            if(m[j]>tt1)
            {
                a[j]=tt1;
                tem+=a[j];
                tt1=a[j];
                continue;
            }
            a[j]=m[j];
            tem+=a[j];
            tt1=a[j];
        }
        for(ll j=i-1;j>=1;j--)
        {
            if(m[j]>tt2)
            {
                a[j]=tt2;
                tem+=a[j];
                tt2=a[j];
                continue;
            }
            a[j]=m[j];
            tem+=a[j];
            tt2=a[j];
        }
        if(tem>maxx)
        {
            maxx=tem;
            for(ll i=1;i<=n;i++)
            {
                an[i]=a[i];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        cout<<an[i]<<" ";
    }
}
 	  	   	     			 		  	 			 	 	