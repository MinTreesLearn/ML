#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define ld double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define line cout << '\n'

#define sz(v) ((int)(v).size())
const double pi = 3.1415926535897932384626433832795;

const long long mod = 998244353;
const long long inf = 9099999999999999999;
const long long nmax = 2e5 + 100;
const long double eps = 1e-9;

// random_device rd;
// mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int MAGIC = rnd();

vector<vector<int>> g(nmax), gr(nmax);

vector<int> d(nmax, inf);

void bfs(int s) {
  queue<int> q;
  vector<bool> used(nmax, false);
  used[s] = true;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (auto to : gr[v]) {
      if (!used[to]) {
        used[to] = true;
        d[to] = d[v] + 1;
        q.push(to);
      }
    }
  }
}

void runtimeerror() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    gr[v].push_back(u);
  }

  int k;
  cin >> k;
  vector<int> arr(k);
  for (int i = 0; i < k; i++)
    cin >> arr[i];

  int ansmn = 0, ansmx = 0;

  bfs(arr[k - 1]);

  for (int i = 0; i < k - 1; i++) {
    int f = 0;
    for (auto to : g[arr[i]]) {
      if (to != arr[i + 1]) {
        if (d[to] == d[arr[i]] - 1) {
          f++;
        }
      }
    }
    if (f > 0 || d[arr[i + 1]] > d[arr[i]] - 1)
      ansmx++;
    if (d[arr[i + 1]] > d[arr[i]] - 1)
      ansmn++;
  }

  cout << ansmn << ' ' << ansmx;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  //    freopen("C:/Users/tmazi/Downloads/27_B.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  ll t = 1;
  //      cin >> t;
  while (t--)
    runtimeerror();

  //  cout << "WINNER";
  // i'm stupid man
}