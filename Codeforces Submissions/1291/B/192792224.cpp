#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int T, n, a[N];
int main () {
scanf ("%d", &T);
while (T --) {
scanf ("%d", &n);
for (int i = 1; i <= n; i ++)
scanf ("%d", &a[i]);
int l = 1, r = n;
while (a[l + 1] >= l)
l ++;
while (a[r - 1] >= n - r + 1)
r --;
if (l >= r)
puts ("Yes");
else
puts ("No");
}
return 0;
}
