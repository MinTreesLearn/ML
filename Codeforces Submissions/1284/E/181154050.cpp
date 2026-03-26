// LUOGU_RID: 94202220
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define int long long
#define F(i,l,r) for(int i=(l),i##end=(r);i<=i##end;++i)
using namespace std;
const int N=2505;const long double pi=acos(-1.0L);
int n,ans,dp[N],s[N];long double x[N],y[N];
template<typename T>inline void readmain(T &n){T sum=0,x=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-')x=-1;ch=getchar();}while (ch>='0'&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}n=sum*x;}
template<typename T>inline T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>inline void read(T &x,Tr&... r){readmain(x);read(r...);}
template<typename T>inline void write(T x){if (x<0){putchar('-');x=-x;}if (x>9)write(x/10);putchar(x%10+'0');return;}
template<typename T>inline void writesc(T x){write(x);putchar(' ');}
template<typename T>inline void writeln(T x){write(x);putchar('\n');}
main()
{
	F(i,0,read(n)-1)read(x[i],y[i]);
	F(i,0,n-1)
	{
		vector<long double>v;
		F(j,0,n-1)if (j!=i)v.push_back(atan2(y[j]-y[i],x[j]-x[i]));
		int k=0;
		sort(v.begin(),v.end());F(j,0,n-1)
		{
			while (k<n-1&&v[k]<v[j]+pi)++k;
			dp[j]=k;s[j]=(j?s[j-1]:0)+dp[j];
		}
		F(j,0,n-1)ans+=(s[dp[j]-1]-s[j])-(dp[j])*(dp[j]-j-1);
	}
	write(ans*(n-4)/2);
	return 0;
}
