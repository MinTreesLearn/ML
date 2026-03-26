//श्रमं विना न किमपि साध्यम्
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(a) (a).begin(),(a).end()
#define rev(p) reverse(p.begin(),p.end());
#define v vector 
#define sortt(a) sort(all(a)) 
#define pll pair<ll,ll>
#define sz(c) (int)c.size()
#define fr first
#define sc second
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define rep(i,a,n) for(int i=a ; i<n ; i++)
#define pi (2*acos(0.0))
#define F(a,b,i) for(int i=a;i<b;i++)
#define FN(a,b,i) for(int i=a-1;i>=b;i--)
#define endl "\n"
//*****DEBUG FUNCTIONS********// 
#ifndef ONLINE_JUDGE
template<typename T>void __p(std::vector<T> v);
template<typename T>void __p(T a){cout<<a;}
template<typename T, typename F>void __p(pair<T, F> a){cout<<"{";__p(a.first);cout<<",";__p(a.second);cout<<"}";}
template<typename T>void __p(std::vector<T> a) {cout<<"{";for(auto it=a.begin(); it<a.end(); it++)__p(*it),cout<<",}"[it+1==a.end()];}
template<typename T>void __p(std::set<T> a){cout<<"{";for(auto it=a.begin(); it!=a.end();){__p(*it); cout<<",}"[++it==a.end()];}}
template<typename T>void __p(std::multiset<T> a){cout<<"{";for(auto it=a.begin(); it!=a.end();){__p(*it); cout<<",}"[++it==a.end()];}}
template<typename T, typename F>void __p(std::map<T,F> a){cout<<"{\n";for(auto it=a.begin(); it!=a.end();++it){__p(it->first);cout << ": ";__p(it->second);cout<<"\n";}cout << "}\n";}
template<typename T, typename ...Arg>void __p(T a1, Arg ...a){__p(a1);__p(a...);}
template<typename Arg1>void __f(const char *name, Arg1 &&arg1){cout<<name<<" : ";__p(arg1);cout<<endl;}
template<typename Arg1, typename ... Args>void __f(const char *names, Arg1 &&arg1, Args &&... args) {int bracket=0,i=0;for(;; i++)if(names[i]==','&&bracket==0)break;else if(names[i]=='(')bracket++;else if(names[i]==')')bracket--;const char *comma=names+i;cout.write(names,comma-names)<<" : ";__p(arg1);cout<<" | ";__f(comma+1,args...);}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#define error(...)
#endif
//*****DEBUG FUNCTIONS********//
ll inf =1e18;
ll mod1 = 1e9 + 7;
ll mod2=998244353;
ll log2n(ll n) // floor of(log2 n) , log2 (13)=3 
{
  //FAILS FOR N=0
  if(n==0)return 0;
  return (63-__builtin_clzll(n));
}
bool is_prime( ll n)
{
  if(n==1)return false;
  ll i=2;
  for(i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      return false;
    }
  }
  return true;
}
ll power(ll x, ll y, ll p)
{
    x = x % p;
    if(x==0)return 0;
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll pwr(ll x, ll y){if(x==0)return 0;ll res = 1;x = x ;while (y > 0){if (y & 1)res = (res * x);y = y >> 1;x = (x * x) ;}return res;}
ll modInverse(ll n, ll p){return power(n, p - 2, p);}
ll ncr(ll n, ll r , ll modd){if(r>n){return 0;}
    if(r>n-r){r = n-r;}ll ans = 1;
    for(ll i = 1; i<=r ; i++){
        ans *= (n-i+1);ans%= modd;ans *= modInverse(i, modd);ans %= modd;}
 return ans;}
ll _gcd(ll a, ll b){ if (b == 0) return a; return _gcd(b, a % b);}
//********CLOCK********
ll begtime = clock();
#define time() cerr << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//********CLOCK********
ll testctr;
const int N=2e6+5;



void solve()
{
  
  ll i, j , t1 , t2 , t3 ,t4 , flag;
  //ARE YOU REALLY SURE()?
  //chckdstc?
  //MXMN?BSPZL
  //order_1e18?overflow!!!
  
  

  ll n,q; cin>>n>>q;
  set<pll>sp1;
  bool ans=1;
  set<v<ll>>diff;
  while(q--)
  {
    cin>>t1>>t2;
    t1--;t2--;
    t3=t1^1;
    //
    if(sp1.count(mp(t1,t2)))
    {
      //already in
      //pres dele
      for(j=max(t2-1,0ll);j<=min(t2+1,n-1);j++)
      {
        v<ll>v1={t3,j,t1,t2};
        v<ll>v2={t1,t2,t3,j};
        if(diff.count(v1))diff.erase(v1);
        if(diff.count(v2))diff.erase(v2);
      }
      sp1.erase(mp(t1,t2));
    }
    else
    {
      for(j=max(t2-1,0ll);j<=min(t2+1,n-1);j++)
      {
        //not there 
        //insert
        if(sp1.count(mp(t3,j)))
        {
          v<ll>v1={t3,j,t1,t2};
          diff.insert(v1);
        }
      }
      sp1.insert(mp(t1,t2));

    }
    if(sz(diff))
    {
      cout<<"No\n";
    }
    else
    {
      cout<<"Yes\n";
    }
  }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
  cout<<fixed<<setprecision(20);
  ll TESTS;
  //cin>>TESTS;
  TESTS=1;
  for(int i=1;i<=TESTS;i++)
  { 
    testctr=i;
    // cout<<"Case #"<<i<<":"<<" ";
    solve();
  }
  time();
  return 0;
}