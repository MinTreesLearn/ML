#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define sc second
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
const ll mod = 1e9 + 7;

void solve(){
    int q, x, k, ans = 0;
    cin >> q >> x;
    int rem[x] = {0};
    while(q--){
        cin >> k;
        rem[k % x]++;
        for(ans; true; ans++){
            if(rem[ans % x] > 0){
                rem[ans % x]--;
            }
            else {cout << ans << '\n';break;}
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int T = 1;
    //cin >> T;
    while(T--){
        solve();
        cout << '\n';
    }
    
    return 0;
}