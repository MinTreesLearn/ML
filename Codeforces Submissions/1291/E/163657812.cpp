#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1<<30;
const ll inf = 1LL<<60;


struct UnionFind {
   vector<int> par;
   vector<int> sz;
   int ans = 0;
   vector<int> num[2], col;
   int fix;

   UnionFind(int n, vector<int> col):col(col){
       par.resize(n);
       sz.assign(n, 1);
       for(int k=0; k<2; k++) num[k].resize(n);
       fix = n-1;
       for(int i=0; i<n; i++){
           par[i] = i;
           num[col[i]][i]++;
       }
   }

   int find(int x){
       if(par[x] == x){
           return x;
       }else{
           return par[x] = find(par[x]);
       }
   }

   int calc(int x){
       x = find(x);
       if(same(x, fix)){
           return num[1][x];
       }else{
           return min(num[0][x], num[1][x]);
       }
   }

   bool unite(int x, int y){
       x = find(x), y = find(y);
       if(x == y) return false;
       if(sz[x] > sz[y]) swap(x, y);

       ans -= calc(x) + calc(y);
       par[x] = y;
       sz[y] += sz[x];
       for(int k=0; k<2; k++) num[k][y] += num[k][x];
       ans += calc(y);
       return true;
   }

   bool same(int x, int y){ return find(x) == find(y); }
   int size(int x){ return sz[find(x)]; }
};

void solve() {
  int N, K; cin >> N >> K;
  string str; cin >> str;
  vector<int> A(N);
  for (int i=0; i<N; i++) A[i] = str[i] - '0';
  vector<vector<int>> G(N);
  for (int i=0; i<K; i++) {
    int c; cin >> c;
    while (c--) {
      int a; cin >> a; a--;
      G[a].emplace_back(i);
    }
  }
  vector<pair<int, int>> edges[300001];
  for (int i=0; i<N; i++) if (G[i].size()) {
    if (G[i].size() == 1) G[i].emplace_back(K);
    int a = G[i][0], b = G[i][1], c = 1^A[i];
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }
  vector<int> col(K+1, -1);
  auto dfs = [&](auto&& dfs, int i) -> void {
    for (auto& e : edges[i]) if (col[e.first] == -1) {
      col[e.first] = col[i]^(e.second);
      dfs(dfs, e.first);
    }
  };
  for (int i=K; i>=0; i--) if (col[i] == -1) {
    col[i] = 0;
    dfs(dfs, i);
  }
  UnionFind uf(K+1, col);
  for (int i=0; i<N; i++) {
    if (G[i].size()) uf.unite(G[i][0], G[i][1]);
    cout << uf.ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // int t; cin >> t;
  /*while (t--)*/ solve();
}
