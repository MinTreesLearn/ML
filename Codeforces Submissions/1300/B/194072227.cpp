#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define vvll vector<vector<ll>>
#define all(v) v.begin(),v.end()
#define vvc vector<vector<char>>
#define vss vector<string>
#define emp emplace
#define pb push_back
#define pf push_front
#define dq deque
#define llmn LONG_LONG_MIN
#define llmx LONG_LONG_MAX
#define umll unordered_map<ll>
#define mll map<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define vll vector<ll> 
#define vpll vector<pair<ll,ll>> 
#define pll pair<ll,ll> 
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(i,a,b) for(ll i=a;i<b;++i)
#define rev(i,a,b) for(ll i=a;i>=b;--i)
#define tr(it,m) for(auto it:m)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int M=998244353;
long long mod(long long x)
{
return ((x%M + M)%M);
}
long long add(long long a, long long b)
{
return mod(mod(a)+mod(b));
}
long long mul(long long a, long long b)
{
return mod(mod(a)*mod(b));
}
 
using namespace std;
 
// this is mod exp
ll modexp(ll a, ll b)
{
ll ans=1;
while(b>0){
if((b%2)==1){
ans=mul(ans,a);
}
a=mul(a,a);
b/=2;
}
return ans;
}
// this is disjointset 
class DisjointSet {
vector<int> rank, parent, size;
public: 
DisjointSet(int n) {
rank.resize(n+1, 0);
parent.resize(n+1);
size.resize(n+1);
for(int i = 0;i<=n;i++) {
parent[i] = i; 
size[i] = 1; 
}
}
int findUPar(int node) {
if(node == parent[node])
return node;
return parent[node] = findUPar(parent[node]);
}
void unionByRank(int u, int v) {
int ulp_u = findUPar(u);
int ulp_v = findUPar(v);
if(ulp_u == ulp_v) return;
if(rank[ulp_u] < rank[ulp_v]) {
parent[ulp_u] = ulp_v;
}
else if(rank[ulp_v] < rank[ulp_u]) {
parent[ulp_v] = ulp_u; 
}
else {
parent[ulp_v] = ulp_u;
rank[ulp_u]++;
}
}
void unionBySize(int u, int v) {
int ulp_u = findUPar(u);
int ulp_v = findUPar(v);
if(ulp_u == ulp_v) return;
if(size[ulp_u] < size[ulp_v]) {
parent[ulp_u] = ulp_v;
size[ulp_v] += size[ulp_u];
}
else {
parent[ulp_v] = ulp_u;
size[ulp_u] += size[ulp_v];
}
}
};
 
void ngr(vll& v,vll& ans)
{
stack<ll> s;
ll n=v.size();
s.emp(v[n-1]);
ans.pb(-1);
rev(i,n-2,0)
{
while(s.size()!=0&&s.top()<v[i]) s.pop();
if(s.size()==0){ans.pb(-1);}
else ans.pb(s.top());
s.emp(v[i]);
}
reverse(ans.begin(),ans.end());
return;
}
void ngl(vll& v,vll& ans)
{
ll n=v.size();
stack<ll> s;
ans.pb(-1);
s.emp(v[0]);
fr(i,1,n)
{
while(s.size()!=0&&s.top()<v[i]) s.pop();
if(s.size()==0) ans.pb(-1);
else ans.pb(s.top());
s.emp(v[i]);
}
return;
}
void primefact(ll n,vll& v)
{
ll temp=2;
while(temp<sqrtl(n))
{
while(n%temp==0)
{
n=n/temp;
v.pb(temp);
}
++temp;
}
if(n>1) v.pb(n);
}
ll power(ll a,ll b,ll c=M)
{
if(a==0) return 0;
if(b==0) return 1;
if(b%2==0){
ll ans=power(a,b/2,c);
ll final=mul(ans,ans);
return final;
}
else return mul(a,power(a,b-1,c));
}
ll power(ll x,int y, int p)
{
    ll res = 1; // Initialize result
  x = x % p;
   while (y > 0) 
    {
      if (y & 1) res = (res * x) % p;
      y = y >> 1; 
      x = (x * x) % p;
    }
    return res;
}
ll modInverse(unsigned long long n,int p)
{
    return power(n, p - 2, p);
}
ll nCrModPFermat(ll n,ll r,ll p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)% p;
}
int main()
{
fastio;
 
ll t;
 
cin>>t;
while(t--)
{
   ll n;cin>>n;
   vll v(2*n);
   fr(i,0,2*n) cin>>v[i];
   sort(all(v));cout<<(v[n]-v[n-1])<<"\n";
}
return 0;
}

