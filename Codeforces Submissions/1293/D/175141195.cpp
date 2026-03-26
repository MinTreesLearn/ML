#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=1010;
typedef pair<int,int>PII;
LL x[N],y[N],cnt;
LL d(LL x,LL y,LL a,LL b)
{
    return abs(a-x)+abs(y-b);
}
int main()
{
    LL ax,ay,bx,by;
    cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
    LL sx,sy,t;
    cin>>sx>>sy>>t;
    while(x[cnt]-sx<t&&y[cnt]-sy<t)
    {
        cnt++;
        x[cnt]=x[cnt-1]*ax+bx;
        y[cnt]=y[cnt-1]*ay+by;
    }
    //哈曼顿距离   d(i,i+1)+d(i+1,i+2)==d(i,i+2);
    LL res=0;
    for(int i=0;i<=cnt;i++)
    for(int j=i;j<=cnt;j++)
    {
        LL temp=min(d(sx,sy,x[i],y[i]),d(sx,sy,x[j],y[j]));
        temp+=d(x[i],y[i],x[j],y[j]);
        if(temp<=t)
        res=max(res,(LL)j-i+1);
    }
    cout<<res<<endl;
    return 0;
}
	    	  						  	  	 	 	      	