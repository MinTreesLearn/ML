#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define itr(...) begin(__VA_ARGS__), end(__VA_ARGS__)
#define fastIO()                                                               \
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define debug(x...)                                                            \
  do {                                                                         \
    cout << "\033[32;1m" << #x << " -> ";                                      \
    rd_debug(x);                                                               \
  } while (0)
void rd_debug() { cout << "\033[39;0m" << endl; }
template <class T, class... Ts> void rd_debug(const T &arg, const Ts &...args) {
  cout << arg << " ";
  rd_debug(args...);
}
#define pb push_back
#define PF(x) ((x) * (x))
#define LF(x) ((x)*PF(x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const double eps = 1e-6;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3fll;

int main() {
  fastIO();
  int n;
  cin >> n;
  vector<PII> arr(n);
  for (auto &it : arr)
    cin >> it.first;
  for (auto &it : arr)
    cin >> it.second;
  sort(itr(arr));
  priority_queue<int> pq;
  map<int, vector<int>> mp;
  for(auto& it: arr){
    mp[it.first].push_back(it.second);
  }
  ll ans = 0;
  ll sum = 0;
  int cur = -1;
  for(auto& [k, vec]: mp){
    while(!pq.empty() and cur < k){
      sum -= pq.top();
      ans += sum;
      pq.pop();
      ++cur;
    }
    cur = max(cur, k);
    for(auto& it: vec){
      pq.push(it);
      sum += it;
    }
  }
  while (!pq.empty()) {
    sum -= pq.top();
    ans += sum;
    
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}
