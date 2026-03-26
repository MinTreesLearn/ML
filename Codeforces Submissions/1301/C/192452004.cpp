#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){

    ll n, m;
    cin >> n >> m;

    // if(m == 0){
    //     cout << 0 << endl;
    //     return;
    // }

    ll ans = (n*(n+1))/2;

    ll z = n - m;
    
    // floor(z/(m+1)) * (m-x) + ceil(z/(m+1)) * (x) = z
    // x = z % m+1;

    ll x = z % (m+1);

    ll c = ceil((double)z/(m+1));

    ans -= x * (c*(c+1))/2;

    ll f = z/(m+1);
    
    ans -= (m+1-x) * (f*(f+1))/2;
    cout << ans << endl;
}

int main() { 

    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    
    cin >> T;
    
    while (T--)
    {
        solve();
    }
    
    return 0;

}