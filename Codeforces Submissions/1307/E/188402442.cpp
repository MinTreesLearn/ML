#include<iostream>
#include<cstring>
#include<vector>
#include<array>
#include<cassert>
using namespace std;
using LL = long long;
const int maxn = 5005;
int s[maxn][maxn];
vector<pair<int, int> > p[maxn];

template<const int T>
struct ModInt {
    const static int mod = T;
    int x;
    ModInt(int x = 0) : x(x % mod) {}
    ModInt(long long x) : x(int(x % mod)) {} 
    int val() { return x; }
    ModInt operator + (const ModInt &a) const { int x0 = x + a.x; return ModInt(x0 < mod ? x0 : x0 - mod); }
    ModInt operator - (const ModInt &a) const { int x0 = x - a.x; return ModInt(x0 < 0 ? x0 + mod : x0); }
    ModInt operator * (const ModInt &a) const { return ModInt(1LL * x * a.x % mod); }
    ModInt operator / (const ModInt &a) const { return *this * a.inv(); }
    void operator += (const ModInt &a) { x += a.x; if (x >= mod) x -= mod; }
    void operator -= (const ModInt &a) { x -= a.x; if (x < 0) x += mod; }
    void operator *= (const ModInt &a) { x = 1LL * x * a.x % mod; }
    void operator /= (const ModInt &a) { *this = *this / a; }
    friend ostream &operator<<(ostream &os, const ModInt &a) { return os << a.x;}
    
    ModInt pow(int64_t n) const {
        ModInt res(1), mul(x);
        while(n){
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }
    
    ModInt inv() const {
        int a = x, b = mod, u = 1, v = 0;
        while (b) {
            int t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if (u < 0) u += mod;
        return u;
    }
    
};
typedef ModInt<1000000007> mint;

int mx[maxn];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        for(int j = 1; j <= n; j++)
            s[i][j] = s[i - 1][j];
        s[i][x]++;
    }
    for(int i = 1; i <= m; i++){
        int f, h;
        cin >> f >> h;
        pair<int, int> t;
        if (s[n][f] >= h){
            for(int j = 1; j <= n; j++){
                if (s[j][f] == h){
                    t.first = j;
                    break;
                }
            }
            for(int j = n; j >= 1; j--){
                if (s[n][f] - s[j - 1][f] == h){
                    t.second = j;
                    break;
                }
            }
            p[f].push_back(t);
        }
    }
    int t = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for(auto [x, y] : p[j]){
                if (x <= i && y > i) cnt3++;
                else if (x <= i) cnt1++;
                else if (y > i) cnt2++;
            }
            if (cnt3 == 0) mx[i] += min(1, cnt1) + min(1, cnt2);
            else mx[i] += min(2, cnt1 + cnt2 + cnt3);
        }
        t = max(t, mx[i]);
    }
    if (t == 0){
        cout << 0 << ' ' << 1 << '\n';
        return 0;
    }

    mint inv2 = mint(2).inv();

    auto C2 = [&](int x){
        return mint(x) * mint(x - 1) * inv2;
    };

    auto solve = [&](int last){
        if (mx[last] != t) return mint(0);
        mint ans = 1;
        for(int i = 1; i <= n; i++){
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            int type = 0;
            for(auto [x, y] : p[i]){
                if (last == x){
                    if (x <= last && y > last) type = 3;
                    else if (x <= last) type = 1;
                    else if (y > last) type = 2;
                }
                else{
                    if (x <= last && y > last) cnt3++;
                    else if (x <= last) cnt1++;
                    else if (y > last) cnt2++;
                }
            }
            assert(type != 2);
            if (cnt1 + cnt2 + cnt3 == 0) continue;
            if (type == 0){
                if (cnt3 == 0){
                    ans *= mint(max(1, cnt1)) * mint(max(1, cnt2));
                }
                else{
                    if (cnt1 == 0 && cnt2 == 0){
                        if (cnt3 > 1) ans *= C2(cnt3) * mint(2);
                        else ans *= mint(2);
                    }
                    else{
                        mint cnt = C2(cnt3) * mint(2);
                        if (cnt1 >= 1 && cnt2 >= 1)
                            cnt += mint(cnt1) * mint(cnt2);
                        if (cnt1 >= 1)
                            cnt += mint(cnt1) * mint(cnt3);
                        if (cnt2 >= 1)
                            cnt += mint(cnt2) * mint(cnt3);
                        ans *= cnt;
                    }
                }            
            }
            else if (type == 1){
                if (cnt2 + cnt3 > 0) ans *= mint(cnt2 + cnt3);
            }
            else if (type == 2){
                if (cnt1 + cnt3 > 0) ans *= mint(cnt1 + cnt3);
            }
            else{
                if (cnt1 + cnt2 + cnt3 > 0) ans *= mint(cnt1 + cnt2 + cnt3);
            }
        }
        return ans;
    };
    
    mint ans = solve(0);

    for(int i = 1; i <= n; i++){
        for(auto [x, y] : p[i]){
            ans += solve(x);
        }
    }
    cout << t << ' ' << ans << '\n';

}