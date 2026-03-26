/*

You can have the world under your feet,
But all you do is cry,
I know you are scared of failing,
But Oh My Darlin, Give it a try.

    IWRITESOMETIMES | Maansi :)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define rep(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define mod 1000000007
#define inf 1000000000
#define endl "\n"
#define srt(ar) sort(ar.begin(), ar.end())
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pq priority_queue
#define rpq priority_queue<int, vi, greater<int>>
#define init std::fill(hash.begin(), hash.end(), -1)
#define FAST_IO(n)         \
    cout.setf(ios::fixed); \
    cout.precision(n);
#define print(v)        \
    rep(i, v.size())    \
            cout        \
        << v[i] << " "; \
    cout << endl;
#define mii map<int, int>

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
void solve(){
    int n, m;
    cin>>n>>m; 
    vi ar(n);    
    vi b(m);
    rep(i, n) cin>>ar[i];
    rep(i, m) cin>>b[i];
    srt(b);
    vi dummy = ar;
    vector<pii>vp;
    int first = b[0];
    for(int i = 0; i + 1 < m; i++){
        if(b[i] + 1 != b[i + 1]){
            vp.pb({first, b[i] + 1});
            first = b[i + 1];
        }
    }

    if(first != b[m-1]) vp.pb({first, b[m-1] + 1});
    else vp.pb({first, first + 1});

    for(auto i : vp){
        int f = i.first;
        int s = i.second;
        f--, s;
        sort(ar.begin() + f, ar.begin() + s);
    }
    
    srt(dummy);
    if(dummy == ar) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
    


}

int main()
{
    fastio;
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
