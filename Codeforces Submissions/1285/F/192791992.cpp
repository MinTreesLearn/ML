#pragma GCC optimization("Ofast")
#include <bits/stdc++.h>
using namespace std;
int Tc = 1;
void solve() {
int n, check = 0;
cin >> n;
vector<int> a(n);
for (auto& e : a)
cin >> e;
sort(a.begin(), a.end());
a.erase(unique(a.begin(), a.end()), a.end());
long long ans = 0;
for (int i = a.size() - 1; i >= 0; --i) {
if (i > (int)a.size() - 47 || (check <= 47 && ((a[i] ^ a.back()) & 1))) {
if (i < (int)a.size() - 47) check++;
for (int j = 0; j < n; ++j) {
ans = max({ans, a[i] * 1ll * a[j] / __gcd(a[i], a[j])});
}
}
}
cout << ans;
}
signed main() {
cin.tie(0)->sync_with_stdio(0);
// cin >> Tc;
while (Tc--)
solve(), cout << '\n';
}