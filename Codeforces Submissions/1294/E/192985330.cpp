#include <bits/stdc++.h>

int main() {
int n, m; scanf("%d%d", &n, &m);
int a{n * m}, C[a]{};
for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
int x; scanf("%d", &x);
if (--x % m == j and x < a)
C[j * n + (i - x / m + n) % n]--;
C[j * n + i] += i;
}
for (int k = 0; k < n * m; k += n)
a += *std::min_element(C + k, C + k + n);
printf("%d", a);
}