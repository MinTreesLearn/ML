//#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
/*测量运行时间
#include <windows.h>
DWORD star_time = GetTickCount();
DWORD end_time = GetTickCount();
cout << (end_time - star_time) << "ms." << endl;
*/
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
#define pb push_back
#define fi first
#define SZ(x) ((int)(x).size())
#define se second
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

const int N = 3010;
vector<int> g[N];
int fa[N][N], cnt[N][N];
ll f[N][N];
void dfs(int u, int f, int root) {
	cnt[root][u] = 1;
	fa[root][u] = f;
	for(int x : g[u]) {
		if(x == f) continue;
		dfs(x, u, root);
		cnt[root][u] += cnt[root][x];
	}
	return ;
}
ll dp(int u, int v) {
	if(u == v) return 0;
	if(f[u][v] != -1) return f[u][v];
	f[u][v] = cnt[v][u] * cnt[u][v] + max(dp(fa[v][u], v), dp(fa[u][v], u));
	return f[u][v];	
}

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		int n;cin >> n;
		memset(f, -1, sizeof f);
		for(int i = 1;i < n;i ++ ) {
			int u, v;cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		for(int i = 1;i <= n;i ++ ) {
			dfs(i, -1, i);
		}
		ll ans = 0;
		for(int i = 1;i <= n;i ++ ) {
			for(int j = 1;j <= n;j ++ ) {
				ans = max(ans, dp(i, j));
			}
		}
		cout << ans << endl;
	} 
	return 0;
}
