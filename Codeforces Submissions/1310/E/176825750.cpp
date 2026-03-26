#include<bits/stdc++.h>
#define pb emplace_back
typedef long long LL;
typedef unsigned long long ULL;
typedef std::pair<int,int> PII;
using std::vector;
const int N=2030,mod=998244353;
inline int read()
{
	int x=0,y=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*y;
}

int n,K,ans;
inline int M(int A)
{
	return (A>=mod)?A-mod:A;
}

namespace sub1{
	// 不超过 n 的所有划分数方案。 
	//  dp[i]：i 的划分方案数，需要钦定从小到大，放入一个数。 
	//  dp[i]+=dp[i-k]; 
	//  dp[i]+=dp[i-k];
	int dp[N];
	signed main()
	{
		dp[0]=1;
		for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) dp[j]=M(dp[j]+dp[j-i]);
		for(int i=1;i<=n;i++) ans=M(ans+dp[i]);
		printf("%d\n",ans);
		return 0;
	}
}
namespace sub2{
	// f(f(S))：c[i] 个 i, 和小等于 n，c单调不增，方案数。
	// 单调不增 -> c[i-1]-c[i]>=0 -> 差分 
	// dp[i]=
	int dp[N];
	inline int S(int l,int r)
	{
		return (1ll*(l+r)*(r-l+1)/2)%mod;
	}
	signed main()
	{
		dp[0]=1;
		for(int i=1,ns;(ns=S(1,i))<=n;i++)
		{
			for(int j=ns;j<=n;j++)
			{
				dp[j]=M(dp[j]+dp[j-ns]);
			}
		}
		for(int i=1;i<=n;i++) ans=M(ans+dp[i]);
		printf("%d\n",ans);
		return 0;
	}
}
namespace sub3{
	int cnt[N];
	inline bool check(int nn)
	{
		int nw,sum=0;
		vector<int> a,b;a.clear(),b.clear();
		for(int i=1;i<=nn;i++) a.pb(cnt[i]);
		for(int i=1,nw;i<K;i++)
		{
			b.clear();
			std::reverse(a.begin(),a.end()),nw=sum=0;
			for(int sz:a)
			{
				++nw;
				for(int k=1;k<=sz;k++)
				{
					b.pb(nw);
					sum+=nw;
				}
			}
			std::swap(a,b);
			if(sum>n) return 0;
		}
		return 1;
	}
	int dfs(int step,int pre,int ns)
	{
		if(step&&!check(step)) return 0;
		ans++;
		for(int i=pre;i<=n-ns;i++)
		{
			cnt[step+1]=i;
			if(!dfs(step+1,i,ns+i)) return 1;
		}
		return 1;
	}
	signed main()
	{
		dfs(0,1,0),printf("%d\n",ans-1); 
		return 0;
	}
}

signed main()
{
// 	freopen("data.in","r",stdin);
// 	freopen("zj.out","w",stdout);
	n=read(),K=read();
	if(K==1) sub1::main();
	else if(K==2) sub2::main();
	else sub3::main();
	return 0;
}
