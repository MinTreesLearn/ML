#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1;
const ll oo = 1e18;
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1,-oo);
        n = nn;
    }
    auto max(int i) {
        ++i;
        T ans = -oo;
        while(i) {
            ans=::max(ans,fen[i]);
            i&=i-1;
        }
        return ans;
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]=::max(fen[i],val);
            i+= i&(-i);
        }
    }
};
int main() {
    int n,m; cin >> n >> m;
    vi l(n),s(n); 
    for(auto& i : l) cin >> i;
    for(auto& i : s) cin >> i;
    vi c(n+m);
    for(auto& i : c) cin >> i;
    c.insert(c.begin(),0);
    vector<vector<ll>> dp(n+m+1,vector<ll>(n+1,-oo));
    fenwick<ll> fenzero(n+m+2); // fenzero
    // need to take some maximum across a diagonal, all such dp, such that dp[l-x][cnt+x]
    // and then? not so easy, as their contributions add up. So to add +(cnt+x)*c[l-x] + (cnt+x-1)*c[l-x]
    // add half of this contribution, then subtract rest? 
    // also cases when the cnt gets to 0 first. Those contribution can be calculated. Do those seperately. 
    fenzero.update(0,0);
    for(int i=n-1;i>=0;--i) {
        int x = l[i];
        // fenzero
        ll cnt1 = fenzero.max(x);
        auto update = [&](int cnt, ll val) {
            val+=c[x]-s[i];
            if(val<=-oo/2) return;
            // calculate zero
            int at = x;
            while(cnt>0) {
                dp[at][cnt] = max(dp[at][cnt],val);
                cnt/=2;
                if(cnt) val+=c[at+1]*cnt;
                at++;
            }
            fenzero.update(at,val);
            
        };
        for(int cnt=n-1;cnt>=0;--cnt) {
            // pre-emptivily add.
            update(cnt+1,dp[x][cnt]);
        }
        update(1,cnt1);

    }
    cout << fenzero.max(n+m+1) << '\n';
}