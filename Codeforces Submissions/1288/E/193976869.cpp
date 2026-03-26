#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define int long long 
#define ld  long double
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define ss second 
#define ff first
#define inf (int)1e18
#define rz resize
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define all(x) x.begin(),x.end()


template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key
#define fbo find_by_order

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p){return (istream >> p.first >> p.second);}
template <typename T>
istream &operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template <typename T1, typename T2> 
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p){return (ostream << p.first << " " << p.second);}
template <typename T> 
ostream &operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c)cout << it << " ";return ostream;}
template <typename T>void print(T &&t) { cout << t << "\n"; }
template <typename T, typename... Args>void print(T &&t, Args &&...args){cout << t << " ";print(forward<Args>(args)...);}
template <typename T> int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }

const ld  PI = 3.141592653589793238;
const ld  eps=1e-11;
const int mod_9= 998244353;
const int mod=1e9+7;
const int N=3e5+10;
const int lim=505;





void solve(){
    
    int n,m;
    cin >> n >> m;
    
    ordered_set<pii> st;
    vi minans(n+1);
    vi maxans(n+1);
    vi tim(n+1,0);
    
    int cnt=0; 
    rep(i,1,n+1){
        minans[i]=maxans[i]=i;
        st.insert({0ll,i});
    }
    
    rep(i,0,m){
        int e;
        cin >> e;
        minans[e]=1;
        cnt--;
        int pos=st.ook({tim[e],e})+1;
        maxans[e]=max(maxans[e],pos);
        st.erase({tim[e],e});
        tim[e]=cnt;
        st.insert({tim[e],e});
    }
    
    
    int c=0; 
    for(auto it:st){
        c++;
        maxans[it.ss]=max(maxans[it.ss],c);
    }
    
    rep(i,1,n+1)
    cout << minans[i] << ' ' << maxans[i] << '\n';
    
    
    
         
}
 
int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
    

   
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    
    
    return 0;
}


