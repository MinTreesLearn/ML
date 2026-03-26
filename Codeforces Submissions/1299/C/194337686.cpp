#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define lowbit(x) (x&(-x))
#define pb emplace_back
#define pr pair<int,int>
#define let const auto
const int N=1e6+5;
int read(){
	int x=0,f=1; char c=getchar();
	while(('0'>c||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=0,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?x:-x;
}
int n,a[N],nxt[N],fa[N];
ll pre[N];
struct node{
	ll v;int l,r;
	int len(){return r-l+1;}
	bool operator<(node b)const{return 1ll*v*b.len()>1ll*b.v*(r-l+1);}
};
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
	n=read();
	for(int i=1; i<=n; i++) a[i]=read(),pre[i]=pre[i-1]+a[i];
	priority_queue <node> q;
	for(int i=1; i<=n; i++) nxt[i]=i,q.push({a[i],i,i}),fa[i]=i;
	while(!q.empty()){
		auto [v,l,r]=q.top(); q.pop();
		if(nxt[l]!=r) continue;
		if(l==1) continue;
		int las=find(l-1);
		if(1ll*(pre[l-1]-pre[las-1])*(r-l+1)>=1ll*v*(l-las)){
			fa[l]=las; nxt[las]=r;
			q.push({pre[r]-pre[las-1],las,r});
		}
	}
	for(int i=1; i<=n; i=nxt[i]+1){
		double res=1.0*(pre[nxt[i]]-pre[i-1])/(nxt[i]-i+1);
		for(int j=i; j<=nxt[i]; j++) printf("%.10lf\n",res);
	}
	return 0;
}
