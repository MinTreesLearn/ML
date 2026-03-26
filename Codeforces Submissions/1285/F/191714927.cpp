//Then
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair <int, int>;
mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 1e5 + 1;
//const int Mod = 1e9 + 7;
//const int inf =
int n;
int a[maxN];
int cnt[maxN];
int phi[maxN];
vector <int> divs[maxN];
bool on[maxN];
int get(int x){
    int res = 0;
    for (int i: divs[x]){
        res += phi[i] * cnt[i];
    }
    return res;
}

void del(int x){
    for (int i: divs[x]){
        --cnt[i];
    }
}

void add(int x){
    for (int i: divs[x]){
        ++cnt[i];
    }
}

void Init(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        on[a[i]] = 1;
    }
    for (int i = 1; i <= 1e5; ++i){
        for (int j = i; j <= 1e5; j += i){
            divs[j].pb(i);
            if (i == 1) phi[i] = 1;
            else if ((i / divs[i][1]) % divs[i][1] == 0) phi[i] = 0;
            else phi[i] = -phi[i / divs[i][1]];
        }
    }
    ll ans = *max_element(a + 1, a + n + 1);
    for (int i = 1; i <= 1e5; ++i){
        vector <int> S;
        for (int j = 1e5 / i; j >= 1; --j){
            if (!on[j * i]) continue;
            int tem = get(j);
            while (tem){
                int u = S.back(); S.pop_back();
                if (__gcd(u, j) == 1){
                    ans = max(ans, 1LL * u * j * i);
                    --tem;
                }
                del(u);
            }
            add(j);
            S.pb(j);
        }
        for (auto i: S) del(i);
    }
    cout << ans;
}

#define debug
#define taskname "test"
signed main(){
    faster
    if (fopen(taskname".inp", "r")){
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    int tt = 1;
    //cin >> tt;
    while (tt--){
        Init();
    }
    if (fopen("timeout.txt", "r")){
        ofstream timeout("timeout.txt");
        timeout << signed(double(clock()) / CLOCKS_PER_SEC * 1000);
        timeout.close();
        #ifndef debug
        cerr << "Time elapsed: " << signed(double(clock()) / CLOCKS_PER_SEC * 1000) << "ms\n";
        #endif // debug
    }
}
