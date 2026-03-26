#pragma GCC optimize("O3")
#define pb push_back
#define ll long long
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ull unsigned long long
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for(auto to : a) {
        cout << to << " ";
    }
    cout << endl;
}
int main() {
    fast;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
return 0;
}
