/* ゆめうつつ */
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 7;
const ll maxn = 2e5 + 5;
#define pb push_back
#define fi first
#define se second
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define floral                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0); cout.tie(0)

int n, m, k;

void solve(){
    cin >> n >> m >> k;
    vector<int> a(n+2), b(m+2);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    int mx = max(m, n);
    vector<int> ca(mx+1), cb(mx+1);
    int l = 1, r = 1;
    while(l <= n){
        if(a[l] == 0){
            l++;
            continue;
        }
        r = l;
        while(a[r] == 1 and r <= n) r++;
        int len = r - l;
        for(int i = 1; i <= len; i++){
            ca[i] += len - i + 1;
        }
        l = r;
    }
    l = 1, r = 1;
    while(l <= m){
        if(b[l] == 0){
            l++;
            continue;
        }
        r = l;
        while(b[r] == 1 and r <= m) r++;
        int len = r - l;
        for(int i = 1; i <= len; i++){
            cb[i] += len - i + 1;
        }
        l = r;
    }
    int ans = 0;
    for(int i = 1; i <= mx; i++){
        if(k % i == 0 and k / i <= mx){
            ans += ca[i] * cb[k / i];
        }
    }
    cout << ans << endl;
}

signed main(){
    floral;
    solve();
} 