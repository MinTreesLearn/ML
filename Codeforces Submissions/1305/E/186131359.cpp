//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;
const int MAXN = 2e5 + 10;
const int MOD = 998244353;
#define int long long
using namespace __gnu_pbds;
int bm(int b, int p) { // bigmod
    if(p==0) return 1;
    int r = bm(b, p/2);
    if(p&1) return (((r*r) % MOD) * b) % MOD;
    return (r*r) % MOD;
}
int inv(int b) { // modinv
    return bm(b, MOD-2);
}
int f[MAXN];
int nCr(int n, int r) { // nCr main function, requires precomputation function
    int ans = f[n]; ans *= inv(f[r]); ans %= MOD;
    ans *= inv(f[n-r]); ans %= MOD; return ans;
}
int dsu[MAXN]; // disjoint set union
int set_of(int u) {
    if(dsu[u] == u) return u;
    return dsu[u] = set_of(dsu[u]);
}
void union_(int u, int v) {
    dsu[set_of(u)] = set_of(v);
}
void precomp() { // factorials for nCr
    f[0] = 1;
    for(int i=1; i<MAXN; i++) f[i] = (f[i-1] * i) % MOD;
}
int rnd(int x, int y) { // random number generator
    int u= uniform_int_distribution<int>(x, y)(rng); return u;
}
int sd(int n) { // sum of digits
    int sum = 0;
    while(n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
string binAdd(string a, string b) { //O(max(n,m)) time binary addition
    string result = ""; int s = 0;
    int i = a.size()-1, j = b.size()-1;
    while(i >= 0 || j >= 0 || s == 1) {
        s += ((i>=0 ? a[i] - '0':0));
        s += ((j>=0 ? b[j] - '0':0));
        result += char(s%2 + '0');
        s /= 2;
        i--, j--;
    }
    reverse(result.begin(), result.end());
    return result;
}
string binSub(string a, string b) { // O(max(n,m)) time binary subtraction, a ≥ b required
    string result = ""; int s = 0;
    int i = a.size()-1, j = b.size()-1;
    while(i >= 0 || j >= 0 || s != 0) {
        s += ((i>=0 ? a[i] - '0':0));
        s -= ((j>=0 ? b[j] - '0':0));
        result += char(abs(s)%2 + '0');
        if(s >= 0) s /= 2;
        else s = (s-1) / 2;
        i--, j--;
    }
    while(result.size() > 1 && result[result.size() - 1] == '0') {
        result.erase(result.size() - 1, 1);
    }
    reverse(result.begin(), result.end());
    return result;
}
int fastlog(int x) {
    int k = 32 - __builtin_clz(x) - 1;
    return k;
}

void stress(int tc) {
    
}
void solve(int tc) {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    if(n == 1 || n == 2) {
        if(m == 0) {
            cout << "2022 "; //!!!
            if(n == 2) cout << "2023\n";
            return;
        }
        else {
            cout << "-1\n"; 
            return;
        }
    }
    a[0] = 1;
    a[1] = 1, a[2] = 2;
    for(int i=3; i<=n; i++) {
        int wow = (i+1) / 2 - 1;
        if(m >= wow) {
            m -= wow;
            a[i] = i;
        }
        else {
            int st = i+1;
            if(m > 0) a[i] = a[i-1] + a[i-m*2]; 
            else st = i;
            m = 0;
            for(int j=st; j<=n; j++) {
                a[j] = 1000000000 - n * (4*n) + j * (4*n);
            }
            break;
        }
    }
    if(!m) {
        for(int i=1; i<=n; i++) cout << a[i] << " ";
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }
}
signed main(){
    precomp();        //Comment when not needed
//    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1;
//    cin >> t;
    int cnt = 0;
    while(t--){
        stress(++cnt);
        solve(++cnt);
    }
}