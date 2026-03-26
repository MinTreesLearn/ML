#include <bits/stdc++.h>
using namespace std;
#define cin(vec)      \
  for (auto &i : vec) \
  cin >> i
#define cout(vec)     \
  for (auto &i : vec) \
    cout << i << " "; \
  cout << "\n";
#define sz(x) int(x.size())
#define pb(x) push_back(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define fi first
#define se second
#define ll long long
#define Mod 1'000'000'007
#define PI acos(-1)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define EPS 1e-6
#define endl "\n"
#define OO INT_MAX

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
  for (auto &x : v)
    in >> x;
  return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
  for (const T &x : v)
    out << x << ' ';
  return out;
}

void Eman_Elsayed()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

int fn(double x, double d)
{
  return x + ceil(d / (x + 1));
}

bool Bs(ll n, ll d)
{
  ll l = 1, r = n;
  while (l <= r)
  {
    ll mid = (l + r) / 2;
    if (fn(mid, d) <= n)
      return true;
    else
      r = mid - 1;
  }
  return false;
}

void solve()
{
  ll n, s, k;
  cin >> n >> s >> k;
  vector<ll> v(k);
  map<ll, ll> closed;
  cin >> v;
  for (auto &i : v)
    closed[i] = true;
  for (int i = 0; i < n; i++)
  {
    if (s - i > 0 && closed[s - i] == false)
    {
      cout << i << endl;
      return;
    }
    if (s + i <= n && closed[s + i] == false)
    {
      cout << i << endl;
      return;
    }
  }
}

int main()
{
  Eman_Elsayed();
  int t = 1;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}