#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define MASK(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 20
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FU(i, a, b) for(int i=a; i<=b; i++)
#define FD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, x) for(int i=0; i<x; i++)
#define REPD(i, x) for(int i=x-1; i>=0; i--)
const int MAX = 2e5 + 5;
const int mod = 1e9 + 7;
const int base = 31;
const int INF = 1e9 + 7;
typedef pair<int, int> ii;

#define task "long"
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    else if (fopen(task".in", "r"))
    {
       freopen(task".in", "r", stdin);
       freopen(task".out", "w", stdout);
    }
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]={0,1,0,-1,1,1,-1,-1};
int dy[]={1,0,-1,0,1,-1,1,-1};
template<class X, class Y> bool maximize(X &x, Y y){ if (x < y) {x = y; return true;} return false;};
template<class X, class Y> bool minimize(X &x, Y y){ if (x > y) {x = y; return true;} return false;};
void add(int &x, int y) { x += y; if (x>=mod) x-=mod;}
void sub(int &x, int y) { x -= y; if (x<0) x+=mod;}
int mul(int x, int y) {return 1LL * x * y % mod;}
int calPw(int x, int y)
{
    int ans = 1;
    while(y)
    {
        if (y&1) ans = 1LL * ans * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return ans;
}
int n;
int mx[MAX], sum[MAX];
int S[MAX];
ii a[MAX];
void read()
{
   cin >> n;
   FU(i, 1, n) cin >> a[i].fi >> a[i].se;
}
int bs(int x, int sz)
{
   int l = 1, r = sz, ans = 0;
   while(l <= r)
   {
      int mid = (l + r) >> 1;
      if (S[mid] > x)
      {
         ans = mid;
         l = mid + 1;
      }
      else r = mid - 1;
   }
   return ans;
}
void sol()
{
   sort(a+1, a+n+1);
   memset(mx, 0, sizeof mx); mx[0] = -INF; sum[0] = 0;
   FU(i, 1, n)
   {
      sum[i] = sum[i-1] + (a[i].fi > mx[i-1]);
      mx[i] = max(mx[i-1], a[i].se);
   }
   int ans = 0, sz = 0;
   FD(i, n, 1)
   {
      int pos = bs(mx[i-1], sz);
      ans = max(ans, sum[i-1] + pos);
      while(sz && a[i].se >= S[sz]) --sz;
      S[++sz] = a[i].fi;
   }
   cout << ans, EL;
}
signed main()
{
    fastio();
    init();
    int TEST = 1;
    cin >> TEST;
    while(TEST--)
    {
        read();
        sol();
    }
}
