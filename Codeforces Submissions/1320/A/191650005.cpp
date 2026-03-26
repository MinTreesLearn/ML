/**
 *      Author:  nicksms
 *      Created: 02.01.2023 22:18:10
**/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> b(n);
    for (auto &&p : b) cin >> p;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = b[i]-i;
    }
    vector<ll> d(800001);
    ll m = 0;
    for (int i = 0; i < n; i++) {
        d[200000+c[i]] += b[i];
        m = max(d[200000+c[i]], m);
    }
    cout << m << "\n";
    
    return 0;
}