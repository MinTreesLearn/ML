#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;

#define PB push_back
#define MP make_pair
// Common memset settings
//memset(memo, -1, sizeof memo); // dp memoization with -1
//memset(arr, 0, sizeof arr); //clear array of integers


struct unionFind {
  vector<int> parrent;
  vector<int> size;
  void init(int n) {
    parrent.assign(n, 0);
    size.assign(n, 0);
    for(int i = 0;i<n;i++) {
      parrent[i] = i;
      size[i] = 1;
    }
  }

  int get(int a) {
    if(parrent[a] != a) {
      parrent[a] = get(parrent[a]);
    }
    return parrent[a];
  }

  void unionFun(int a, int b) {
    a = get(a);
    b = get(b);

    if(a == b) {
      return;
    }
    if(size[a] > size[b]) {
      swap(a,b);
    }
    parrent[a] = b;
    size[b] += size[a];
  }
};

struct segtree {
  vector<long long> tree;
  int size;
  void init(int n) {
    size = 1;
    while(size < n) {
      size *= 2;
    }
    tree.assign(size*2 - 1, 0);
  }

  void build(vector<int> &a, int x, int lx, int rx) {
    if(rx - lx == 1) {
      if(lx < a.size())
        tree[x] = a[lx];
    } else {
      int m = (lx + rx)/2;
      build(a, 2*x + 1, lx, m);
      build(a, 2*x + 2, m, rx);
      tree[x] = tree[2*x + 1] + tree[2*x + 2];
    }
  }

  void build(vector<int> &a) {
    init(a.size());
    build(a,0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if(rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx)/2;
    if(i < m) {
      set(i, v, 2*x + 1, lx, m);
    } else {
      set(i, v, 2*x + 2, m, rx);
    }
    tree[x] = tree[2*x + 1] + tree[2*x + 2];
  }
  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  long long sum(int l, int r, int x, int lx, int rx) {
    if(l >= rx || lx >= r) {
      return 0;
    }
    if(lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx)/2;
    long long s1 = sum(l, r, 2*x + 1, lx, m);
    long long s2 = sum(l, r, 2*x + 2, m, rx);
    return s1 + s2;
  }

  long long sum(int l, int r){
    return sum(l, r, 0, 0, size);
  }
};

struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x) return x < p.x;
    else return y < p.y;
  }
};

void subsetGenerate(int n){
  for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
      if (b&(1<<i)) subset.push_back(i);
    }
  }
}

void permutationGenerate(int n){
  vector<int> permutation;
  for (int i = 0; i < n; i++) {
    permutation.push_back(i);
  }
  do {
  // process permutation
  } while (next_permutation(permutation.begin(),permutation.end()));
}

bool customSort(int a, int b) {
  return a < b;
}

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization("unroll-loops")
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  //string s
  //getline(cin, s);
  //printf("%.9f\n", x);
  
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> odds;
    for(int i=0;i<n;i++){
      if((s[i] - '0')%2) {
        odds.push_back(s[i] - '0');
      }
    }
    if(odds.size() < 2){
      cout << -1 << endl;
    } else {
      cout << odds[0] << odds[1] << endl;
    }
  }

  return 0;
}