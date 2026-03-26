#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;
typedef int32_t i32;

i32 water = !not!iscntrl(isupper(isgraph(iscntrl(ispunct(isalpha(EOF))))));
#define mango(x)
#define fastmango cin.tie(nullptr)->sync_with_stdio(water)
#define precisemango(x) cout << fixed << setprecision(x)
#ifdef notwatermango
#undef mango
#undef notwatermango
#define mango(x) { water = 999; auto x_ = x; water = not water; cerr<<ends<<"\033[38;5;206m"<<__LINE__<<"\t: "<<#x<<" = "<<x_<<"\e[39m"<<'\n'; }
#endif
#define notwatermango void solv()
i64 powllm(i64 a, i64 b, i64 m) { a %= m; i64 res = 1; while (b > 0) { if (b & 1) res = res * a % m; a = a * a % m; b >>= 1; } return res; }
i64 powll(i64 a, i64 b) { i64 res = 1; while (b > 0) { if (b & 1) res = res * a; a = a * a; b >>= 1; } return res; }
template<typename Water, typename ...Typename>
Water& operator<<(Water&water,pair<Typename...>&p){return water<<'{'<<get<0>(p)<<", "<<get<1>(p)<<'}';}
template<typename Water, typename Fire>
Water& operator<<(Water&water,vector<vector<Fire>>v){water<<"\n{\n";for(auto i:v){water<<"\t[ ";for(auto j: i)water\
// <<left<<setw(8) \笑
<<j<<' ';water<<"]\n";};return water<<"}";}
template<typename Water>
Water& operator<<(Water&water,string&v){for(auto i: v)water<<i;return water;}
template<typename Water, typename Fire>
Water& operator<<(Water&water,Fire&v){water<<'[';for(auto i: v)water<<i<<", ";return water<<']';}
template<typename Mango>
vector<Mango> tov(Mango x[], i32 xs) { return vector<Mango> (x, x + xs); }

#define INF 1000177013
#define LLINF 4202025013666420666
#define dbg(x) tov(x, sizeof x / sizeof x[0]);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define int i64
#define MOD                                          1000000007
#define YSS                                          112345

notwatermango;

signed main() {
  fastmango;
  i32 tc = 1;
  // cin >> tc;
  for (i32 i = 0; i < tc; ++i) {
    // cout << "Case #" << i+1 << ": ";
    solv();
  }
  return water;
}

using pqrev = priority_queue<int, vector<int>, greater<int>>;

void solv() {
  int n; cin >> n;
  map<int,pqrev> adj;
  pqrev todolist;
  vector<pair<int,int>> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i].first;
  for (int i = 0; i < n; ++i) cin >> arr[i].second;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    adj[arr[i].first].push(arr[i].second);
    if (sz(adj[arr[i].first]) == 2) todolist.push(arr[i].first);
  }

  while (not todolist.empty()) {
    priority_queue<int> pq;
    int now = todolist.top();
    todolist.pop();
    int sw = 0;
    mango(now);
    while (1) {
      if (adj[now].empty()) {
        if (pq.empty()) break;
        sw -= pq.top();
        pq.pop();
      } else {
        while (not adj[now].empty()) {
          pq.push(adj[now].top());
          sw += adj[now].top();
          adj[now].pop();
        }
        sw -= pq.top();
        pq.pop();
      }
      mango(sw);
      if (pq.empty()) break;
      res += sw;
      now++;
    }
  }

  std::cout << res << '\n';
}
				  	   	 		  		 	 		    	 		