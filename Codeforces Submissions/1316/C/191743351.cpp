#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
 
const ll MAXN = 1e6 + 20;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
 
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define endll '\n'

ll a[MAXN], b[MAXN];

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, m, p, x = 0, y = 0;
    cin >> n >> m >> p;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
        if(a[i] % p) x = i;
    }
    for(int i = 0; i < m; i ++){
        cin >> b[i];
        if(b[i] % p) y = i;
    }
    cout << x + y << endl;
    return 0;
}