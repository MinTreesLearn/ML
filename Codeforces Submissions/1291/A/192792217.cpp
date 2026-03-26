#include <iostream>
using namespace std;

int main() {
int t;
cin >> t;
while (t--) {
int n;
string s;
cin >> n >> s;
int odd = 0, cnt = 0;
for (char c : s) if ((c - '0') & 1) odd++;
if (odd <= 1) { cout << -1 << endl; continue; }
for (char c : s) {
if ((c - '0') & 1) { cout << c; cnt++; }
if (cnt == 2) break;
}
cout << endl;
}
}