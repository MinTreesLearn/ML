/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
const int N = 2e5 + 5;
const int inf = 1e18;
int mod = 1e9 + 7;
int power(int a, int b)
{
  int ans = 1;
  while (b > 0)
  {
    if (b & 1)
    {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}

// vector<int> c(N), dp(N), ans(N), g[N];
int n;
vector<int> a;
vector<vector<int>> gr;

void dfs1(int u, int p)
{
  for (int v : gr[u])
  {
    if (v != p)
    {
      dfs1(v, u);
      a[u] += max(0ll, a[v]);
    }
  }
}
void dfs2(int u, int p)
{
  for (int v : gr[u])
  {
    if (v != p)
    {
      a[v] += max(0ll, a[u] - max(0ll, a[v]));
      dfs2(v, u);
    }
  }
}

void solve()
{
  cin >> n;
  a.resize(n);
  gr.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    if (a[i] == 0)
      a[i] = -1;
  }
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs1(0, -1);
  dfs2(0, -1);
  for (int i = 0; i < n; i++)
    cout << a[i] << " \n"[i == n - 1];
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  // #endif
  int t = 1;
  // cin >> t;
  while (t--)
    solve();

  return 0;
}
