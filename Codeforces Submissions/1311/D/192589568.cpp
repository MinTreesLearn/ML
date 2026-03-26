#include<bits/stdc++.h>
#define nl "\n"
#define fi first
#define se second
#define pi 3.14159
#define ll long long
#define odd(a)  (a&1)
#define even(a)  !(a&1)
#define Mod 1'000'000'007
#define INF 2'000'000'000
#define sz(x) int(x.size())
#define charToInt(s) (s - '0')
#define ull unsigned long long
#define number_line iota(all(vec) , 1)
#define all(s) s.begin(), s.end()
#define rall(v) v.rbegin() , v.rend()
#define fixed(n) fixed << setprecision(n)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define to_decimal(bin) stoll(bin, nullptr, 2)
#define Ceil(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
#define Floor(n, m) (((n) / (m)) - ((n) % (m) ? 0 : 1))
#define Upper(s) transform(all(s), s.begin(), ::toupper);
#define Lower(s) transform(all(s), s.begin(), ::tolower);
#define cout_map(mp) for(auto& [f, s] : mp) cout << f << "  " << s << "\n";
//  ----- bits-------
#define pcnt(n) __builtin_popcount(n)  
#define pcntll(n) __builtin_popcountll(n)
#define clz(n) __builtin_clz(n)    // <---100
#define clzll(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctz(n)  // 0001---->
#define ctzll(n) __builtin_ctzll(n)

using namespace std;

template < typename T = int > istream& operator >> (istream &in, vector < T > & v){
    for(auto & x : v) in >> x;
    return in;
} 

template < typename T = int > ostream& operator << (ostream &out, const vector < T > & v){ 
    for(const T & x : v) out << x << " "; 
    return out;
}

void esraa()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
} 
void solve(){ 
    ll a , b , c;
    cin >> a >> b >> c;
    ll x , y , z , mini = 1e18;
    for(ll i = 1; i <= 20000; i++){
        for(ll j = i; j <= 20000; j += i){
            for(ll k = j; k <=20000; k += j){
                if(abs(a - i) + abs(b - j) + abs(c - k) < mini){
                    mini = abs(a - i) + abs(b - j) + abs(c - k);
                    x = i , y = j , z = k;
                }
            }
        }
    }
    cout << mini << nl;
    cout << x << " " << y << " " << z << nl;
}
int main()
{
    esraa();
    int t = 1;
    cin >> t;
    //cin.ignore();
    while(t--)
      solve();
    return 0;
} 