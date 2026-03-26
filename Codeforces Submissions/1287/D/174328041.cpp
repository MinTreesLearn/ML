// Problem: D. Numbers on Tree
// Contest: Codeforces - Codeforces Round #612 (Div. 2)
// URL: https://codeforces.com/contest/1287/problem/D
// Time: 2022-09-09 19:30:18
// User: zjh
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 当你觉得自己不行的时候 你就走到斑马线上 这样你就会成为一个行人
// 没关系 大不了我们大器晚成而已
// 
// Powered by CP Editor (https://cpeditor.org)

//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;

#define int128 __int128
#define endl '\n'
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
template <class T>
inline bool in(T &ret) 
{
	char c;T sgn;
	if(c=getchar(),c==EOF) return 0; 
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}
template <class T>
inline void out(T x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)
    out(x/10);
    putchar(x%10+'0');
}
const int N = 4010;
int sz[N], a[N], c[N];
vector<int> g[N];
vector<int> all;
int dfs(int u, int fa) {
	sz[u] = 1;
	for(int x : g[u]) {
		if(x == fa) continue;
		dfs(x, u);
		sz[u] += sz[x];
	}
	return sz[u];
}
void work(int u, int fa){
	nth_element(all.begin(), all.begin() + c[u], all.end());
	a[u] = all[c[u]];
	all.erase(all.begin() + c[u]);
	for(int x: g[u]) {
		if(x == fa) continue;
		work(x, u);
	}
}
int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		int n;cin >> n;
		int r = -1;
		for(int i = 1;i <= n;i ++ ) {
			int p;cin >> p >> c[i];
			if(p == 0) r = i;
			else {
				g[i].push_back(p);
				g[p].push_back(i);
			}
		}
		dfs(r, -1);
		for(int i = 1;i <= n;i ++ ) {
			if(c[i] > sz[i] - 1) {
				cout << "NO";
				return 0;
			}
		}
		for(int i = 1;i <= n;i ++ ) all.push_back(i);
		work(r, -1);
		cout << "YES" << endl;
		for(int i = 1;i <= n;i ++ ) cout << a[i] <<  " ";
	}
	return 0;
}