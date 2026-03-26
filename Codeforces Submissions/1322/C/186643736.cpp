// LUOGU_RID: 97979252
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

const int N=500500;

int n,m;
ll c[N];
set<int> s[N];
map<set<int>,ll> sum;

ll gcd(ll x,ll y) {
	if(!y) return x;
	return gcd(y,x%y);
}

void solve() {
	n=read(),m=read(); sum.clear();
	rep(i,1,n) c[i]=read(),s[i].clear();
	rep(i,1,m) {
		int u=read(),v=read();
		s[v].insert(u);
	}
	rep(i,1,n) if(!s[i].empty()) sum[s[i]]+=c[i];
	ll g=0; rep(i,1,n) if(!s[i].empty()) g=gcd(g,sum[s[i]]);
	writeln(g);
}

int main() {
	int t=read(); while(t--) solve();
	return 0;
}
