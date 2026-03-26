#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 500005
#define inf 0x3f3f3f3f

int n,a[maxn],res[maxn];
int f[maxn][21],g[maxn][21],lg[maxn];

inline pii ask(int l,int r){
	r--; int k=lg[r-l+1];
	return mkp(max(f[l][k],f[r-(1<<k)+1][k]),min(g[l][k],g[r-(1<<k)+1][k])); 
}

signed main()
{
	n=read();
	For(i,1,n)a[i]=read();
	For(i,1,n-1) f[i][0]=min(a[i],a[i+1]),g[i][0]=max(a[i],a[i+1]);
	For(i,2,n)lg[i]=lg[i>>1]+1;
	For(j,1,20)
		For(i,1,n+1-(1<<j))
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]),
			g[i][j]=min(g[i][j-1],g[i+(1<<(j-1))][j-1]);
	int mx=0;
	For(i,1,n)
	{
		int l=1,r=min(i,n-i+1),p=0;
		// 二分 0/1 交替 长度
		while(l<r){
			int mid=l+r>>1;
			pii now=ask(i-mid,i+mid);
			if(now.fi<now.se) p=mid,l=mid+1;
			else r=mid;
		}
		mx=max(mx,p);
		if(!p) {res[i]=a[i];continue;}
		pii now=ask(i-p,i+p);
		res[i]=(((p&1)^(a[i]<a[i-1]))?now.fi:now.se);
	}
	cout<<mx<<endl;
	For(i,1,n) printf("%d ",res[i]);
	return 0;
}