#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long> >, rb_tree_tag,tree_order_statistics_node_update>*/
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
#define mod1   (long long)998244353
#define mod2   (long long)1000000007
#define first_bit(x) (x&(-x))
#define last_bit(x) (x&~(-x))
#define ff    first
#define int  long long
#define ss    second
#define pb    push_back
#define w(x)  long long x;cin>>x;while(x--)
#define vi    vector<long long> 
#define mii map<long long,long long>
#define pii pair<long long,long long>
#define set_bits __builtin_popcountll
#define fast()   ios_base::sync_with_stdio(false);cin.tie(NULL);
#define sz(x) ((long long)x.size())
#define all(x) begin(x), end(x)
#define memo(x,y) memset((x),(y),sizeof(x));
signed main(){
    fast();
   string s;
   cin>>s;
   int n=s.size();
   int arr[26][n+1];
   memo(arr,0);
   for(int i=0;i<n;i++){
      arr[s[i]-'a'][i+1]++;
   }
   for(int i=0;i<26;i++){
      for(int j=1;j<=n;j++)arr[i][j]+=arr[i][j-1];
   }
   int q;
   cin>>q;
   while(q--){
      int l,r;
      cin>>l>>r;
      int ne=0;
      for(int i=0;i<26;i++)if(arr[i][r]-arr[i][l-1]>0)ne++;
      if(ne==1){
         if(l==r)cout<<"Yes"<<endl;
         else cout<<"No"<<endl;
      }
      else if(ne==2){
         l--;r--;
         if(s[l]==s[r])cout<<"No"<<endl;
         else cout<<"Yes"<<endl;
      }
      else cout<<"Yes"<<endl;
   }
}

