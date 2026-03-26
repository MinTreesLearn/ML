/*    Your Mind Is Your Biggest Enemy    */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize ("-O3")
#define ll long long int
#define ld long double
#define ff first
#define ss second
/*-----------------------------------------------DEBUG FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef YuvrajSharma
#define deb(...) cerr << "(" << #__VA_ARGS__ << "): ", debug(__VA_ARGS__),cerr<<endl;
#else
#define deb(...);
#endif
void debug(ll t) {cerr << t;}
void debug(int t) {cerr << t;}
void debug(string t) {cerr << t;}
void debug(char t) {cerr << t;}
void debug(ld t) {cerr << t;}
void debug(double t) {cerr << t;}
void debug(unsigned ll t) {cerr << t;}
template <class Y, class V> void debug(pair <Y, V> p);
template <class Y> void debug(vector <Y> v);
template <class Y> void debug(set <Y> v);
template <class Y, class V> void debug(map <Y, V> v);
template <class Y> void debug(multiset <Y> v);
template <class Y, class V> void debug(pair <Y, V> p) {cerr << "{"; debug(p.ff); cerr << ","; debug(p.ss); cerr << "}";}
template <class Y> void debug(vector <Y> v) {cerr << "[ "; for (Y i : v) {debug(i); cerr << " ";} cerr << "]";}
template <class Y> void debug(set <Y> v) {cerr << "[ "; for (Y i : v) {debug(i); cerr << " ";} cerr << "]";}
template <class Y> void debug(multiset <Y> v) {cerr << "[ "; for (Y i : v) {debug(i); cerr << " ";} cerr << "]";}
template <class Y, class V> void debug(map <Y, V> v) {cerr << "[ "; for (auto i : v) {debug(i); cerr << " ";} cerr << "]";}
template <typename Head, typename... Tail> void debug(Head H, Tail... T){cerr << H << ' ';debug(T...);}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define endl '\n'
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define sz(x) (ll)x.size()
#define pqh priority_queue
#define ook order_of_key   //  returns position (unsigned integer) to given key
#define fbo find_by_order  //  returns iterator to the element at given position
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,n) for(i=1;i<=n;i++)
#define rep(i,a,b) for(i=a;i<=b;i++)
#define per(i,b,a) for(i=b;i>=a;i--)
#define all(x) x.begin(), x.end()
#define zerobits(x) __builtin_ctzll(x)
#define setbits(x)  __builtin_popcountll(x)
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define tol(s) transform(s.begin(),s.end(),s.begin(),::tolower);
#define tou(s) transform(s.begin(),s.end(),s.begin(),::toupper);
#define read(v) for(auto &itt:v) cin>>itt;
#define print(v) for(auto &itt:v) cout<<itt<<' ' ; cout<<endl;
#define T ll tt=0;cin>>tt;for(ll test=1;test<=tt;test++)
typedef pair<ll, ll>  pl;   typedef vector<pl>  vpl;    typedef pair<int,int> pi;    typedef vector<pi>   vpi;
typedef pair<ll,pl>   plp;  typedef vector<plp> vplp;   typedef pair<pi,int>  ppi;   typedef vector<ppi>  vppi;
typedef pair<pl,pl>   ppp;  typedef vector<ppp> vppp;   typedef pair<pi,pi>   pppi;  typedef vector<pppi>  vpppi;
typedef vector<ll>    vl;   typedef vector<vl>  vvl;    typedef vector<int>   vi;    typedef vector<vi>  vvi;
template <typename Y> using oset = tree<Y, null_type, less<Y>, rb_tree_tag, tree_order_statistics_node_update>;
template <class Y> void debug(oset<Y> v) {cerr << "[ "; for (auto i : v) {debug(i); cerr << " ";} cerr << "]";}
template <typename Y> using pql = priority_queue<Y, vector<Y>, greater<Y>>;
template <typename Y>
void make_unique(Y &vec) {
    vec.erase(unique(vec.begin(),vec.end()), vec.end());
}
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
ll randint(ll a, ll b){  return uniform_int_distribution<ll>(a, b)(rnd);   }
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const ll mod = 1e9+7; //  998244353 ;
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll isprime(ll n){ if(n<=1) return 0; if(n<=3) return 1; if(n%2==0||n%3==0) return 0; for(ll i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) return 0; return 1; } ll gcd(ll a,ll b){return __gcd(a,b); } void testnum(ll t){cout<<"Case #"<<t<<": ";}
ll lsb(ll n){ n=n^(n&(n-1)); ll pos=0; while(n){n=n>>1; pos++; } return pos-1; }/* acc. to zero indexing*/ ll bpow(ll a,ll n){ll res=1; while(n>0){ if(n&1LL) res=res*a; a=a*a; n>>=1; } return res; }
ll msb(ll n){                ll pos=0; while(n){n=n>>1; pos++; } return pos-1; }/* acc. to zero indexing*/ ll mpow(ll a, ll n,ll p){ a%=p; ll res=1; while(n>0){ if(n&1LL)res=res*a%p; a=a*a%p; n>>=1; } return res; }
ll add(ll a, ll b){ return (a+b)%mod; } ll sub(ll a,ll b){ return (a-b+mod)%mod; } ll mul(ll a, ll b){ return ((a%mod)* (b%mod)) % mod; } ll modI(ll n,ll p){ return mpow(n, p - 2, p); }
ll lcm(ll a,ll b){return (a*b)/__gcd(a,b);} ll LCM(vl &v,ll n){ ll ans=v[0]; for(ll i=1;i<n;i++) ans=(((v[i]*ans))/(__gcd(v[i],ans))); return ans; }ll ncr(ll n,ll r){if(n<0||r<0||n<r){return 0;}ll res=1;if(r>n-r)r=n-r;
for(ll i=0;i<r;++i){res*=(n-i);res/=(i+1);}return res; } map<ll, ll> pnt_compression(vl &pnt){ map<ll, ll> u; ll i=0,ct=0; fo(i,sz(pnt)){ u[pnt[i]]=0;} for(auto &it:u){ it.ss=ct; ct++;} return u; }
bool comp(pl a,pl b){
    return false;
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
const ld PI   = 3.141592653589793 ;
const ld eps  = 1e-9 ;
const ll inf  = 2e18 ; // 1e9;
const ll cons = 505;
ll N,M;
vl v;
ll dp[cons],dp2[cons][cons];
ll solve(ll l,ll r){
    if(l==r){
        return dp2[l][r]=v[l-1];
    }
    ll &ans=dp2[l][r];
    if(ans!=-1){
        return ans;
    }
    ans=0;
    for(ll i=l;i<r;i++){
        ll pre=solve(l,i),suf=solve(i+1,r);
        if(pre==suf&&pre>0){
            return ans=pre+1;
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    #ifdef YuvrajSharma
    freopen("input.txt","r",stdin),freopen("output.txt","w",stdout),freopen("error.txt", "w", stderr);
    #endif
    // cout<<fixed<<setprecision(9);
    ll n=0,m=0,i=0,j=0,k=0,cnt=0,ans=0,sum=0,flag=0,pos=-1,ind=-1,mn=inf,mx=-inf,res=0;
    cin>>n;
    v=vl(n);
    fo(i,n){
        cin>>v[i];
    }
    memset(dp2,-1,sizeof dp2);
    dp[0]=0;
    Fo(i,n){
        dp[i]=inf;
        for(j=1;j<=i;j++){
            if(solve(j,i)>0){
                dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n]<<endl;



    return 0;
}
/*  always remember these things
    => check edge cases like when n==1, l==r, overflow, array bounds
    => don't initialize dp with such values which dp state can attain
    => don't use memset when multiple testcases are present
    => there is a pattern when everything is uniformly distributed
    => try different approaches and try to find a general solution
    => BF, FC, LM, BS, MTH, GY, DP, DC, PSA, CT
*/
