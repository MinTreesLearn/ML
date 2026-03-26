#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"
#define forn(i, n) for(int i = 0; i < n; i++)

void solve(){
    int a, b; cin >> a >> b;
    ll thing = (ll)(log10(b+1));
    cout << (a * thing);

    cout << nl;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    cout.flush();
    return 0;
}