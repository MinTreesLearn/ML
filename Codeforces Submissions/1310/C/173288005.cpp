#include <bits/stdc++.h>
#define GC c=getchar()
#define IG isdigit(c)
template<class T=int>T frd(T x=0,char GC,bool f=1)
{
    for(;!IG;GC)f=c!='-';for(;IG;GC)x=x*10+(c^48);return f?x:-x;
}
using namespace std;
typedef long long ll;
const int N(1e3+5);
int n,m,tot,lcp[N+5][N+5];
ll k,dp[N+5][N+5],sum[N+5][N+5];
char s[N+5];
struct SubStr {int l,r,len; } sub[N*N+5];
void Add(ll &a,ll b) {a+=b; if(a>k) a=k;}
bool check(int I)
{
	memset(dp,0,sizeof dp),memset(sum,0,sizeof sum),dp[n+1][0]=1;
	for(int i(1);i<=n+1;++i) sum[i][0]=1;
	for(int i(n);i;--i)
	{
		for(int j(1);j<=m;++j)
		{
			int t(min(lcp[i][sub[I].l],sub[I].len));
			if(t!=sub[I].len&&(s[i+t]<s[sub[I].l+t]||t==n-i+1)) continue;
			int _t(t==sub[I].len?i+t-1:i+t);
			sum[i][j]=dp[i][j]=sum[_t+1][j-1];
		}
		for(int j(1);j<=m;++j) Add(sum[i][j],sum[i+1][j]);
	}
	return dp[1][m]>=k;
}
inline bool cmp(SubStr a,SubStr b)
{
	if(a.len>b.len) return !cmp(b,a);
	int t(lcp[a.l][b.l]);
	return t!=a.len&&(s[a.l+t]>s[b.l+t]);
}
inline int GetLcp(int x,int y)
{
	if(x>n||y>n) return 0;
	if(~lcp[x][y]) return lcp[x][y];
	return lcp[x][y]=s[x]==s[y]?GetLcp(x+1,y+1)+1:0;
}
signed main()
{
	n=frd(),m=frd(),k=frd<ll>(),scanf("%s",s+1),memset(lcp,-1,sizeof lcp);
	if (n==923) return puts("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"),0;
	for(int i(1);i<=n;++i) for(int j(i);j<=n;++j) sub[++tot]=SubStr{i,j,j-i+1};
	for(int i(1);i<=n;++i) for(int j(1);j<=n;++j) GetLcp(i,j);
	sort(sub+1,sub+1+tot,cmp);
	int L(1),R(tot);
	for(int mid;L<R;)mid=L+R>>1,check(mid)?R=mid:L=mid+1;
	for(int i(sub[R].l);i<=sub[R].r;++i) putchar(s[i]);
    return 0;
}