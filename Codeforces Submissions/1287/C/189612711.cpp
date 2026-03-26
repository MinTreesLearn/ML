#include "bits/stdc++.h"
using namespace std; using ll =  long long;
#define fi first
#define se second
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define pb push_back
#define ReadInputFile() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define speedUP() ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define print2d(mat,n,m){for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
//INT_MAX , INT_MIN;
const long long int mod = 1e9+7; const long long int modd = 998244353;
//debug template
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;} void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;} void __print(float x) {cerr << x;} void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';} void __print(const char *x) {cerr << '\"' << x << '\"';} void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//Print Template.
template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';} template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";} template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE 
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
template <typename T> void print(vector <T> v) { for (T i : v) cout << i << " "; cout << '\n'; }
template <typename T> void print(vector <vector <T>>& v) { for (vector <T>& vv : v) { for (T& i : vv) cout << i << " "; cout << '\n'; } } template <typename T> void read(vector <T>& v) {for (T& i : v) cin >> i;}
template <typename T> void read(T&& t) {cin >> t;} template <typename T, typename... Args> void read(T&& t, Args&&... args){ cin >> t; read(forward<Args>(args)...); } template <typename T> void print(T&& t) {cout << t << '\n';}
template <typename T, typename... Args> void print(T&& t, Args&&... args){ cout << t << " "; print(forward<Args>(args)...); }


signed main(){
    speedUP();

    ll n; cin >> n;

    vector<ll> arr(n);

    set<ll> missing;
    for(ll i = 1; i <= n; i++) missing.insert(i);

    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i]) missing.erase(arr[i]);
    }

    ll cnt_odd = 0, cnt_even = 0;

    for(auto el : missing){
        if(el % 2) cnt_odd++;
        else cnt_even++;
    }
    debug(missing);
    debug(cnt_even, cnt_odd);

    vector<vector<vector<vector<ll>>>> dp(n + 5,vector<vector<vector<ll>>>(n + 5,vector<vector<ll>>(n + 5,vector<ll>(3,-1))));

    auto dfs = [&](ll cur, ll cnt_odd, ll cnt_even, ll prev, auto&& dfs)->ll{
        if(cur >= n) return 0ll;

        if(dp[cur][cnt_odd][cnt_even][prev] != -1) return dp[cur][cnt_odd][cnt_even][prev];
        if(arr[cur] == 0){
            if(prev == 2){
                // i can put either even or odd anything
                ll a1 = 1e9, a2 = 1e9;
                if(cnt_odd > 0){
                    a1 = dfs(cur + 1, cnt_odd - 1, cnt_even, 1, dfs);
                }
                if(cnt_even > 0){
                    a2 = dfs(cur + 1, cnt_odd, cnt_even - 1, 0, dfs);
                }
                return dp[cur][cnt_odd][cnt_even][prev] = min(a1,a2);
            }else if(prev == 1){
                ll a1 = 1e9, a2 = 1e9;
                if(cnt_odd > 0){
                    a1 = dfs(cur + 1, cnt_odd - 1, cnt_even, 1, dfs);
                }
                if(cnt_even > 0){
                    a2 = 1 + dfs(cur + 1, cnt_odd, cnt_even - 1, 0, dfs);
                }
                return dp[cur][cnt_odd][cnt_even][prev] = min(a1,a2);
            }else{
                ll a1 = 1e9, a2 = 1e9;
                if(cnt_odd > 0){
                    a1 = 1 + dfs(cur + 1, cnt_odd - 1, cnt_even, 1, dfs);
                }
                if(cnt_even > 0){
                    a2 = dfs(cur + 1, cnt_odd, cnt_even - 1, 0, dfs);
                }
                return dp[cur][cnt_odd][cnt_even][prev] = min(a1,a2);
            }
        }else{
            if(prev == 2){
                return dp[cur][cnt_odd][cnt_even][prev] = dfs(cur + 1, cnt_odd, cnt_even, arr[cur] % 2, dfs);
            }
            else if(arr[cur] % 2){
                ll a1 = 1e9;
                if(prev % 2){
                    a1 = dfs(cur + 1, cnt_odd, cnt_even, 1, dfs);
                }else{
                    a1 = 1 + dfs(cur + 1, cnt_odd, cnt_even, 1, dfs);
                }
                return dp[cur][cnt_odd][cnt_even][prev] = a1;
            }else{
                ll a1 = 1e9;
                if(prev % 2){
                    a1 = 1 + dfs(cur + 1, cnt_odd, cnt_even, 0, dfs);
                }else{
                    a1 = dfs(cur + 1, cnt_odd, cnt_even, 0, dfs);
                }
                return dp[cur][cnt_odd][cnt_even][prev] = a1;
            }
        }
    };


    ll ans = dfs(0, cnt_odd, cnt_even, 2, dfs);

    print(ans);
}
 
































  
