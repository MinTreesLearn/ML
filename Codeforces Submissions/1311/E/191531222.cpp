#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long> >,
 rb_tree_tag,tree_order_statistics_node_update>*/
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
#define mod1   (long long)998244353
#define mod2   (long long)1000000007
#define first_bit(x) (x&(-x))
#define last_bit(x) (x&~(x))
#define ll   long long
#define ld   long double
//#define int long long
#define ff    first
#define ss    second
#define pb    push_back
#define w(x)  long long x;cin>>x;while(x--)
#define vi    vector<long long> 
#define mii map<long long,long long>
#define pii pair<long long,long long>
#define set_bits(x) __builtin_popcountll(x)
#define fast()  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz(x) ((long long)x.size())
#define all(x) begin(x), end(x)
#define memo(x,y) memset((x),(y),sizeof(x));
signed main(){
 fast();
 w(x){
 int n,x;
 cin>>n>>x;
 int curr=2;
 map<int,int> lev;
 map<int,int> deg;
 map<int,int> par;
 map<int,int> is;
 vector<int> mx;
 mx.push_back(1);
 queue<int> q;
 q.push(1);
 while(curr<n+1){
 int a=q.front();
 q.pop();
 if(lev[a]+1==mx.size()){mx.push_back(curr);is[curr]++;}
 par[curr]=a;
 lev[curr]=lev[a]+1;
 q.push(curr);
 x-=lev[curr++];
 deg[a]++;
 if(curr<n+1){
 par[curr]=a;
 lev[curr]=lev[a]+1;
 q.push(curr);
 x-=lev[curr++];
 deg[a]++;
 }
 }
 while(x>0){
  bool fd=false;
  for(int i=2;i<=n;i++)if(!is[i]&&deg[i]==0&&deg[mx[lev[i]]]<2){
    x--;
    deg[mx[lev[i]]]++;
    deg[par[i]]--;
    par[i]=mx[lev[i]];
    lev[i]++;
    if(lev[i]==mx.size()){is[i]++;mx.push_back(i);}
    fd=true;
    break;
  }
  if(!fd)break;
 }
 if(x==0){
  cout<<"YES"<<endl;
  for(int i=2;i<=n;i++)cout<<par[i]<<" ";
  cout<<endl;
 }
 else cout<<"NO"<<endl;
 }
}