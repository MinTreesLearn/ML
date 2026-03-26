#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define u64 unsigned long long
#define ull unsigned long long
#ifdef LOCAL
#define __int128 long long
#endif // LOCAL
int flag;
ull memo[256][256];
ull mul(ull x,ull y,int k=64){
	if(k==flag)return memo[x][y];
	k/=2;
	ull a=x>>k;
	ull b=x^(a<<k);
	ull c=y>>k;
	ull d=y^(c<<k);
	ull bd=mul(b,d,k);
	ull ac=mul(a,c,k);
	ull abcd=mul(a^b,c^d,k);
	return (abcd^bd)<<k ^ mul(ac,1ULL<<(k-1),k) ^ bd;
}

void init(){
	flag=1;
	memo[1][1]=1;
	for(int i=0;i<256;i++)for(int j=0;j<256;j++)memo[i][j]=mul(i,j,8);
	flag=8;
}
u64 po(u64 a,u64 b)
{
    if(b==0) return 1;
    if(b==1) return a;
    if(!(b & 1)) {u64 u=po(a,b/2);return mul(u,u);}
    else {u64 u=po(a,b-1);return mul(a,u);}
}
template<typename T>
T extgcd(T a, T b, T &x, T &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  T p = b / a;
  T g = extgcd(b - p * a, a, y, x);
  x -= p * y;
  return g;
}

template<typename T>
bool diophantine(T a, T b, T c, T &x, T &y, T &g) {
  if (a == 0 && b == 0) {
    if (c == 0) {
      x = y = g = 0;
      return true;
    }
    return false;
  }
  if (a == 0) {
    if (c % b == 0) {
      x = 0;
      y = c / b;
      __int128 b1=b;
      g = (b1>0 ? b1 : -b1);
      return true;
    }
    return false;
  }
  if (b == 0) {
    if (c % a == 0) {
      x = c / a;
      y = 0;
      g =(a>0 ? a : -a);
      return true;
    }
    return false;
  }
  g = extgcd(a, b, x, y);
  if (c % g != 0) {
    return false;
  }
  T dx = c / a;
  c -= dx * a;
  T dy = c / b;
  c -= dy * b;
  x = dx + (T) ((__int128) x * (c / g) % b);
  y = dy + (T) ((__int128) y * (c / g) % a);
  __int128 g1=g;
  g = (g1>0 ? g1 : -g1);
  return true;
  // |x|, |y| <= max(|a|, |b|, |c|) [tested]
}

bool crt(__int128 k1, __int128 m1, __int128 k2, __int128 m2, __int128 &k, __int128 &m) {
  k1 %= m1;
  if (k1 < 0) k1 += m1;
  k2 %= m2;
  if (k2 < 0) k2 += m2;
  __int128 x, y, g;
  if (!diophantine(m1, -m2, k2 - k1, x, y, g)) {
    return false;
  }
  __int128 dx = m2 / g;
  __int128 delta = x / dx - (x % dx < 0);
  k = m1 * (x - dx * delta) + k1;
  m = m1 / g * m2;
  assert(0 <= k && k < m);
  return true;
}
u64 go(vector<u64> v1,vector<u64> v2)
{
    if(v1.size()==1) return v2[0];
    __int128 mod1=v1.back();__int128 u1=v2.back();
    v1.pop_back();v2.pop_back();
    __int128 mod2=v1.back();__int128 u2=v2.back();
    v1.pop_back();v2.pop_back();
    __int128 mod3=mod1*mod2;__int128 res3;
    crt(u1,mod1,u2,mod2,res3,mod3);
    v1.push_back(mod3);v2.push_back(res3);
    return go(v1,v2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int t;cin>>t;
    u64 h=(-1);
    vector<u64> v={3,5,17,257,641,65537,6700417};
    vector<u64> v1;
    while(t--)
    {
        v1.clear();
        u64 a,b;cin>>a>>b;
        u64 inva=po(a,-2);
        u64 res1=mul(a,inva);
        bool ok1=true;
        for(u64 mod:v)
        {
            u64 h=((u64) -1)/mod;
            vector<pair<u64,int> > u;
            int sq=sqrt(mod);
            u64 s=po(a,sq*h);
            u64 cur=1;
            for(int i=0;i<=(mod+sq-1)/sq;++i)
            {
                u.push_back({cur,i*sq});cur=mul(cur,s);
            }
            sort(u.begin(),u.end());
            cur=b;
            bool ok=false;
            for(u64 i=0;i<sq;++i)
            {
                u64 o=po(cur,h);
                int pos=lower_bound(u.begin(),u.end(),make_pair(o,(int) 0))-u.begin();
                if(pos==u.size() || u[pos].first!=o) {cur=mul(cur,inva);continue;}
                ok=true;v1.push_back((i+u[pos].second)%mod);break;
            }
            if(!ok) {ok1=false;cout<<(-1)<<'\n';break;}
        }
        if(ok1)
        {
            u64 res=go(v,v1);
            cout<<res<<'\n';
        }
    }
    return 0;
}
