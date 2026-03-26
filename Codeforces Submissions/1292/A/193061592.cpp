#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)

typedef long double ld;
const int MOD = 1000000007;
#define ff first
#define ss second

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    int n, q; cin >> n >> q;
    set<pair<pair<int, int>, pair<int, int>>> st;
    vector<vector<int>> v(2, vector<int>(n, 0));
    vector<vector<bool>> vis(2, vector<bool>(n, false));
    auto update = [&](int x, int y, int add) {
        const int dx[] = {-1, -1, -1, 1, 1, 1};
        const int dy[] = {-1, 0, 1, -1, 0, 1};
        
        for(int k = 0; k < 6; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if(0 <= nx && nx < 2 && 0 <= ny && ny < n) {
                if((nx == 0 && ny == 0) || (nx == 1 && ny == n - 1)) continue;
                
                if(add == 1) {
                    if(vis[nx][ny]) {
                        pair<int, int> p1 = {x, y}, p2 = {nx, ny};
                        if(p1 > p2) {
                            swap(p1, p2);
                        }
                        st.insert({p1, p2});
                    }
                }
                else {
                    if(!vis[nx][ny]) continue;
                    
                    pair<int, int> p1 = {x, y}, p2 = {nx, ny};
                    if(p1 > p2) {
                        swap(p1, p2);
                    }
                    st.erase({p1, p2});
                }
            }
        }
    };
    while(q--) {
        int r, c; cin >> r >> c;
        --r; --c;
        if(!vis[r][c]) {
            vis[r][c] = true;
            update(r, c, 1);
        }
        else {
            vis[r][c] = false;
            update(r, c, -1);
        }
        
        cout << (sz(st) ? ("No\n") : ("Yes\n"));
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
        #ifdef LOCAL
            cout << "##################" << '\n';
        #endif
        if (solve()) {
            break;
        }
        cout << '\n';
    }
    #ifdef LOCAL
        cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
    return 0;
}
// -> Keep It Simple Stupid!