#include <bits/stdc++.h>
using namespace std; 
#define all(c) c.begin(),c.end()
#define sz(x) int(x.size())
#define ar array
typedef long long ll; 
typedef vector<int> vi;
const ll mod=1000000007;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll exp(ll x,ll y){
  x%=mod;
  ll res=1;
  while(y){
    if(y&1) res=res*x%mod;
    x=x*x%mod, y>>=1;
  }
  return res;
}
ll fact(ll n){
  ll res=1;
  for(ll i=2;i<=n;++i) (res*=i)%=mod;
  return res;
}
bool isprime(ll n){
  if(n<=1) return 0;
  for(ll i=2;i*i<=n;++i) if(n%i==0) return 0;
  return 1;
}

int main(){
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
int t; cin>>t;
while(t--){
  int n; cin>>n;
  vector<ar<int,2>> v(n);
  vector<int> b;
  for(int i=0;i<n;++i){
    for(int j=0;j<2;++j){
      cin>>v[i][j];
      b.push_back(v[i][j]);
      v[i][j]*=2;
      b.push_back(v[i][j]); b.push_back(v[i][j]+j);
    }
  }
  sort(all(b)); b.resize(unique(all(b))-b.begin());
  for(auto &i:v) for(int j=0;j<2;++j) i[j]=lower_bound(all(b),i[j])-b.begin();
  vector<int> pre(5*n),p(5*n);
  for(auto i:v){
    ++pre[i[0]];
    if(i[1]+1<5*n) --pre[i[1]+1];
  }
  for(int i=1;i<5*n;++i) pre[i]+=pre[i-1];
  int a=0,mx=0;
  for(int i=1;i<5*n;++i) a+=!pre[i]&&pre[i-1];
  for(int i=1;i<5*n;++i) p[i]=p[i-1]+(pre[i]==1&&pre[i-1]>1);
  for(auto i:v){
    int c=i[1]+1<5*n?!pre[i[1]+1]&&pre[i[1]]==1:0;
    mx=max(mx,a+p[i[1]]-(i[0]?p[i[0]-1]:0)-c);
  }
  cout<<mx<<'\n';
}
return 0;
}