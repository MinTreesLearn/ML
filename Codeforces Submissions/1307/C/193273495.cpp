//header files//
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll INF = 1e9 + 7;
const ll MOD = 998244353;
// definition files//;
#define int long long
#define loop(i, a, b) for(ll i = (ll)a; i <(ll) b; ++i)
#define fl(i,n) loop(i, 0, n)
#define rfl(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define pry cout<<"YES\n";
#define prm cout<<"-1\n";
#define prn cout<<"NO\n";
#define pb(x) push_back(x)
#define nl '\n'
#define inpt(v) fl(i,sz(v)) cin >> v[i];
#define prt(v)  for(auto i:v) cout << i << ' ';
#define sz(v) sizeof(v)
#define ff first
#define ss second
#define each(a, x) for (auto &a : x)
#define all(x) (x).begin(), (x).end()
#define Vmax(x) *max_element(all(x))
#define Vmin(x) *min_element(all(x))
#define fix(prec) cout << setprecision(prec) << fixed;
#define lowB(v,x) lower_bound(all(v),x)-v.begin() // >=x
#define upB(v,x)  upper_bound(all(v),x)-v.begin() // > x
#define charToInt(c) (c - '0')
 
//Debug 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
 //Template Class//
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
//main// 
//IMPORTANT PROPERTIES//
 
 //REMEMBER PARANTHESES PRECEDENCE for eg x=(x^y) and not x=x^y;
//Modular inverse//
/*int modular_inverse(int a, int m){
for (int x = 1; x < m; x++)
if (((a%m) * (x%m)) % m == 1)
return x;
return 0;
}*/
 
//Binary exponentiaition//
/*long long binpow(long long a, long long b) { 
if (b == 0)
return 1;
long long res = binpow(a, b / 2);
if (b % 2)
return res * res * a;
else
return res * res;
}*/
 
//-->even no. of 1s in xor cancel each other
 
/*struct cmp {
bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
return a.first < b.first;
}
}*/
 
void solve(){
 string s;cin>>s;
 int cnt[100];
 int inv[100][100];
 memset(cnt,0,sizeof(cnt));
 memset(inv,0,sizeof(inv));
 int ans=0;
    for(auto x:s){
        for(int i=0;i<26;i++) {
            inv[i][x-'a']+=cnt[i];
            ans=max(ans,inv[i][x-'a']);
        }
        cnt[x-'a']++;
        ans=max(ans,cnt[x-'a']);
    }
    cout<<ans<<nl;
}
signed main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
 int t = 1;
//  cin >> t;
 while (t--)
  {
     //start her UwU//
     solve();
  }
  return 0;
}