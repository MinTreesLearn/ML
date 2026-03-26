#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define pb push_back
#define ff first
#define ss second
#define oo 1000000000

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n,d; cin >> n >> d;
    int l=0,r=n;
    while(l<r) {
        int m=(l+r)/2;
        if(m + ceil(1.0*d/(m+1)) <= n) {
            cout << "YES"; return;
        } else {
            r=m;
        }
    }
    cout << "NO";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
