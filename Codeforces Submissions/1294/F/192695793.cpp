// LUOGU_RID: 101696200
// LUOGU_RID: 101682976
#include<cstdio>
#include<ctime>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>
#include<cassert>
#include<random>
#include<numeric>
#include<functional>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define tor(i,v,x) for(int i=head[x],v=to[i];i;i=nxt[i],v=to[i])
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define mpi(x,y) make_pair(x,y)
#define pi pair<int,int>
#define fi first
#define se second
//#define int ll
#define DEBUG printf("%s %d\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ldb;
template<typename T>
void read(T &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	x=f?-x:x;
}
template<typename T,typename...Args>
void read(T &x,Args &...args){
	read(x);read(args...);
}

const int N=1e6+7;
int n,m,ans;
int dep[N];
vector<pi>mx[N];
vector<int>G[N];
vector<int>wt(3,0);

void upd(int x,int y,int z){
	wt[0]=x,wt[1]=y,wt[2]=z;
}

void df(int u,int fa){
	dep[u]=dep[fa]+1;
	mx[u].push_back(mpi(0,u));
	mx[u].push_back(mpi(0,u));
	for(int v:G[u]){
		if(v^fa){
			df(v,u);
			mx[u].push_back(mpi(mx[v][0].fi+1,mx[v][0].se));
		}
	}
	sort(mx[u].begin(),mx[u].end(),[&](pi &lhs,pi &rhs){
		return lhs.fi>rhs.fi;
	});
}

void dfs(int u,int fa){
	sort(mx[u].begin(),mx[u].end(),[&](pi &lhs,pi &rhs){
		return lhs.fi>rhs.fi;
	});
	if(mx[u][0].fi+mx[u][1].fi+mx[u][2].fi>ans){
		ans=mx[u][0].fi+mx[u][1].fi+mx[u][2].fi;
		upd(mx[u][0].se,mx[u][1].se,mx[u][2].se);
	}
//	cout<<"////u:"<<u<<endl;
//	for(pi p:mx[u]){
//		cout<<p.se<<' '<<p.fi<<' '<<"| ";
//	}
//	cout<<endl;
	for(int v:G[u]){
		if(v^fa){
			if(mx[v][0].se==mx[u][0].se){
				mx[v].push_back(mpi(mx[u][1].fi+1,mx[u][1].se));
			}else{
				mx[v].push_back(mpi(mx[u][0].fi+1,mx[u][0].se));
			}
			dfs(v,u);
		}
	}
}

void solve(){
	read(n);//mx和cmx存的就是节点了
	//dfs下放的时候注意下放节点标号和最长长度
	fs(i,1,n-1){
		int x,y;read(x,y);G[x].push_back(y);G[y].push_back(x);
	}
	df(1,0);dfs(1,0);
	sort(wt.begin(),wt.end());
	if(wt[1]==wt[0]||wt[1]==wt[2]){
		fs(i,1,n){
			if(i!=wt[0]&&i!=wt[2]){
				wt[1]=i;break;
			}
		}
	}
	printf("%d\n",ans);
	for(int nd:wt)printf("%d ",nd);
}

signed main(){
	int T=1;while(T--){
		solve();
	}
	return 0;
}