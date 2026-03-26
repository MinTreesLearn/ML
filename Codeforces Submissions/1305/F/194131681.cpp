#include <bits/stdc++.h>
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair <int, int>;
mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 2e5 + 1;
const int inf = 0x3f3f3f3f;
const int Mod = 1e9 + 7;
ll a[maxN];
int n;
bool in[maxN * 5];
vector <int> P;
inline int rd(int l, int r){
    return l + Rand() % (r - l + 1);
}
void Sieve(){
    for (int i = 2; i <= 1e6; ++i){
        if (!in[i]){
            P.pb(i);
            for (int j = i * 2; j <= 1e6; j += i)
                in[j] = 1;
        }
    }
}

int check(ll x){
    if (x == 0) return n;
    vector <ll> S;
    for (int i: P){
        if (x % i == 0){
            S.pb(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x != 1) S.pb(x);
    ll res = n;
    for (ll i: S){
        ll cnt = 0;
        for (int j = 1; j <= n; ++j){
            cnt += min(a[j] < i ? n : a[j] % i, i - (a[j] % i));
        }
        res = min(res, cnt);
    }
    return res;
}

void Init(){
    cin >> n;
    Sieve();
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    vector <int> b;
    for (int i = 0; i < 50; ++i) b.pb(rd(1, n));
    int ans = n;
    for (int i: b){
        ans = min(ans, check(a[i]));
        ans = min(ans, check(a[i] - 1));
        ans = min(ans, check(a[i] + 1));
    }
    cout << ans;
}

#define taskname "test"
signed main(){
    faster
    if (fopen(taskname ".inp", "r")){
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }
    int tt = 1;
    //cin >> tt;
    while (tt--){
        Init();
    }
    if (fopen("timeout.txt", "r")){
        ofstream timeout("timeout.txt");
        cerr << "Time elapsed: " << signed(double(clock()) / CLOCKS_PER_SEC * 1000) << "ms\n";
        timeout << signed(double(clock()) / CLOCKS_PER_SEC * 1000);
        timeout.close();
    }
}
