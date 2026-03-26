#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

const ll NMAX = 1002;
const ll VMAX = 41;
const ll INF = (1LL << 59);
const ll MOD = 1000000009;
const ll BLOCK = 318;
const ll base = 31;
const ll nrbits = 21;

int dist[NMAX][NMAX][41];
int mat[NMAX][NMAX];
vector <pii> v[41];

bool viz[41];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int n, m;


bool OK(int i, int j) {
    if(i > 0 && i <= n && j > 0 && j <= m)
        return 1;
    return 0;
}

int main() {
#ifdef HOME
    ifstream cin(".in");
    ofstream cout(".out");
#endif // HOME
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int k, i, j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
            v[mat[i][j]].push_back({i, j});
        }
    }
    for(int col = 1; col <= k; col++) {
        for(i = 1; i <= n + 1; i++) {
            for(j = 1; j <= max(m, k); j++) {
                dist[i][j][col] = 32767;
            }
        }
        for(i = 1; i <= k; i++) viz[i] = 0;
        queue <pii> q;
        for(auto x : v[col]) {
            dist[x.first][x.second][col] = 0;
            q.push({x.first, x.second});
        }
        while(q.size()) {
            pii x = q.front();
            q.pop();
            for(int d = 0; d < 4; d++) {
                pii care = {x.first + dx[d], x.second + dy[d]};
                if(!OK(care.first, care.second)) continue;
                if(dist[care.first][care.second][col] == 32767) { /// Hmm...
                    dist[care.first][care.second][col] = dist[x.first][x.second][col] + 1;
                    q.push({care.first, care.second});
                }
            }
            if(!viz[mat[x.first][x.second]]) {
                viz[mat[x.first][x.second]] = 1;
                for(auto y : v[mat[x.first][x.second]]) {
                    pii care = y;
                    if(dist[care.first][care.second][col] == 32767) { /// Hmm...
                        dist[care.first][care.second][col] = dist[x.first][x.second][col] + 1;
                        q.push({care.first, care.second});
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int minim = abs(c - a) + abs(d - b);
        for(int col = 1; col <= k; col++) {
            minim = min(minim, (int)dist[a][b][col] + (int)dist[c][d][col] + 1);
        }
        cout << minim << "\n";
    }
    return 0;
}
