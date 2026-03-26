// Problem: E. Cow and Treats
// Contest: Codeforces - Codeforces Round #621 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1307/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//回家？我没有家可以回，我没有退路。
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
vector<int> v[5003],a[5003];
int n=read(),m=read();
int col[5003];
pair<int,int> solve(int x)
{
	int res=0,ans=1;
	for(int i=1; i<=n; ++i) if(col[x]==i)
	{
		int X=0,Y=0,pos=0,s=(int)a[i].size();
		for(int j:v[i])
		if(j<=s&&a[i][j-1]==x) X=1,pos=j;
		if(!X) return make_pair(0,0);
		for(int j:v[i])
		if(j<=s&&a[i][j-1]!=x&&j+pos<=s) ++Y;
		if(Y) res+=2,ans=1ll*ans*Y%p;
		else ++res;
	}
	else
	{
		int s=a[i].size();
		int A=0,B=0,C=0;
		for(int j:v[i]) if(j<=s)
		{
			if(a[i][j-1]<x) ++A;
			if(a[i][s-j]>x) ++B;
			if(a[i][j-1]<x&&a[i][s-j]>x) ++C;
		}
		long long sum=1ll*A*B-C;
		if(sum) res+=2,ans=1ll*ans*(sum%p)%p;
		else if(A+B) res+=1,ans=1ll*ans*(A+B)%p;
	}
	return make_pair(res,ans);
}
pair<int,int> merge(pair<int,int> A,pair<int,int> B)
{
	if(A.first>B.first) return A;
	if(A.first<B.first) return B;
	return make_pair(A.first,(A.second+B.second)%p);
}
signed main()
{
	for(int i=1; i<=n; ++i) a[col[i]=read()].push_back(i);
	for(int i=1,x; i<=m; ++i)
		x=read(),v[x].push_back(read());
	pair<int,int> ans=make_pair(0,0);
	for(int i=0; i<=n; ++i) 
	ans=merge(ans,solve(i));
	printf("%d %d\n",ans.first,ans.second);
	return 0;
}