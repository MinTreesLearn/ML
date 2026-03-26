#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vp = vector <pii>;
using vl = vector<ll>;

const int inf = INT_MAX;
const ll linf = LLONG_MAX;

const int mod = 1e9+7;

int mex(vi v) {
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    for(int i = 0; i < sz(v); i++)
        if(i != v[i]) return i;
    return sz(v);
}

using BLOCK = array<array<int, 3>, 5>;

vector <BLOCK> step[6][6][6];
vector <BLOCK> period[6][6][6];

void solve() {
    int n, x, y, z;
    scanf("%d %d %d %d", &n, &x, &y, &z);
    vl a(n);
    auto sg = [&](ll v, int j) -> int {
        ll b = v / 5;
        int r = v % 5;
        if(b < sz(step[x][y][z])) {
            return step[x][y][z][b][r][j];
        }
        else {
            b -= sz(step[x][y][z]);
            b %= sz(period[x][y][z]);
            return period[x][y][z][b][r][j];
        }
    };
    ll tot = 0;
    for(auto &v : a) {
        scanf("%lld", &v);
        tot ^= sg(v, 0);
    }
    int ans = 0;
    array <int, 3> w = {x, y, z};
    for(auto &v : a) {
        ll cur = tot ^ sg(v, 0);
        for(int j : {0, 1, 2}) {
            if(cur == sg(max(0ll, v - w[j]), j))
                ans++;
        }
    }
    printf("%d\n", ans);

}

int main() {
    for(int x = 1; x <= 5; x++) {
        for(int y = 1; y <= 5; y++) {
            for(int z = 1; z <= 5; z++) {
                set <BLOCK> S;
                vector <array<int, 3>> sg;
                vector <BLOCK> block_sg;
                array <int, 3> w = {x, y, z};
                for(int j = 0; ; j += 5) {
                    BLOCK block;
                    for(int k = j; k < j + 5; k++) {
                        array <int, 3> nsg;
                        if(k == 0) nsg = {0, 0, 0};
                        else for(int i : {0, 1, 2}) {
                            vi v;
                            for(int j : {0, 1, 2}) {
                                if(!i || i != j) {
                                    v.pb(sg[max(0, k - w[j])][j]);
                                }
                            }
                            nsg[i] = mex(v);
                        }
                        block[k - j] = nsg;
                        sg.pb(nsg);
                    }
                    if(S.count(block)) {
                        bool f = false;
                        for(int q = 0; q < sz(block_sg); q++) {
                            if(!f && block_sg[q] == block)
                                f = true;
                            if(!f) {
                                step[x][y][z].pb(block_sg[q]);
                            }
                            else {
                                period[x][y][z].pb(block_sg[q]);
                            }
                        }
                        break;
                    }
                    block_sg.pb(block);
                    S.insert(block);
                }
            }
        }
    }
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        solve();
    }
    return 0;
}
