// LUOGU_RID: 101604469
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const long long mod = 998244353;
int n, m;
vector<long long> fac;

long long fast_power(long long x, long long y) {
    long long res = 1;
    while(y > 0) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

long long exgcd(long long x, long long y, long long &c_x, long long &c_y) {
    if(y == 0) { c_x = 1, c_y = 0; return x; }
    long long gcd_x_y = exgcd(y, x % y, c_y, c_x);
    c_y -= (x / y) * c_x;
    return c_x;
}

long long inv(long long x) {
    long long c_x, c_mod;
    exgcd(x, mod, c_x, c_mod);
    return (c_x % mod + mod) % mod;
}

long long C(int n, int m) {
    return (fac[n] * inv(fac[m]) % mod) * inv(fac[n - m]) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    // 阶乘
    fac.resize(1 + m);
    fac[0] = 1;
    for(long long i = 1; i <= m; i += 1) {
        fac[i] = (i * fac[i - 1]) % mod;
    }
    //
    long long pick_num = C(m, n - 1);
    long long pick_place = n - 2;
    long long arrangement = fast_power(2, n - 3);
    long long ans = (pick_num * pick_place % mod) * arrangement % mod;
    cout << ans << "\n" << flush;
    return 0;
}