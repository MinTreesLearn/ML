#include<iostream>
#include<cstring>
#include<random>
#include<cmath>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int maxn = 2e5 + 5;
static const ULL mod = (1ull << 61) - 1;
ULL power[maxn];
mt19937_64 rnd(random_device{}());
uniform_int_distribution<ULL> dist(100, mod - 1);
const ULL base = dist(rnd);
const ULL v[2] = {dist(rnd), dist(rnd)};

static inline ULL add(ULL a, ULL b){
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

static inline ULL mul(ULL a, ULL b){
    __uint128_t c = __uint128_t(a) * b;
    return add(c >> 61, c & mod);
}

ULL merge(ULL h1, ULL h2, int len2){
    return add(mul(h1, power[len2]), h2);
}

void init(int n){
    power[0] = 1;
    for(int i = 1; i <= n; i++)
        power[i] = mul(power[i - 1], base);
}

int s[maxn], pre[maxn];

ULL query(const vector<ULL> &s, int l, int r){
    return add(s[r], mod - mul(s[l], power[pre[r] - pre[l]]));
}


int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        s[i] = c - '0';
        pre[i] = pre[i - 1] + (s[i] == 0);
    }
    init(n);
    vector<ULL> hsh[2];
    hsh[0].assign(n + 1, 0);
    hsh[1].assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if (s[i]){
            hsh[0][i] = hsh[0][i - 1];
            hsh[1][i] = hsh[1][i - 1];
        }
        else{
            hsh[0][i] = add(mul(hsh[0][i - 1], base), v[i & 1]);
            hsh[1][i] = add(mul(hsh[1][i - 1], base), v[(i & 1) ^ 1]);
        }
    }
    int m;
    cin >> m;
    while(m--){
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        int r1 = l1 + len - 1, r2 = l2 + len - 1;
        if (query(hsh[l1 & 1], l1 - 1, r1) == query(hsh[l2 & 1], l2 - 1, r2)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

}