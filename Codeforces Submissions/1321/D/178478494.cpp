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

const int N = 2e5 + 100;
vector<int> g[N], qry[N];
int d[N];
void bfs(int st) {
	memset(d, -1, sizeof d);
	queue<int> q;
	q.push(st);
	d[st] = 0;
	while(SZ(q)) {
		int u = q.front();q.pop();
		for(int x: g[u]) {
			if(d[x] == -1) {
				d[x] = d[u] + 1;
				q.push(x); 
			}
		}
	}
}

int main()
{
	int T = 1;
	// cin >> T;
	while(T -- ) {
		int n, m;cin >> n >> m;
		for(int i = 0;i < m;i ++ ) {
			int u, v;cin >> u >> v;
			qry[u].pb(v);
			g[v].pb(u);
		}		
		int k;cin >> k;
		vector<int> a(k);
		for(int i = 0;i < k;i ++ ) cin >> a[i];
		bfs(a[k-1]);
		int l = 0, r = 0;
		for(int i = 0;i < k - 1;i ++ ) {
			int u = a[i], v = a[i+1], cnt = 0, f = 0;
			for(int x: qry[u]) {
				if(x == u) continue;
				if(d[x] == d[u] - 1) {
					cnt ++;
					if(v == x) f = 1;
				}
			}
			l ++, r ++;
			if(f == 1) l --;
			if(f == 1 && cnt == 1) r --;
			// cout << f << " " << l << " " << r << endl;
		}
		cout << l << " " << r << endl;
	}
	return 0;
}
