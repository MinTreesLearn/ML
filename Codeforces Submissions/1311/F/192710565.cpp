#include<bits/stdc++.h>
#define ll long long 
#define sc second
#define ft first
const int N = 1e8+9;
using namespace std;
vector<pair<long long, long long>> p(200005);
vector<ll> xs(200005), cnt(200005);

int m, n;

void update(vector<ll> &b, int u, int v) {
    for (; u <= m; u += (u & (-u))) {
        b[u] += v;
    }
}

ll get(vector<ll> &b, int u) {
    long long res = 0;
    for (; u > 0; u -= (u & (-u))) {
        res += b[u];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in.txt","r",stdin); 
    // freopen("out.txt","w",stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].ft;
        // cout << p[i].ft << ' ';
    }
    vector<ll> vs;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].sc;
        vs.push_back(p[i].sc);
    }
    
    vs.push_back(-1*N);
    sort(p.begin() + 1, p.begin() + n + 1);
    sort(vs.begin(), vs.end());
    
    vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
    m = vs.size();
    long long ans = 0;
    int pos;

    for (int i = 1; i <= n; i++) {
        pos = lower_bound(vs.begin(), vs.end(), p[i].sc) - vs.begin();
        ans += 1LL*get(cnt, pos)*p[i].ft - get(xs, pos);
        update(cnt, pos, 1);
        update(xs, pos, p[i].ft);
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << p[i].ft << "||" << p[i].sc << ' ';
    // }

    cout << ans;
}