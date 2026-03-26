#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 3e5+10,mod = 998244353;
constexpr ll inf = 1e18+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
//    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int mod){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

int par[N],h[N],sz[N][2],fl[N][2],fx[N];
int ans;
vector<int> ve[N],adj[N];

int getpar(int v){
	if (v == par[v]) return v;
	int p = getpar(par[v]);
	h[v] ^= h[par[v]];
	par[v] = p;
	return par[v];
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0);  cout.tie(0);
	int n,k;
	string s;
	cin >> n >> k >> s;
	rep(i,0,k){
		par[i] = i;
		sz[i][0] = 1;
	}
	rep(i,0,k){
		int sz;
		cin >> sz;
		ve[i].resize(sz);
		rep(j,0,sz){
		   	cin >> ve[i][j];
			ve[i][j]--;
			adj[ve[i][j]].pb(i);
		}
	}
	rep(i,0,n){
		if (adj[i].empty()){
			cout << ans << endl;
		   	continue;
		}
		if ((int)adj[i].size() == 1){
			int ind = adj[i][0],p = getpar(ind);
			if (fl[p][0] || fl[p][1]){
				cout << ans << endl;
			   	continue;
			}
			ans -= min(sz[p][1],sz[p][0]);
			fx[p] = 1;
			if (s[i] == '1'){
				ans += sz[p][1-h[ind]];
				fl[p][1-h[ind]] = 1;
			}
			else{
				ans += sz[p][h[ind]];
				fl[p][h[ind]] = 1;
			}
			cout << ans << endl;
			continue;
		}
		int u = adj[i][0],v = adj[i][1];
		int p1 = getpar(u),p2 = getpar(v);
		if (p1 == p2){
			cout << ans << endl;
			continue;
		}
		bool d = h[u]^h[v];
		if (s[i] == '0') d ^= 1;
		par[p1] = p2;
		h[p1] = d;
		if (fx[p2] && fx[p1]){
			sz[p2][0] += sz[p1][d];
			sz[p2][1] += sz[p1][1-d];
			cout << ans << endl;
			continue;
		}
		if (fx[p2]){
			ans -= min(sz[p1][0],sz[p1][1]);
			if (fl[p2][0]) ans += sz[p1][d];
			else ans += sz[p1][1-d];
            sz[p2][0] += sz[p1][d];
            sz[p2][1] += sz[p1][1-d];
			cout << ans << endl;
			continue;
		}
		if (fx[p1]){
            ans -= min(sz[p2][0],sz[p2][1]);
            if (fl[p1][d]){
			   	ans += sz[p2][0];
				fl[p2][0] = 1;
			}
            else{
			   	ans += sz[p2][1];
				fl[p2][1] = 1;
			}
            sz[p2][0] += sz[p1][d];
            sz[p2][1] += sz[p1][1-d];
            cout << ans << endl;
			fx[p2] = 1;
            continue;
		}
        ans -= min(sz[p2][0],sz[p2][1]);
        ans -= min(sz[p1][0],sz[p1][1]);
        sz[p2][0] += sz[p1][d];
        sz[p2][1] += sz[p1][1-d];
        ans += min(sz[p2][0],sz[p2][1]);
		cout << ans << endl;
		continue;
	}
}
