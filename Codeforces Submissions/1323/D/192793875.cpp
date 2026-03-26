#include <algorithm>
#include <iostream>

using namespace std;

const int N = 400000;
const int A = 1 << 26;

int aa[N], kk[A];

int main() {
int n; cin >> n;
for (int i = 0; i < n; i++)
cin >> aa[i];
int ans = 0;
for (int h = 0; h < 25; h++) {
int m = 1 << h + 1;
for (int a = 0; a < m; a++)
kk[a] = 0;
for (int i = 0; i < n; i++)
kk[aa[i] % m]++;
for (int a = m; a < m + m; a++)
kk[a] = kk[a - m];
for (int a = 1; a < m + m; a++)
kk[a] += kk[a - 1];
int k = 0;
for (int i = 0; i < n; i++) {
int a = aa[i] % m;
int l = ((1 << h) - a + m) % m;
int r = l + (1 << h) - 1;
k += kk[r];
if (l)
k -= kk[l - 1];
if ((a + a) % m >= 1 << h)
k--;
}
k /= 2;
if (k % 2)
ans ^= 1 << h;
}
cout << ans << '\n';
return 0;
}
