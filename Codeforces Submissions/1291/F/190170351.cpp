#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
//#pragma GCC optimize("unroll-loops,O3")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
constexpr int N = 1e6+10,mod = 1e9+7,maxm = 1026;
constexpr ll inf = 1e18+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

int n,k,t;
int m;
int p[N];
bool vis[N];
vector<pll> adj[N];
bool good[N];
int lst[maxm];
vector<int> a;

char ask(int i){
	lst[i] = a.size();
	char c;
	a.pb(i);
	cout << "? " << i << endl;
	cin >> c;
	return c;
}

void rst(){
	cout << "R\n";
	a.clear();
	memset(lst,128,sizeof lst);
}

void dfs(int v){
	int l = 1 + (v-1)*k,r = v*k;
	rep(i,l,r+1){
		char c = ask(i);
		if (c == 'Y') good[i] = 0;

	}
	while (p[v] < (int)adj[v].size()){
		int u = adj[v][p[v]].X;
		int i = adj[v][p[v]].Y;
		p[v]++;
		if (vis[i]) continue;
		rst();
		rep(j,l,r+1){
			if (good[j]) 
				ask(j);
		}
		vis[i] = 1;
		dfs(u);
	}
}

int main(){
	//ios :: sync_with_stdio(0); cin.tie(0);  cout.tie(0);
	memset(lst,128,sizeof lst);
	cin >> n >> k;
	rep(i,1,n+1){
		char c = ask(i);
	   	if (c == 'N') good[i] = 1;
	}
	rst();
	if (k == 1){
		rep(i,1,n+1){
			if (!good[i]) continue;
			rep(j,i+1,n+1){
				if (!good[j]) continue;
				char s = ask(i);
				s = ask(j);
				if (s == 'Y') good[j] = 0;
				rst();
			}
		}
		int ans = 0;
		rep(i,1,n+1) ans += good[i];
		cout << "! " << ans << endl;
		return 0;
	}
	k /= 2;
	t = n/k;
	rep(i,1,t+1) rep(j,i+2,t+1){
		adj[i].pb({j,m});
		adj[j].pb({i,m});
		m++;
	}
	dfs(1);
	int ans = 0;
	rep(i,1,n+1) ans += good[i];
	cout << "! " << ans << endl;
}

