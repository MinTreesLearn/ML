#include<bits/stdc++.h>
using namespace std;
long long n,m,nt[1000006],f[2][500005],sz[2][500005],ans;
vector<long long> vec[500005];
char a[500005],b[500005],c[1000006];
inline void add(long long op,long long u,long long w){for(long long i=u;i<=n;i+=(i&(-i))) sz[op][i]+=w;}
inline long long qry(long long op,long long u)
{
	long long sum=0;
	for(long long i=u;i>0;i-=(i&(-i))) sum+=sz[op][i];
	return sum;
}
int main()
{
	scanf("%lld%lld%s%s%s",&n,&m,a+1,b+1,c+1),a[n+1]=b[n+1]='$',c[m+1]='!';
	for(long long i=1;i<=m+1;++i) if(c[i]!=c[i+1]){nt[2]=i-1;break;}
	for(long long i=3,p=nt[2],p0=2;i<=m+1;++i)
	{
		if(i>p)
		{
			for(long long j=1;j<=m+1;++j) if(c[j]!=c[i+j-1]){nt[i]=j-1;break;}
			p=i+nt[i]-1,p0=i;
		}
		else if(i+nt[i-p0+1]-1>=p)
		{
			for(long long j=p+1;j<=m+1;++j) if(c[j]!=c[j-i+1]){nt[i]=j-i;break;}
			p=i+nt[i]-1,p0=i;
		}
		else nt[i]=nt[i-p0+1];
	}
	for(long long i=1;i<=n+1&&i<=m+1;++i) if(c[i]!=a[i]){f[0][1]=i-1;break;}
	for(long long i=2,p=f[0][1],p0=1;i<=n;++i)
	{
		if(i>p)
		{
			for(long long j=1;j<=m+1&&i+j-1<=n+1;++j) if(c[j]!=a[i+j-1]){f[0][i]=j-1;break;}
			p=i+f[0][i]-1,p0=i;
		}
		else if(i+nt[i-p0+1]-1>=p)
		{
			for(long long j=p+1;j<=n+1&&j-i+1<=m+1;++j) if(a[j]!=c[j-i+1]){f[0][i]=j-i;break;}
			p=i+f[0][i]-1,p0=i;
		}
		else f[0][i]=nt[i-p0+1];
	}
	reverse(c+1,c+1+m),reverse(b+1,b+1+n);
	for(long long i=1;i<=m+1;++i) if(c[i]!=c[i+1]){nt[2]=i-1;break;}
	for(long long i=3,p=nt[2],p0=2;i<=m+1;++i)
	{
		if(i>p)
		{
			for(long long j=1;j<=m+1;++j) if(c[j]!=c[i+j-1]){nt[i]=j-1;break;}
			p=i+nt[i]-1,p0=i;
		}
		else if(i+nt[i-p0+1]-1>=p)
		{
			for(long long j=p+1;j<=m+1;++j) if(c[j]!=c[j-i+1]){nt[i]=j-i;break;}
			p=i+nt[i]-1,p0=i;
		}
		else nt[i]=nt[i-p0+1];
	}//cout<<nt[3]<<endl;
	for(long long i=1;i<=n+1&&i<=m+1;++i) if(c[i]!=b[i]){f[1][1]=i-1;break;}
	for(long long i=2,p=f[1][1],p0=1;i<=n;++i)
	{
		if(i>p)
		{
			for(long long j=1;j<=m+1&&i+j-1<=n+1;++j) if(c[j]!=b[i+j-1]){f[1][i]=j-1;break;}
			p=i+f[1][i]-1,p0=i;
		}
		else if(i+nt[i-p0+1]-1>=p)
		{//cout<<i<<" "<<p<<endl;
			for(long long j=p+1;j<=n+1&&j-i<=m;++j) if(b[j]!=c[j-i+1]){f[1][i]=j-i;break;}
			p=i+f[1][i]-1,p0=i;
		}
		else f[1][i]=nt[i-p0+1];//cout<<i<<" "<<f[1][i]<<endl;
	}
	reverse(f[1]+1,f[1]+1+n);
	for(long long i=1;i<=n;++i)
	{//cout<<i<<" "<<f[0][i]<<endl;
		vec[i-1].push_back(-max(m-f[0][i],1ll));
		vec[min(n,i+m-2)].push_back(max(m-f[0][i],1ll));
	}
	for(long long i=1;i<=n;++i)
	{//cout<<i<<" "<<f[1][i]<<endl;
		long long len=vec[i].size();
		add(0,n-f[1][i]+1,1),add(1,n-f[1][i]+1,min(f[1][i],m-1));//cout<<i<<endl;//cout<<qry(0,4)<<" "<<qry(0,3)<<endl;
		for(long long j=0;j<len;++j)
		{//cout<<vec[i][j]<<endl;
			long long u=abs(vec[i][j]),tmp=qry(1,n-u+1)-(u-1)*qry(0,n-u+1);//cout<<i<<" "<<u<<" "<<qry(0,n-u+1)<<" "<<qry(1,n-u+1)<<endl;
			if(vec[i][j]<0) ans-=tmp;
			else ans+=tmp;
		}//cout<<i<<" "<<ans<<endl;
	}
	printf("%lld",ans);
}
	 	 	      	  		 				 				 	  	