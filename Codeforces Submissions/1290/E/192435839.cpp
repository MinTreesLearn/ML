#include <bits/stdc++.h>
#define st first
#define nd second
#define db double
#define re register
#define pb push_back
#define mk make_pair
#define int long long
#define ldb long double
#define pii pair<int, int>
#define ull unsigned long long
#define mst(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 2e5 + 10;
inline int read()
{
  int s = 0, w = 1;
  char ch = getchar();
  while(ch < '0' || ch > '9') { if(ch == '-') w *= -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
int n, a[N], p[N], ans[N];
#define ls k << 1
#define rs k << 1 | 1
#define mid ((l + r) >> 1)
struct SegmentTree{
  int c[N << 2], v[N << 2], s[N << 2], tr[N << 2];
  int len[N << 2], lens[N << 2], tag[N << 2], tags[N << 2];
  inline void pushup(int k){
    c[k] = c[ls] + c[rs], len[k] = len[ls] + len[rs], tr[k] = tr[ls] + tr[rs];
    if(v[ls] > v[rs]){
      v[k] = v[ls], s[k] = max(s[ls], v[rs]);
      len[k] = len[ls], lens[k] = lens[ls] + len[rs] + lens[rs];
    } else if(v[ls] < v[rs]){
      v[k] = v[rs], s[k] = max(v[ls], s[rs]);
      len[k] = len[rs], lens[k] = lens[rs] + len[ls] + lens[ls];
    } else{
      v[k] = v[ls], s[k] = max(s[ls], s[rs]);
      len[k] = len[ls] + len[rs], lens[k] = lens[rs] + lens[ls];
    }
  }
  inline void build(int k, int l, int r){
    c[k] = v[k] = s[k] = tr[k] = len[k] = lens[k] = tag[k] = tags[k] = 0;
    if(l == r) return;
    build(ls, l, mid), build(rs, mid + 1, r);
  }
  inline void Addtag(int k, int x, int y, int op){
    if(!op) x = y;
    v[k] += x, tag[k] += x, s[k] += y, tags[k] += y, tr[k] += x * len[k] + y * lens[k];
  }
  inline void pushdown(int k){
    if(!tag[k] && !tags[k]) return;
    int tem = v[rs] >= v[ls];
    Addtag(ls, tag[k], tags[k], v[ls] >= v[rs]), Addtag(rs, tag[k], tags[k], tem);
    tag[k] = tags[k] = 0;
  }
  inline int query(int k, int l, int r, int x, int y){
    if(y < l || x > r) return 0;
    if(l >= x && r <= y) { Addtag(k, 1, 1, 1); return c[k]; }
    pushdown(k);
    int res = query(ls, l, mid, x, y) + query(rs, mid + 1, r, x, y);
    pushup(k);
    return res;
  }
  inline void modify(int k, int l, int r, int x, int t) {
    if(l == r && l == x) { tr[k] = v[k] = t, len[k] = c[k] = 1; return; }
    pushdown(k);
    if(x <= mid) modify(ls, l, mid, x, t);
    else modify(rs, mid + 1, r, x, t);
    pushup(k);
  }
  inline void update(int k, int l, int r, int x, int y, int t) {
    if(y < l || x > r || t >= v[k]) return;
    if(l >= x && r <= y && t > s[k]) { Addtag(k, min(t - v[k], 0ll), 0, 1); return; }
    pushdown(k), update(ls, l, mid, x, y, t), update(rs, mid + 1, r, x, y, t), pushup(k);
   // cout << "k: " << tr[k] << "\n";
  }
}T;

signed main()
{
  n = read();
  for(re int i = 1; i <= n; i++) a[i] = read(), p[a[i]] = i;
  for(re int t = 1; t <= 2; t++){
   // cout << "Begin: " << t << "\n";
    T.build(1, 1, n);
    for(re int i = 1, x; i <= n; i++){
      x = T.query(1, 1, n, p[i] + 1, n), T.modify(1, 1, n, p[i], i + 1);
      //cout << "pos: " << x << "\n";
      T.update(1, 1, n, 1, p[i] - 1, i - x), ans[i] += T.tr[1];
      
    }
    for(re int i = 1; i <= n; i++) p[i] = n - p[i] + 1;
  }
 // puts("");
  for(re int i = 1; i <= n; i++) printf("%lld\n", ans[i] - i * (i + 2));
  return 0;
}
		  			  	 	 	   	 	 				  	 		