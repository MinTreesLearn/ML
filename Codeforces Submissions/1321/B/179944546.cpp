#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K,class V> using omap = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
void __print(int x){cout<<x;}void __print(long long x){cout<<x;}
void __print(double x){cout<<x;}void __print(long double x){cout<<x;}
void __print(char x){cout<<'\''<<x<<'\'';}void __print(const char *x){cout<<'\"'<<x<<'\"';}
void __print(const string &x){cout<<'\"'<<x<<'\"';}void __print(bool x){cout<<(x?"True":"False");}
template<typename T,typename V>
void __print(const pair<T,V>&x){cout<<'{';__print(x.first);cout<<',';__print(x.second);cout<<'}';}
template<typename T>
void __print(const T &x){int f=0;cout<<'{';for(auto &i:x)cout<<(f++?",":""),__print(i);cout<<"}";}
void _print(){cout<<"]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ms(a,x)         memset(a,x,sizeof a)
#define int             long long
#define ff              first
#define ss              second
#define pb              push_back
#define nl              '\n'
#define index           find_by_order
#define less            order_of_key
#define gcd(a,b)        __gcd((a),(b))
#define sq(a)           ((a)*(a))
#define len(a)          (int)a.size()
#define all(a)          a.begin(),a.end()
const int mod=1e9+7;
const int N=2e5+5;

void solve(){
  int n;
  cin>>n;
  int a[n+1];
  map<int,int>mp;
  int ans=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    mp[a[i]-i]+=a[i];
    ans=max(ans,mp[a[i]-i]);
  }
  cout<<ans;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T=1;
  //cin>>T;
  for(int t=1;t<=T;t++){
    solve();
  }
}
