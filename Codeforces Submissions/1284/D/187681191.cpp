#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define f first
#define s second
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz(v) int(v.size())
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> T mod(T a, T mod = MOD){ a %= mod; if (a<0) a += mod; return a; }
template <typename T> T add(T a, T b, T mod = MOD){ return (a+b)%mod; }
template <typename T> T sub(T a, T b, T mod = MOD){ return (a-b+mod)%mod; };
template <typename T> T mul(T a, T b, T mod = MOD){ return (a * 1ll * b) % mod; }
template <typename T> T binPow(T a, T b, T mod = MOD){ T res = 1; while (b>0){ if (b&1) res = mul<T>(res, a, mod); a = mul<T>(a,a, mod); b >>= 1; } return res; }
template <typename T> T binPowNoMod(T a, T b){ T res = 1; while (b>0){ if (b&1) res *= a; a *= a; b >>= 1; } return res; }
template <typename T> T divMod(T a, T b, T mod = MOD){ return mul(a, binPow(b, mod-2, mod), mod); }

const ld ep = 0.0000001;
const ld pi = acos(-1.0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
class LazySegTree{
  vector<T> t, lazy, len;
public:
  int n;
  LazySegTree(vector<T> &a){
    n = int(a.size());
    t.resize(4*n);
    lazy.resize(4*n);
    len.resize(4*n);
    build(a);
  }
  
  void build(vector<T> &a){
    build(a, 0, n-1, 1);
  }
  
  void update(int x, int y, T diff){
    update(0, n-1, 1, x, y, diff);
  }
  
  T query(int l, int r){
    return query(0, n-1, 1, l, r);
  }
  
private:
  T merge(T x, T y){
    return max(x,y);
  }
  
  T default_val() {
    return 0;
  }
  
  void push(int i){
    t[2*i] = max(t[2*i],lazy[i]);
    t[2*i+1] = max(t[2*i+1],lazy[i]);
    
    lazy[2*i] = max(lazy[2*i],lazy[i]);
    lazy[2*i+1] = max(lazy[2*i+1],lazy[i]);
    
    lazy[i] = 0;
  }
  
  void build(vector<T> &a, int l, int r, int i){
    if (l==r){
      t[i] = a[l];
      len[i] = 1;
      return;
    }
    int mid = l+(r-l)/2;
    build(a,l,mid,2*i);
    build(a,mid+1,r,2*i+1);
    t[i] = merge(t[2*i],t[2*i+1]);
    len[i] = 1;
  }
  
  void update(int l, int r, int i, int x, int y, T diff){
    if (x>y) return;
    if (x==l && r==y){
      t[i] = max(t[i],diff*len[i]);
      lazy[i] = max(lazy[i],diff);
      return;
    }
    push(i);
    int mid = l+(r-l)/2;
    update(l, mid, 2*i, x, min(y,mid), diff);
    update(mid+1, r, 2*i+1, max(x,mid+1), y, diff);
    t[i] = merge(t[2*i], t[2*i+1]);
  }
  
  T query(int l, int r, int i, int x, int y){
    if (x>y) return default_val();
    if (x<=l && r<=y) {
      return t[i];
    }
    push(i);
    int mid = l+(r-l)/2;
    return merge(query(l, mid, 2*i, x, min(y,mid)), query(mid+1, r, 2*i+1, max(x,mid+1), y));
  }
};

bool solve(vector<vector<int>>& a, int __cnt=1){
  int n = sz(a);
  if (__cnt>2) return false;
  
  // coords comp
  map<int,int> mp;
  rep(i,0,n){
    rep(j,0,4){
      mp[a[i][j]] = 0;
    }
  }
  
  int __cc = 0;
  for (auto it: mp) mp[it.f] = __cc++;
  
  rep(i,0,n){
    rep(j,0,4){
      a[i][j] = mp[a[i][j]];
    }
  }
  
  vector<int> tmp(__cc+5);
  LazySegTree<int> st(tmp);
  
  rep(i,0,n){
    int left_b = a[i][2];
    
    st.update(a[i][0],a[i][1],left_b);
  }
  
  rep(i,0,n){
    int mx_left = st.query(a[i][0],a[i][1]);
    if (mx_left > a[i][3]) {
      return true;
    }
  }
  
  rep(i,0,n){
    swap(a[i][0],a[i][2]);
    swap(a[i][1],a[i][3]);
  }
  
  return solve(a,__cnt+1);
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t=1;
//  cin>>t;
  
  int n;
  cin>>n;
  
  vector<vector<int>> a(n);
  rep(i,0,n){
    a[i].resize(4);
    rep(j,0,4) cin>>a[i][j];
  }
    
  for (int i=0;i<t;i++){
    cout<<(solve(a) ? "NO":"YES")<<"\n";
  }
  
  return 0;
}
