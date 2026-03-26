#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<ld, ld>
#define ff first
#define ss second
#define all(v) v.begin(),v.end()

typedef tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update> ordset;

#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")

ll INF = 4e18;
const ll mod = (1ll << 32ll);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll binpow(ll n, ll m){
    if(m == 0) return 1ll;
    if(m & 1ll) return (n * binpow(n, m - 1ll)) % mod;
    ll b = binpow(n, m / 2ll);
    return (b*b) % mod;
}

struct str{
    int x1, y1, x2, y2;
};

int a[1000][1000], dist[1000][1000];
bool was[40];

int ans[100000];

str qq[100000];

vector<vector<pii>> cc(40);

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j]--;
            cc[a[i][j]].push_back({i, j});
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> qq[i].x1 >> qq[i].y1 >> qq[i].x2 >> qq[i].y2;
        qq[i].x1--;
        qq[i].x2--;
        qq[i].y1--;
        qq[i].y2--;
        ans[i] = abs(qq[i].x1 - qq[i].x2) + abs(qq[i].y1 - qq[i].y2);
    }
    queue<pii> st;
    for(int i = 0; i < k; i++){
        for(int i1 = 0; i1 < n; i1++){
            for(int j1 = 0; j1 < m; j1++){
                if(a[i1][j1] == i){
                    dist[i1][j1] = 0;
                    st.push({i1, j1});
                }
                else dist[i1][j1] = -1;
            }
        }
        for(int i1 = 0; i1 < k; i1++) was[i1] = 0;
        was[i] = 1;
        while((int)st.size()){
            pii u = st.front();
            st.pop();
            int cl = a[u.ff][u.ss];
            if(!was[cl]){
                was[cl] = 1;
                for(pii& v : cc[cl]){
                    if(dist[v.ff][v.ss] == -1){
                        dist[v.ff][v.ss] = dist[u.ff][u.ss] + 1;
                        st.push({v.ff, v.ss});
                    }
                }
            }
            for(int i1 = -1; i1 <= 1; i1++){
                for(int j1 = -1; j1 <= 1; j1++){
                    if(abs(i1) + abs(j1) == 1 && i1 + u.ff >= 0 && i1 + u.ff < n && u.ss + j1 >= 0 && u.ss + j1 < m && dist[u.ff + i1][u.ss + j1] == -1){
                        dist[u.ff + i1][u.ss + j1] = dist[u.ff][u.ss] + 1;
                        st.push({u.ff + i1, u.ss + j1});
                    }
                }
            }
        }
        for(int i1 = 0; i1 < q; i1++){
            ans[i1] = min(ans[i1], dist[qq[i1].x1][qq[i1].y1] + dist[qq[i1].x2][qq[i1].y2] + 1);
        }
    }
    for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
	int tt;
    //cin >> tt;
    tt = 1;
    while(tt--){
        solve();
		#ifdef LOCAL
            cout << "__________________________________" << endl;
		#endif
	}
	#ifdef LOCAL
        cout << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << "sec" << '\n';
	#endif
	return 0;
}
