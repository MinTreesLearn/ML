#include <bits/stdc++.h>
#include <ext/random>
using namespace std;

//#define labeltc
#define endl "\n"
#define MAXN 262143
#define ll long long
#define MOD 1000000007
//#define MOD 998244353 //853?
#define INFLL 1000000000001000000LL
#define INFI 1001000000
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define sc second
#define m_p make_pair
#define p_b push_back
#define l_b lower_bound
#define u_b upper_bound
#define vi vector<int>
#define vll vector<ll>
#define sp(x) x << " "
#define rand_num(x,y) uniform_int_distribution<ll>((ll)x,(ll)y)(rng)
#define lsb(x) (x&(-x))
#define dgt(x) (x-'0')
#define all(x) x.begin(),x.end()
#define pans(x) ((x)? "YES " : "NO ")
template<typename T> bool ckmin(T& a, const T& b) {return (a>b)? a = b, 1 : 0;}
template<typename T> bool ckmax(T& a, const T& b) {return (a<b)? a = b, 1 : 0;}

__gnu_cxx::sfmt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

ll power(ll x, ll e, ll m = LONG_LONG_MAX){
    //e %= phi[m];
    ll r = 1;
    while(e>0){
        if(e%2) r = (r*x)%m;
        x = (x*x)%m;
        e >>= 1;
    }
    return r;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T,U>& v){
    os << sp(v.fi) << v.sc;
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    for (int i = 0; i < v.size(); ++i) {os << sp(v[i]);}
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v){
    for (auto it : v) {os << sp(it);}
    return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T,U>& v){
    for (auto it : v) {os << it << "\n";}
    return os;
}

void setIO(string s) {
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

int e[MAXN+1],ans,n;
ll cnt[MAXN+1];

void init(int x) {for (int i=0; i<=x; i++) e[i]=-1;}

int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

bool same_set(int a, int b) { return get(a) == get(b); }

int size(int x) { return -e[get(x)]; }

bool unite(int x, int y) {
    x = get(x), y = get(y);
       if(x==y) return false;
    if (e[x] > e[y]) swap(x, y);
       e[x] += e[y]; e[y] = x;
       return true;
}


void precomp(){
    return;
}

void solve(int tc){
    #ifdef labeltc
    cout << "Test case " << tc << ": ";
    #endif
    init(MAXN);
    cin >> n;
    ll ans = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        ans -= a;
        cnt[a]++;
    }
    cnt[0]++;
    for (int i=MAXN; ~i; i--){
        for (int j=i; 1; j=(j-1)&i){
            if(cnt[j]*cnt[i^j]){
                if(unite(j,i^j)){
                    ans += (cnt[j]+cnt[i^j]-1)*i;
                    cnt[j] = 1;
                    cnt[i^j] = 1;
                }
            }
            if(!j) break;
        }
    }
    cout << ans << endl;
    return;
}

int main(){
    //setIO();
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    precomp();
    int t=1;
    //cin >> t;
    for (int i=1; i<=t; i++) solve(i);
    return 0;
}