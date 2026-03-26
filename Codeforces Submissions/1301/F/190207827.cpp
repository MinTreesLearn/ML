/// Nu am loc de lista de adicenta? Calculez singur vecinii.
/// Nota: Nu e nev de nodurile auxiliare pentru a compresa graful - daca ma joc odata prin culoare, nu ma mai uit
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define debug(x) cerr << #x << " " << x << "\n"
#define debugs(x) cerr << #x << " " << x << " "

using namespace std;
typedef long long ll;
typedef pair <short, short> pii;

const ll NMAX = 1002;
const ll VMAX = 41;
const ll INF = (1LL << 59);
const ll MOD = 1000000009;
const ll BLOCK = 318;
const ll base = 31;
const ll nrbits = 21;

short dist[NMAX][NMAX][41];
short mat[NMAX][NMAX];
vector <pii> v[41];

struct ura {
    short pf, ps;
    int cost;
};

vector <ura> muchii;

short dx[] = {0, 1, -1, 0};
short dy[] = {1, 0, 0, -1};
short n, m;


bool OK(short i, short j) {
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
    short k, i, j;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
            v[mat[i][j]].push_back({i, j});
        }
    }
    deque <pii> dq;
    for(int col = 1; col <= k; col++) {
        for(i = 1; i <= n + 1; i++) {
            for(j = 1; j <= max(m, k); j++) {
                dist[i][j][col] = 32767;
            }
        }
        for(auto x : v[col]) {
            dist[x.first][x.second][col] = 0;
            dq.push_back({x.first, x.second});
        }
        while(dq.size()) {
            pii x = dq.front();
            dq.pop_front();
            if(x.first != n + 1) {
                for(int d = 0; d < 4; d++) {
                    pii care = {x.first + dx[d], x.second + dy[d]};
                    if(!OK(care.first, care.second)) continue;
                    if(dist[care.first][care.second][col] == 32767) { /// Hmm...
                        dist[care.first][care.second][col] = dist[x.first][x.second][col] + 1;
                        dq.push_back({care.first, care.second});
                    }
                }
                pii care = {n + 1, mat[x.first][x.second]};
                if(dist[care.first][care.second][col] == 32767) { /// Hmm...
                    dist[care.first][care.second][col] = dist[x.first][x.second][col];
                    dq.push_front({care.first, care.second});
                }
            } else {
                for(auto y : v[x.second]) {
                    pii care = y;
                    if(dist[care.first][care.second][col] == 32767) { /// Hmm...
                        dist[care.first][care.second][col] = dist[x.first][x.second][col] + 1;
                        dq.push_back({care.first, care.second});
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
