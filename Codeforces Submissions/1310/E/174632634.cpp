#include<bits/stdc++.h>
#define LL long long
#define fr(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=2e3+20,mod=998244353;
int tot,n,k,ans;
vector<int>a;
inline void slove1()
{
	static int f[N+5],g[N+5];
	for(int i=1;;i++)
	{
		if(i*(3*i-1)/2<=N) g[++tot]=i*(3*i-1)/2;
		else break;
		if(i*(3*i+1)/2<=N) g[++tot]=i*(3*i+1)/2;
		else break;
	}
	f[0]=1;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=tot&&g[j]<=i;++j)
			if(((j+1)/2)&1) f[i]=(f[i]+f[i-g[j]])%mod;
			else f[i]=(f[i]-f[i-g[j]]+mod)%mod;
	}
	for(int i=2;i<=N;i++) f[i]=(f[i]+f[i-1])%mod;
	printf("%d\n",f[n]);
}
inline void slove2()
{
	static int f[N+5];f[0]=1;
	for(int i=1;i*(i+1)/2<=N;i++) for(int j=i*(i+1)/2;j<=N;j++) f[j]=(f[j]+f[j-i*(i+1)/2])%mod;
	for(int i=2;i<=N;i++) f[i]=(f[i]+f[i-1])%mod;
	printf("%d\n",f[n]);
}
inline bool cmp(const int &x,const int &y){return x>y;}
inline bool chk()
{
	vector<int>b=a,c;
	for(int i=1,s;i<k;i++)
	{
		sort(b.begin(),b.end(),cmp);s=0;
		for(int j=0;j<b.size();j++) s+=b[j]*(j+1);
		if(s>n||(i+3<k&&s>23)) return 0;
		for(int j=0;j<b.size();j++)
			for(int K=1;K<=b[j];K++)
				c.push_back(j+1);
		b=c;c.clear();
	}
	return 1;
}
bool dfs(int st)
{
	if(!chk()) return 0;ans++;
	for(int i=st,t;;i++)
	{
		a.push_back(i);t=dfs(i);a.pop_back();
		if(!t) return 1;
	}return 1;
}
int main()
{
//	fr(function)
	scanf("%d%d",&n,&k);
	if(k==1) slove1();
	else if(k==2) slove2();
	else dfs(1),printf("%d",ans-1);
	return 0;
}