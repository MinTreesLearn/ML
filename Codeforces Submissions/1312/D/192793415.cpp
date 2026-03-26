#include<bits/stdc++.h>

using namespace std;

const int MOD=998244353;

int main()
{
int n, m, k; long long t, u = 1;
if (cin >> n >> m, k = n-2, k == 0)
cout << 0, exit(0);
for (t = k; k > 1; --k)
t <<= 1, t %= MOD;
for (k = m-n+1; m > k; --m)
t *= m, t %= MOD;
for (k = 2; k < n; ++k)
u *= k, u %= MOD;
for (k = MOD-2; k > 0; k >>= 1, u *= u, u %= MOD)
if (k&1)
t *= u, t %= MOD;
cout << t;
return 0;
}