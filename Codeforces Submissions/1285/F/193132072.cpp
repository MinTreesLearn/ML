// LUOGU_RID: 101881164
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#include <bits/stdc++.h>

using namespace std;

mt19937 gen(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution <> dist(1, 1e9);

const int N = 1e5 + 10;
struct Node
{
  int x;
  long long val;
  Node()
  {
    x = val = 0;
  }
  bool operator<(const Node &rhs) const
  {
    return val > rhs.val;
  }
} a[N];
int rnd[N];

long long lcm(int a, int b)
{
  return 1ll * b * a / __gcd(a, b);
}

signed main()
{
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++ i)
    scanf("%d", &a[i]);
  if (n <= 2500)
  {
    long long ans = 0;
    for (int i = 1; i <= n; ++ i)
      for (int j = 1; j <= n; ++ j)
        ans = max(ans, lcm(a[i].x, a[j].x));
    cout << ans << '\n';
  }
  else
  {
    for (int i = 1; i <= 35; ++ i)
      rnd[i] = dist(gen) % n + 1;
    for (int i = 1; i <= n; ++ i)
      for (int j = 1; j <= 35; ++ j)
        a[i].val = max(a[i].val, lcm(a[i].x, a[rnd[j]].x));
    sort (a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 1; i <= 18; ++ i)
      for (int j = 1; j <= n; j ++)
        ans = max(ans, lcm(a[i].x, a[j].x));
    for (int i = 1; i <= 1400; ++ i)
      for (int j = 1; j <= 1400; ++ j)
        ans = max(ans, lcm(a[i].x, a[j].x));
    cout << ans << '\n';
  }
  return 0;
}
