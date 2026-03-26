#include <bits/stdc++.h>

#define ll long long
#define ld long double

using namespace std;

void Void() {
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < a.size(); i++) {
        if (c[i] == a[i] or c[i] == b[i]) {
            continue;
        }
        else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t = 1;
    cin >> t;
    while (t--) Void();
    return 0;
}
