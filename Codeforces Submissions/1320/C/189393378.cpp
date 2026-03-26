#include <bits/stdc++.h>
 //#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/extc++.h>
typedef long long ll;
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(a) (a).begin(), (a).end()
#define clr(a, h) memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define forr(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define deb(x) cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x) (int) x.size()
#define endl '\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < ll > vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int INF = 1e17;
const double PI = acos(-1);

const int tam = 1e6 + 10;

int weapon[tam];
int armor[tam];

const int maxN = 2e5 + 10;

struct node {
  int val, lazy;
  node() {
    val = lazy = 0;
  }
  node(int v, int l) {
    val = v;
    lazy = l;
  }
  void join(node a, node b) {
    val = max(a.val, b.val);
  }
};

node t[4*tam];

#define index int l = 2*nodo+1, r = l+1, mid = (b+e)/2;

void propagate(int b, int e, int nodo) {
  if (t[nodo].lazy == 0) return;
  t[nodo].val += t[nodo].lazy;
  index;
  if (b != e) {
    t[l].lazy += t[nodo].lazy;
    t[r].lazy += t[nodo].lazy;
  }
  t[nodo].lazy = 0;
}

void update(int b, int e, int nodo, int i, int j, int val) {
  propagate(b, e, nodo);
  if (b > j || e < i) return;
  if (b >= i && e <= j) {
    t[nodo].lazy += val;
    propagate(b, e, nodo);
    return;
  }
  index;
  update(b, mid, l, i, j, val);
  update(mid + 1, e, r, i, j, val);
  t[nodo].join(t[l], t[r]);
}

node query(int b, int e, int nodo, int i, int j) {
  propagate(b, e, nodo);
  if (b > j || e < i) return node(-INF, 0);
  if (b >= i && e <= j) return t[nodo];
  index;
  node a = query(b, mid, l, i, j);
  node c = query(mid + 1, e, r, i, j);
  node ans;
  ans.join(a, c);
  return ans;
}

inline void update(int l, int r, int val) {
  update(0, tam-1, 0, l, r, val);
}

inline node query(int l, int r) {
  return query(0, tam-1, 0, l, r);
}

signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  //freopen("","r",stdin);
  //freopen("","w",stdout);
  fore(i, 0, tam) weapon[i] = armor[i] = INF;
  int n, m, p;
  cin >> n >> m >> p;
  fore(i, 0, n) {
    int a, b;
    cin >> a >> b;
    weapon[a] = min(weapon[a], b);
  }
  fore(i, 0, m) {
    int a, b;
    cin >> a >> b;
    armor[a] = min(armor[a], b);
  }
  for (int i = tam-1; i >= 0; --i) {
    if (i + 1 < tam) {
      weapon[i] = min(weapon[i], weapon[i + 1]);
      armor[i] = min(armor[i], armor[i + 1]);
    }
    if (i+1 < tam) update(i, i, - weapon[i+1]);
    else update(i, i, -INF);
  }
  int ans = - weapon[0] - armor[0];
  vector<pair<ii, ii>> vals;
  fore(i, 0, p) {
    int a, b, c;
    cin >> a >> b >> c;
    vals.pb({{a, b}, {c, i}});
  }
  sort(all(vals), [](pair<ii, ii> a, pair<ii, ii> b) {
    return mp(a.F.S, a.F.F) < mp(b.F.S, b.F.F);
  });
  // fore(i, 0, p) vals[i].S.S = i;
  // sort(all(vals), [](pair<ii, ii> a, pair<ii, ii> b) {
  //   return a.F < b.F;
  // });
  fore(i, 0, p) {
    int pos = vals[i].S.S;
    int val = vals[i].S.F;
    int x = vals[i].F.F;
    int y = vals[i].F.S;
    update(x, tam-1, val);
    ans = max(ans, query(0, tam-1).val - armor[y+1]);
    // cerr << x << " " << y << " " << ans << endl;
  }
  cout << ans << endl;
  return 0;
}
// Dinosaurs