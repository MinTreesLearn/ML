#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fastread() (ios_base:: sync_with_stdio(false), cin.tie(NULL));
//LL, other ways to simplify it?, tricks & math, backwards, constraints,
//ll mod(1e9+7);

void runCase() {
    vector<int> v(26, 0);
    int n; cin >> n;
    int m; cin >> m;
    int a[m];
    map<int, int> ma[n];
    string s; cin >> s;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            ma[i] = ma[i-1];
        }
        ma[i][s[i] - 'a']++;
    }
    for (int i = 0; i < m; ++i) {
        for (auto y : ma[a[i] - 1]) {
            v[y.first] += y.second;
        }
    }
    for (auto y : ma[n - 1]) {
        v[y.first] += y.second;
    }
    for (int i = 0; i < 26; ++i) {
        cout << v[i] << " ";
    } cout << endl;
}


int main() {
    fastread()
    int t = 1;
    cin >> t;

    while (t--) {
        runCase();
    }

    return 0;
}