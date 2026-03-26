//Then
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair <int, int>;
mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
const int maxN = 1e6 + 10;
//const int Mod = 1e9 + 7;
//const int inf =
int n, m;

template <class T> vector <int> ZFunc(const T &s){
    int _n = s.length();
    vector <int> z(_n);
    for (int i = 1, l = 0, r = 0; i < _n; ++i){
        if (i <= r){
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < _n && s[z[i]] == s[z[i] + i]) ++z[i];
        if (i + z[i] - 1 > r){
            r = i + z[i] - 1; l = i;
        }
    }
    return z;
}

struct TBit{
    ll bit[maxN];
    void update(int x, int v){
        for (; x <= m + 10; x += x & -x){
            bit[x] += v;
        }
    }
    ll get(int x){
        ll res = 0;
        for (; x > 0; x -= x & -x){
            res += bit[x];
        }
        return res;
    }
};
TBit B[2];

string a, b, s;
void Init(){
    cin >> n >> m >> a >> b >> s;
    vector <int> fa = ZFunc(s + "#" + a);
    reverse(s.begin(), s.end());
    reverse(b.begin(), b.end());
    vector <int> fb = ZFunc(s + "#" + b);
    fa.erase(fa.begin(), fa.begin() + s.length() + 1);
    fb.erase(fb.begin(), fb.begin() + s.length() + 1);
    for (int &i: fa) i = min(i, m - 1);
    for (int &i: fb) i = min(i, m - 1);
    reverse(fb.begin(), fb.end());
    int j = 0;
    while (j < min(n, m - 1)){
        B[0].update(m + 1 - fb[j], 1);
        B[1].update(m + 1 - fb[j], fb[j] - m + 1);
        //add 2
        ++j;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i){
        cerr << fa[i] + 1;
        ans += fa[i] * B[0].get(fa[i] + 1) + B[1].get(fa[i] + 1);
        B[0].update(m + 1 - fb[i], -1);
        B[1].update(m + 1 - fb[i], m - 1 - fb[i]);
        if (j < n){
            B[0].update(m + 1 - fb[j], 1);
            B[1].update(m + 1 - fb[j], fb[j] - m + 1);
            ++j;
        }
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
