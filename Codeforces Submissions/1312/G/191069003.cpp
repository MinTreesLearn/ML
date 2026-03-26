#pr\
agma optimize("Ofast")

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#define f(i,x,y) for(int i=x, i##end=y; i<=i##end; ++i)
#define d(i,x,y) for(int i=y, i##end=x; i>=i##end; --i)
#define uf(i,x,y) for(int i=x, i##end=y; i<i##end; ++i)
#define ll long long
#define pir pair<int, int>
#define fir first
#define sec second
#define mp make_pair
#define pb push_back 
char ch;
int rd() {
	int f=1, x=0; ch=getchar();
	while(!isdigit(ch)) { f=((ch=='-')?-1:f); ch=getchar(); }
	while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
void rd(int& x) { x=rd(); }
using namespace std;
const int _ = 2e6 + 5;
int tr[_][26], sz[_], n, k, inq[_], dis[_], q[_];
vector< pair<int, int > > edge[_];
void insert(int p, char ch, int id) {
	tr[p][ch - 'a'] = id;
}
void addedge(int u, int v, int w) {
	// cerr << "add : " << u << " -> " << v << " " << w << endl;
	edge[u].pb(mp(v, w));
}
void dfs(int u) {
	if(inq[u]) ++sz[u], addedge(u+n+1, u, 1);
	f(i,'a','z') {
		if(tr[u][i - 'a']) {
			dfs(tr[u][i - 'a']);
			addedge(u+n+1, tr[u][i - 'a']+n+1, sz[u]);
			sz[u] += sz[tr[u][i - 'a']];
		}
	}
}
__gnu_pbds::priority_queue< pir , greater< pir > , __gnu_pbds::pairing_heap_tag > Q;
void dijkstra(int u) {
	memset(dis, 0x3f, sizeof(dis)); dis[u] = 0; Q.push(mp(-dis[u], u));
	while(Q.size()) {
		int u = Q.top().sec; Q.pop();
		// cerr << "at " << u << endl;
		for(auto [v, w] : edge[u]) {
			if(dis[v] > dis[u]+w) {
				Q.push(mp(-dis[v], v));
				dis[v] = dis[u] + w;
			}
		}
	}
}
int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	rd(n); f(i,1,n) {
		int p = rd(); char c = 0; while(!(c >= 'a' && c <= 'z')) c=getchar();
		// cerr << p << ' ' << ch << endl;
		insert(p, c, i);
		addedge(p, i, 1);
		addedge(i, i+n+1, 0);
	}
	addedge(0, n+1, 0);
	rd(k); f(i,1,k) {
		rd(q[i]); inq[q[i]] = 1;
	}
	dfs(0);
	dijkstra(0);
	f(i,1,k) cout << dis[q[i]] << " \n"[i == k];
	return 0;
}