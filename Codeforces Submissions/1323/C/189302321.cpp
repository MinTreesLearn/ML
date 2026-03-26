#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,fast-math")
using namespace std;
#define int long long

vector <int> a, b;
int ac(int x) {
    int ans = 0;
    int now = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i]) now++;
        else now = 0;
        if (now >= x) ans++;
    }
    return ans;
}
int bc(int x) {
    int ans = 0;
    int now = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) now++;
        else now = 0;
        if (now >= x) ans++;
    }
    return ans;
}
signed main() {int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    int bal = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') bal++;
        else bal--;
    }
    if (bal != 0) {
        cout << -1;
        return 0;
    }
    int ans = 0;
    int last_null = 0;
    int minbal = 0;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '(') bal++;
        if (s[i] == ')') bal--;
        minbal = min(minbal, bal);
        if (bal == 0) {
            if (minbal < 0) {
                ans += i - last_null;
            }
            last_null = i;
            minbal = 0;
        }
    }
    cout << ans;
}