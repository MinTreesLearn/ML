#include <bits/stdc++.h>

using namespace std;

int main() {
int T; cin >> T;
while (T--) {
string s, t; cin >> s >> t;

int a{1}, i{}, j{};

vector<vector<int>> F(26);
for (auto c: s) F[c - 'a'].push_back(i++);
for (auto c: t) {
auto &f = F[c - 'a'];
auto it = lower_bound(begin(f), end(f), j);
if (it == end(f)) {
a++;
it = lower_bound(begin(f), end(f), 0);
if (it == end(f)) { a = -1; break;}
}
j = (*it) + 1;
}
cout << a << '\n';
}
}