#include <bits/stdc++.h>
#define N 2505
using namespace std;
typedef long long ll;

template <typename T>
inline void read(T &num) {
	T x = 0, f = 1; char ch = getchar();
	for (; ch > '9' || ch < '0'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch <= '9' && ch >= '0'; ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ '0');
	num = x * f;
}

const int inf = 0x3f3f3f3f;
int n, m, Q;
int head[N], pre[N<<1], to[N<<1], flow[N<<1], cost[N<<1], sz = 1;
vector<int> A, B;

inline void addedge(int u, int v, int w, int c) {
	pre[++sz] = head[u]; head[u] = sz; to[sz] = v; flow[sz] = w; cost[sz] = c;
	pre[++sz] = head[v]; head[v] = sz; to[sz] = u; flow[sz] = 0; cost[sz] = -c;
}

queue<int> q;
int dis[N], vis[N], lst[N]; 
bool SPFA() {
	for (int i = 1; i <= n; i++) dis[i] = inf, vis[i] = lst[i] = 0;
	dis[1] = 0; vis[1] = 1; q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for (int i = head[x]; i; i = pre[i]) {
			int y = to[i]; if (!flow[i]) continue;
			if (dis[y] > dis[x] + cost[i]) {
				dis[y] = dis[x] + cost[i];
				lst[y] = i;
				if (!vis[y]) vis[y] = 1, q.push(y);
			}
		}
	} 
	return dis[n] != inf; 
} 

void mincost() {
	int F = 0, C = 0;
	while (SPFA()) {
		int Fl = inf;
		for (int i = n; i != 1; i = to[lst[i]^1]) Fl = min(Fl, flow[lst[i]]);
		F += Fl;
		for (int i = n; i != 1; i = to[lst[i]^1]) {
			C += Fl * cost[lst[i]]; 
			flow[lst[i]] -= Fl; 
			flow[lst[i]^1] += Fl;
		}
		A.push_back(F); B.push_back(C);  
	}
}

int main() {
	read(n); read(m);
	for (int i = 1, u, v, w; i <= m; i++) {
		read(u); read(v); read(w);
		addedge(u, v, 1, w);
	}
	mincost(); 
	read(Q);
	for (int i = 1, x; i <= Q; i++) {
		read(x);
		double ans = 1e12;
		for (int j = 0; j < A.size(); j++) {
			ans = min(ans, (B[j]+x)*1.0/A[j]);
		}
		printf("%.10f\n", ans);
	} 
	return 0;
} 
 						  	 			 	  	 		 			 	  	