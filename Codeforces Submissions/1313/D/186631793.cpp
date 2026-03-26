// LUOGU_RID: 97950406
//Writer: HugeWide
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

inline ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x) {
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),putchar('\n')

#define rep(x,l,r) for(int x=l;x<=r;x++)
#define per(x,r,l) for(int x=r;x>=l;x--)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

const int N=200200;

int n,m,k;
int l[N],r[N];
vector<int> raw;

int f[N][300];
vector<int> v[N];
bool vis[N];

int ppc(int s) {
	int r=0;
	while(s) {
		if(s&1) r++; s>>=1;
	} return r;
}

int g[300];

int main() {
	n=read(),m=read(),k=read();
	rep(i,1,n) l[i]=read()-1,r[i]=read();
	rep(i,1,n) raw.pb(l[i]),raw.pb(r[i]); raw.pb(-1e9);
	sort(all(raw)),raw.erase(unique(all(raw)),raw.end());
	rep(i,1,n) {
		l[i]=lower_bound(all(raw),l[i])-raw.begin();
		r[i]=lower_bound(all(raw),r[i])-raw.begin();
	}
	int T=(int)raw.size()-1;
	rep(i,1,n) {
		rep(j,l[i]+1,r[i]) v[j].pb(i);
	}
	rep(i,1,T) {
		int sz=v[i].size(),_sz=v[i-1].size();
		vector<int> d; d.clear(); int s=0;
		rep(j,0,sz-1) if(l[v[i][j]]+1==i) d.pb(j); int ds=d.size();
		rep(j,0,_sz-1) if(r[v[i-1][j]]!=i-1) s|=1<<j;
		rep(j,0,(1<<_sz)-1) g[j]=0;
		rep(j,0,(1<<_sz)-1) g[j&s]=max(g[j&s],f[i-1][j]);
		rep(j,0,(1<<_sz)-1) if((s&j)==j) rep(x,0,(1<<ds)-1) {
			rep(y,0,_sz-1) vis[v[i-1][y]]=(j>>y)&1;
			rep(y,0,ds-1) vis[v[i][d[y]]]=(x>>y)&1;
			int ss=0;
			rep(y,0,sz-1) if(vis[v[i][y]]) ss|=1<<y;
			f[i][ss]=max(f[i][ss],g[j]+(ppc(ss)%2)*(raw[i]-raw[i-1]));
		}
	}
	int ans=0;
	int sz=v[T].size();
	rep(i,0,(1<<sz)-1) ans=max(ans,f[T][i]);
	writeln(ans);
	return 0;
}
