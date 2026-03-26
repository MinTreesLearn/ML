// LUOGU_RID: 97860564
#include<bits/stdc++.h>
#define ll long long
#define ff(i,s,e) for(int i=(s);i<=(e);++i)
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=1e5+5,M=(1<<8)+5;
int n,m,k;
int f[M],tong[M],cnt[M];
struct qwq{
	int pos,op,id;
	bool operator < (const qwq &a) const{
		if(pos!=a.pos) return pos<a.pos;
		return op<a.op;
	}
};
vector<qwq> g;
inline void init(){
	ff(i,1,(1<<k)-1){
		int num=0;
		ff(j,0,k-1) if(i&(1<<j)) ++num;
		cnt[i]=num&1;
	}
}
signed main(){
	n=read(),m=read(),k=read();
	init();
	ff(i,1,n){
		int l=read(),r=read();
		g.push_back({l,1,i}),g.push_back({r+1,-1,i});
	}
	sort(g.begin(),g.end());
	memset(f,-0x3f3f3f3f,sizeof(f));
	f[0]=0;
	for(int i=0;i<g.size();++i){
		qwq tmp=g[i];
		int pos=tmp.pos,op=tmp.op,id=tmp.id,val=0,now;
		if(i!=g.size()-1) val=g[i+1].pos-pos;
		if(op==1){
			ff(i,1,k) if(!tong[i]){tong[i]=id,now=i;break;}
			for(int s=(1<<k)-1;s>=0;--s){
				if(s&(1<<now-1)) f[s]=f[s^(1<<now-1)]+val*cnt[s];
				else f[s]+=val*cnt[s];
			}
		}
		else{
			ff(i,1,k) if(tong[i]==id){tong[i]=0,now=i;break;}
			ff(s,0,(1<<k)-1){ 
				if(!(s&(1<<now-1))) f[s]=max(f[s],f[s^(1<<now-1)])+val*cnt[s];
				else f[s]=-0x3f3f3f3f;
			}
		}
	}
	printf("%d\n",f[0]);
	return 0;
}