#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define AboTaha_on_da_code ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define X first
#define Y second

const int dx[8]={0, 0, 1, -1, 1, -1, -1, 1}, dy[8]={1, -1, 0, 0, 1, -1, 1, -1};
const int M = 1e9+7, M2 = 998244353;
const double EPS = 1e-9;

int n1, n2, m, r, b, tot;
int s, os, ot, t, id;
vector <vector <vector <array <int, 4>>>> adj; // {cap, cost, id, flow}

void add(int u, int v, int mn, int mx, int cost)
{
    if (mn > 0) {
        adj[s][v].push_back({mn, cost, id});
        adj[v][s].push_back({0, -cost, id++});
        adj[u][t].push_back({mn, cost, id});
        adj[t][u].push_back({0, -cost, id++});
    }
    if (mx > mn) {
        adj[u][v].push_back({mx-mn, cost, id});
        adj[v][u].push_back({0, -cost, id++});
    }
}

void burn(int tc)
{
    cin >> n1 >> n2 >> m >> r >> b;
    os = n1+n2, ot = os+1, s = ot+1, t = s+1;
    tot = t+1, id = 0;
    adj.assign(tot, vector <vector <array <int, 4>>> (tot));
    int cnt = 0;
    for (int i = 0; i < n1; i++) {
        char x; cin >> x;
        if (x == 'R') cnt++, add(os, i, 1, m, 0);
        else if (x == 'B') cnt++, add(i, ot, 1, m, 0);
        else {
            adj[os][i].push_back({m, 0, id});
            adj[i][os].push_back({0, 0, id++});
            adj[i][ot].push_back({m, 0, id});
            adj[ot][i].push_back({0, 0, id++});
        }
    }
    for (int i = 0; i < n2; i++) {
        char x; cin >> x;
        if (x == 'B') cnt++, add(os, i+n1, 1, m, 0);
        else if (x == 'R') cnt++, add(i+n1, ot, 1, m, 0);
        else {
            adj[os][i+n1].push_back({m, 0, id});
            adj[i+n1][os].push_back({0, 0, id++});
            adj[i+n1][ot].push_back({m, 0, id});
            adj[ot][i+n1].push_back({0, 0, id++});
        }
    }
    vector <pair<int, int>> ed(m);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        x--, y--;
        ed[i] = {x, y};
        adj[x][y+n1].push_back({1, r, id});
        adj[y+n1][x].push_back({0, -r, id++});
        adj[y+n1][x].push_back({1, b, id});
        adj[x][y+n1].push_back({0, -b, id++});
    }
    adj[ot][os].push_back({(int)1e9, 0, id});
    adj[os][ot].push_back({0, 0, id++});
    while(true) {
        vector <int> dis(tot, 1e9);
        dis[s] = 0;
        vector <pair<int, int>> par(tot, {-1, -1});
        queue <int> q;
        vector <bool> inq(tot, false);
        q.push(s);
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            inq[cur] = false;
            for (int i = 0; i < tot; i++) {
                for (int e = 0; e < adj[cur][i].size(); e++) {
                    auto &f = adj[cur][i][e][0], &c = adj[cur][i][e][1];
                    if (f && dis[i] > dis[cur] + c) {
                        dis[i] = dis[cur] + c;
                        par[i] = {cur, e};
                        if (!inq[i]) {
                            q.push(i);
                            inq[i] = true;
                        }
                    }
                }
            }
        }
        if (!~par[t].X) break;
        cnt--;
        int cur = t;
        while(cur != s) {
            int &pre = par[cur].X, &idx = par[cur].Y;
            adj[pre][cur][idx][0]--;
            adj[pre][cur][idx][3]++;
            for (auto &e : adj[cur][pre]) {
                if (e[2] == adj[pre][cur][idx][2]) {
                    e[0]++, e[3]--;
                    break;
                }
            }
            cur = pre;
        }
    }
    // cnt != 0 --> no answer.
    if (cnt) return void (cout << -1);
    vector <vector <int>> flow(n1, vector <int> (n2));
    for (int i = 0; i < n1; i++) {
        for (int j = n1; j < n1+n2; j++) {
            for (auto [cap, c, dum, f] : adj[i][j])
                flow[i][j-n1]+=f;
        }
    }
    int ans = 0;
    string col;
    for (auto [x, y] : ed) {
        auto &ret = flow[x][y];
        if (ret > 0) {
            ret--, ans+=r;
            col.push_back('R');
        }
        else if (ret < 0) {
            ret++, ans+=b;
            col.push_back('B');
        }
        else col.push_back('U');
    }
    cout << ans << '\n' << col;
}

int main()
{
    AboTaha_on_da_code

//    freopen("Ain.txt", "r", stdin);
//    freopen("Aout.txt", "w", stdout);

    int T = 1; // cin >> T;

    for (int i = 1; i <= T; i++) {
//        cout << "Case " << i << ": ";
        burn(i);
        cout << '\n';
    }
    return 0;
}