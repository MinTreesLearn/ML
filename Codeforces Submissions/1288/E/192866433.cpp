/// What are you doing now? Just go f*cking code now dude?
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define TASK "codin"
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long llu;
#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fi  first
#define se  second
#define mp make_pair
#define pb push_back
#define is insert
#define eb emplace_back
#define FOR(x,a,b) for (ll x=a;x<=b;x++)
#define FOD(x,a,b) for (ll x=a;x>=b;x--)
#define FER(x,a,b) for (ll x=a;x<b;x++)
#define FED(x,a,b) for (ll x=a;x>b;x--)
#define EL "\n"
#define ALL(v) v.begin(),v.end()
#define vi vector<ll>
#define vii vector<pii>
#define pii pair<int,int>

///---------- TEMPLATE ABOUT BIT  ----------///

ll getbit(ll val, ll num){
    return ((val >> (num)) & 1LL);
}

ll offbit(ll val, ll num){
    return ((val ^ (1LL << (num - 1))));
}

ll setbit(ll k, ll s) {
    return (k &~ (1 << s));
}

///---------- TEMPLATE ABOUT MATH ----------///

ll lcm(ll a, ll b){
    return a * b/__gcd(a, b);
}

ll bmul(ll a, ll b, ll mod){
    if(b == 0){return 0;}
    if(b == 1){return a;}
    ll t = bmul(a, b/2, mod);t = (t + t)%mod;
    if(b%2 == 1){t = (t + a) % mod;}return t;
}

ll bpow(ll n, ll m, ll mod){
    ll res = 1; while (m) {
        if (m & 1) res = res * n % mod; n = n * n % mod; m >>= 1;
    } return res;
}

///----------------------------------------///

const int S = 5e5 + 5, M = 2e3 + 4;
const ll mod = 1e9 + 7, hashmod = 1e9 + 9, inf = 1e18;
const int base = 311, BLOCK_SIZE = 420;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8]={0, 1, 1, 1, 0, -1, -1, -1};

///------ The main code starts here ------///

int n, m, a[S], minpos[S], maxpos[S], st[8 * S], pos[S];

void upd(int id, int le, int ri, int pos, int c){
    if(ri < pos || le > pos){
        return;
    }
    if(le == ri){
        st[id] += c;
        return;
    }
    int mi = (le + ri) / 2;
    upd(id * 2, le, mi, pos, c);
    upd(id * 2 + 1, mi + 1, ri, pos, c);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int query(int id, int le, int ri, int u, int v){
    if(u > ri || v < le){
        return 0;
    }
    if(le >= u && ri <= v){
        return st[id];
    }
    int mi = (le + ri) / 2;
    return query(id * 2, le, mi, u, v) + query(id * 2 + 1, mi + 1, ri, u, v);
}

void solve(){
    cin >> n >> m;
    FOR(i, 1, n){
        minpos[i] = maxpos[i] = i;
    }
    FOR(i, 1, m){
        cin >> a[i];
        minpos[a[i]] = 1;
    }
    int cnt = 0;
    FOD(i, n, 1){
        pos[i] = ++cnt;
        upd(1, 1, n + m, cnt, 1);
    }
    FOR(i, 1, m){
        cnt++;
        int tmp = query(1, 1, n + m, pos[a[i]], cnt);
        maxpos[a[i]] = max(maxpos[a[i]], tmp);
        upd(1, 1, n + m, pos[a[i]], -1);
        upd(1, 1, n + m, cnt, 1);
        pos[a[i]] = cnt;
    }
    FOR(i, 1, n){
        int tmp = query(1, 1, n + m, pos[i], cnt);
        maxpos[i] = max(maxpos[i], tmp);
    }
    FOR(i, 1, n){
        cout << minpos[i] << " " << maxpos[i] << EL;
    }
}

signed main(){

    IO
    if(fopen(TASK".inp","r")){
        freopen(TASK".inp","r",stdin);
        freopen(TASK".out","w",stdout);
    }
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

}





