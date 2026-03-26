#include <bits/stdc++.h>
using namespace std;
#define ar array
#define vc vector
#define ll long long
#define db long double
#define mk make_pair 
#define pb push_back
#define umap unordered_map
#define sz(A) ((int)(A.size()))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define line(k) rep(i, 1, k){cerr<<nl;}
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define per(i,n,k) for(int i=n;i>=k;i--)
#define print(x) {cout << x << endl; return;}
#define rprint(x) {cout << x << endl; return 0;}
string yes="YES\n",no="NO\n", sp=" ", nl = "\n";
#define trav(A, P) for(auto P=A.begin(); P!=A.end(); P++)

void __print(int x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T, typename V>
void __print(const array<T, 2> &x) {cerr << '{'; __print(x[0]); cerr << ','; __print(x[1]); cerr << '}';}
template<typename T, typename V>
void __print(const array<T, 3> &x) {cerr << '{'; __print(x[0]); cerr << ','; __print(x[1]); cerr << ','; __print(x[2]); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define _(x...) cerr << "~[" << #x << "] = ["; _print(x)
#else
#define _(x...)
#endif

// ar<int,2>
template<typename T> istream &operator>>(istream &istream, array<T,2> &p) { return (istream >> p[0] >> p[1]); }
template<typename T> ostream &operator<<(ostream &ostream, const array<T,2> &p) { return (ostream << p[0] << " " << p[1]); }
// ar<int,3>
template<typename T> istream &operator>>(istream &istream, array<T,3> &p) { return (istream >> p[0] >> p[1] >> p[2]); }
template<typename T> ostream &operator<<(ostream &ostream, const array<T,3> &p) { return (ostream << p[0] << " " << p[1] << " " << p[2]); }
// pair
template<typename T1, typename T2> istream &operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T1, typename T2> ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
// vector
template<typename T> istream &operator>>(istream &istream, vector<T> &v) { for (auto &it : v) { cin >> it; } return istream; }
template<typename T> ostream &operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) { cout << it << " "; } return ostream; }

template<typename T,typename T1>T rmax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T rmin(T &a,T1 b){if(b<a)a=b;return a;}

#define pys(x) cout << ((x)?"YES":"NO") << endl;
//fill(a,a+n, num)
const ll pinf = 1e12+5, minf = -(2e18+5);
const int mod = 1e9+7, MOD = 1e9+7, dom = 998244353, inf = 2e9+5;


void E_731(int tc){
    ll n, k;
    cin >> n >> k;
    vc<ll> a(k), t(k), ans(n+1, pinf);
    rep(i, 0, k-1)cin >> a[i];
    map<ll, ll> f;
    rep(i, 1, n)f[i] = pinf;
    rep(i, 0, k-1)cin >> t[i], ans[a[i]] = t[i], f[a[i]] = t[i];
    ll temp = pinf;
    rep(i, 1, n){
        temp = min(temp, f[i]);
        ans[i] = min({ans[i], temp, f[i]});
        temp++;
    }
    temp = pinf;
    per(i, n, 1){
        temp = min({temp, f[i], ans[i]});
        f[i] = min({ans[i], f[i], temp});
        ans[i] = min({ans[i], f[i], temp});
        temp++;
    }
    rep(i, 1, n)cout << ans[i] << " \n"[i==n];
}

void D_1553(int tc){
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int l = n-1, r = m-1;
    string na = "", nb = "", rb = b;
    reverse(all(rb));
    while(l>=0 && r>=0){
        if(a[l]==b[r]){
            na += a[l];
            nb += b[r];
            --l, --r;
        }
        else  l -= 2;
    }
    if(rb==nb && na==nb)print("YES")
    else print("NO")
}

void C_1234(int tc){
    int n;
    vc<string> s(2);
    cin >> n >> s[0] >> s[1];
    for(int i=0, j=0; i<n; i++){
        if(s[j][i]=='1' || s[j][i]=='2'){
            // the flow will be just passed to the next row
        }
        if(s[j][i]>='3'){
            // the flow is sure to get in the opposite row
            // not possible if the pipes are of type 1, 2
            if(s[1-j][i]=='1' || s[1-j][i]=='2')print("NO")
            else j = 1-j; // change of row
        }
        if(i==n-1 && j==1)print("YES");
    }
    cout << "NO" << nl;
}

void C_1307(){
    string s;
    cin >> s;
    int n = s.size();
    map<string, ll> f;
    rep(i, 0, n-1){
        string t(1, s[i]);
        for(char c='a'; c<='z'; c++){
            string p(1, c);
            if(f[p]>0ll){
                string q = p + t;
                f[q] += (ll)f[p];
            }
        }
        f[t]++;
    }
    ll ans = 0;
    for(pair<string, ll> e: f){
        ans = max(ans, e.second);
    }
    cout << ans << nl;
}

int32_t main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t = 1;
    // cin >> t;
    for(int i=1; i<=t; i++){
        C_1307();
    }
    return 0;
}
