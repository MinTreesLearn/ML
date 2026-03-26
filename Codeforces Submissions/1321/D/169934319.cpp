#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
const ll mod = 1e9 + 7;
const ld PI = 3.141592653589793238460;

#define CHAR_RANGE 128

/*bitset<10000000000> Primes;
void SieveOfEratosthenes()
{
    Primes[0] = 1;
    for (ll i = 3; i <= 10000000000; i += 2) {
        if (Primes[i / 2] == 0) {
            for (ll j = 3 * i; j <= 10000000000; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}

ll binary_exponentiation(ll a, ll b) {
    //a %= MOD;
    ll res = 1;
    while(b > 0) {
        if(b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

bool is_prime(ll x) {
    if(x == 2) return true;
    if(x % 2 == 1 && Primes[x / 2] == 0) return true;
    return false;
}

int get_bit_count(ll x) {
    return __builtin_popcountll(x);
}*/

const int max_size = 2e5 + 5;
vector<int> adj[max_size];
vector<int> adj2[max_size];
int visited[max_size] = {0};
int n,m;
//pair<int, int> s,e;
vector<int> v;
int dist[max_size];
//int par[max_size];
int dz[] = {0, 0, 0 ,0, 1, -1};
int dx[] = {0, 1, 0, -1, 0, 0};
int dy[] = {1, 0, -1, 0, 0, 0};

void bfs(int x) {
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    dist[x] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(auto child : adj[cur]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = 1;
                dist[child] = dist[cur] + 1;
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    while(m--) {
        int x,y; cin>>x>>y;
        adj[y].pb(x);
        adj2[x].pb(y);
    }
    int k; cin>>k;
    vector<int> poly_path(k);
    for(int i = 0; i < k; i++) {
        cin>>poly_path[i];
    }
    memset(dist, -1, sizeof(dist));
    bfs(poly_path[k - 1]);
    int ans_min = 0, ans_max = 0;
    for(int i = 0; i < k - 1; i++) {
        for(auto val : adj2[poly_path[i]]) {
            if(val != poly_path[i + 1] && dist[val] < dist[poly_path[i + 1]]) {
                ans_min++;
                break;
            }
        }
    }
    for(int i = 0; i < k - 1; i++) {
        for(auto val : adj2[poly_path[i]]) {
            if(val != poly_path[i + 1] && dist[val] <= dist[poly_path[i + 1]]) {
                ans_max++;
                break;
            }
        }
    }
    cout<<ans_min<<" "<<ans_max;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //int t;
    //cin>>t;
    //while(t--) {
        solve();
    //}
    return 0;    
}
/*
*/