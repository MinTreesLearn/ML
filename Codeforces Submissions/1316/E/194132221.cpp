#include<bits/stdc++.h>
#include<chrono>
#include<random>
#include<assert.h>
#include<stdexcept>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iomanip>
#include<map>
#include<vector>
#define num1bit(x) __builtin_popcount(x)
#define C continue
#define B break
#define R return
#define ll long long int
#define ld long double
#define ull unsigned long long
#define nd second
#define st first
#define bn begin()
#define ed end()
#define wte long Tests ; cin >> Tests ; while(Tests--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define b(myint,z) bitset<64>z(myint) ; cout<<z<<endl ;
#define endl '\n'
#define pb push_back
#define SPR(a) cout<<fixed<<setprecision(a) 
using namespace std;
const int oo = (int) 1e9 + 7;
const ld eps = 1e-8;
const ld PI = 3.14159265359;
const ll lloo = (ll) 1e18;
const int mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll Pow(ll a, ll b, ll mod = oo){
    ll res = 1;if(b < 0 || b >= mod)b = (b % (mod - 1) + mod - 1) % (mod - 1);
    for(;b;b >>= 1, a = 1ll * a * a % mod)
        if(b & 1)res = 1ll * res * a % mod;
    return res;
}
ld ldPow(ld a, ll b){
    ld res = 1;
    for(;b;b >>= 1, a = 1.0 * a * a)
        if(b & 1)res = 1.0 * res * a;
    return res;
}
ll inverseMod(ll A, ll bB, ll mod = oo){
    ll ans = Pow(bB, mod - 2, mod);
    ans %= mod;
    ans *= A;
    ans %= mod;
    return ans;
}
ll segma(ll x, ll y, ll mod = oo){
    ll res = x + y;
    res *= (max(x, y) - min(y, x) + 1);
    R res / 2;
}
ll mid(ll l, ll r){
    R(r - l) / 2 + l;
}
ll fac(ll a, ll mod){
    if(a == 0) R 1;
    R(a * (fac(a - 1, mod) % mod)) % mod;
}
ll LCM(ll x, ll y){
    R(x * y) / (ll) __gcd(x, y);
}
template<typename t>
t intlog2(t x){
    t res = 0;
    while(x > 0){
        res++;
        x /= 2;
    }
    R res;
}
template<typename t>
bool sec(pair<t, t> a, pair<t, t> b){
    R a.st - a.nd > b.st - b.nd;
};
template<typename t>
bool secr(pair<t, t> a, pair<t, t> b){
    if(a.st < b.st) R 1;
    if(a.st > b.st) R 0;
    if(a.nd < b.nd) R 0;
    if(a.nd >= b.nd) R 1;
};
struct point{
    ld x{}, y{};
    point() = default;
    point(ld _x, ld _y) : x(_x), y(_y){}
    point operator+(const point& p) const{ return point(x + p.x, y + p.y); }
    point operator-(const point& p) const{ return point(x - p.x, y - p.y); }
    ld cross(const point& p) const{ return x * p.y - y * p.x; }
    ld dot(const point& p) const{ return x * p.x + y * p.y; }
    ld cross(const point& a, const point& b) const{ return (a - *this).cross(b - *this); }
    ld dot(const point& a, const point& b) const{ return (a - *this).dot(b - *this); }
    ld sqrLen() const{ return this->dot(*this); }
    void In(){
        cin >> x >> y;
    }
    void Out() const{
        cout << fixed << setprecision(7) << x << " " << y << endl;
    }
};
ld L(point a, point b){
    R(a.x - b.x)* (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll ccw(point a, point b, point c){
    R(b.x - a.x)* (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
//#define MPF
#ifdef MPF
const int N = 300300, M = 5050, NN = 10001005;
int MinPrime[NN];
vector<int> Prime;
void init(){
    MinPrime[1] = 1;
    for(int i = 2;i < NN;i++){
        if(MinPrime[i])C;
        Prime.pb(i);
        for(int j = i;j < NN;j += i){
            if(MinPrime[j])C;
            MinPrime[j] = i;
        }
    }
}
#endif

int n, p, k;
const int NN=1e5+9;
pair<pair<ll, vector<ll> >, int> a[NN];
ll dp[NN][(1<<8)];

int main(){
    for(int i=0;i<NN;i++){
        for(int j=0;j<(1<<8);j++) dp[i][j]=-oo;
    }
    cin >>n>>p>>k;

    for(int i=1;i<=n;i++){
        cin >>a[i].st.st;
        a[i].nd=i;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            int x;
            cin >>x;
            a[i].st.nd.pb(x);
        }
    }

    sort(a+1, a+n+1);
    dp[n+1][0]=0;
    // for(int i=1;i<=n;i++){
    //     cout<<a[i].st.st<<' ';
    //     for(int j=0;j<p;j++) cout<<a[i].st.nd[j]<<' ';
    //     cout<<endl ;
    // }
    for(int i=n;i>0;i--){
        for(int mas=0;mas<=(1<<p)-1;mas++){
            int cnt=num1bit(mas);
            if(dp[i+1][mas]!=-oo) dp[i][mas]=dp[i+1][mas];
            if(n-i+1-cnt<=k) {
                if(dp[i+1][mas]!=-oo)dp[i][mas]+=a[i].st.st;
            }
            for(int pos=0;pos<p;pos++){
                int l=1<<pos;
                if((l&mas)&&dp[i+1][(mas^l)]!=-oo)
                    dp[i][mas]=max(dp[i][mas],dp[i+1][(mas^l)]+a[i].st.nd[pos]);
            }
        }
        
    }
    cout<<dp[1][(1<<p)-1] <<endl ;
    R 0;
}