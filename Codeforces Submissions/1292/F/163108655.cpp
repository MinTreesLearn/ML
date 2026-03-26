#include<cstdio>
#include<cctype>
#include<vector>

#define maxn 66

const int mod=1e9+7;

template<class T>

inline T read(){
	T r=0,f=0;
	char c;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?-r:r;
}

inline long long qpow(long long a,int b){
	long long ans=1;
	for(;b;b>>=1){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}

int n,a[maxn];

bool vis[maxn],tag[maxn];

long long C[maxn][maxn],A[maxn][maxn];

inline void Add(int &x,int y){
	x+=y-mod,x+=(x>>31)&mod;
}

int sum;

long long ans;

std::vector<int> to[maxn];

namespace Solve{

	long long f[1<<15];

	int N,n,m,d[maxn],d0[maxn],T[maxn],cnt[1<<15];

	inline void FWT(){
		for(int i=1;i<N;i<<=1)
			for(int j=0,p=i<<1;j<N;j+=p)
				for(int k=0;k<i;k++)
					Add(cnt[i|j|k],cnt[j|k]);
	}

	void dfs(int u){
		vis[u]=1;
		if(tag[u])d0[++n]=u;
		else d[++m]=u;
		for(auto v:to[u])
			if(!vis[v])dfs(v);
	}

	inline void work(int s){
		n=m=0,dfs(s);
		if(!m)return;
		N=1<<n,sum+=m-1;
		(ans*=C[sum][m-1])%=mod;
		for(int i=0;i<N;i++)
			cnt[i]=0,f[i]=0;
		for(int i=1;i<=m;i++){
			T[i]=0;
			for(int j=1;j<=n;j++)
				if(!(a[d[i]]%a[d0[j]]))
					T[i]|=1<<(j-1);
			cnt[T[i]]++;
		}
		FWT();
		for(int i=1;i<=m;i++)
			(f[T[i]]+=A[m-1][cnt[T[i]]-1])%=mod;
		for(int S=1;S<N-1;S++){
			if(!f[S])continue;
			int tot=cnt[S];
			long long val=f[S];
			for(int i=1;i<=m;i++)
				if((S&T[i])&&(S&T[i])!=T[i]){
					int S1=S|T[i];
					(f[S1]+=val*A[m-tot-1][cnt[S1]-tot-1])%=mod;
				}
		}
		(ans*=f[N-1])%=mod;
	}

}

int main(){
	n=read<int>();
	for(int i=1;i<=n;i++)
		a[i]=read<int>();
	for(int i=1;i<=n;i++){
		tag[i]=1;
		for(int j=1;j<=n;j++)
			if((i^j)&&!(a[i]%a[j]))
				tag[i]=0,to[i].push_back(j),to[j].push_back(i);
	}
	for(int i=0;i<=n;i++){
		C[i][0]=A[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
			A[i][j]=A[i-1][j-1]*i%mod;
		}
	}
	ans=1;
	for(int i=1;i<=n;i++)
		if(!vis[i])Solve::work(i);
	printf("%lld\n",ans);
	return 0;
}
  	   	    		   		 				   	 			