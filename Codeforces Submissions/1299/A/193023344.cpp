//shinzo_wo_sasageyo!!
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define int long long
#define endl "\n"
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
typedef long long ll;
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}


ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}


//use INT_MAX as LLONG_MAX

/*-------------------------------------------------------------------------
//FOR DP OR ELSE
//vector<vector<int>>(n+1,vector<int>(m+1,-1)) dp;memset(dp,-1,sizeof(dp));
-------------------------------------------------------------------------
//FOR FLAG->(YES/NO)
if(){
   cout<<"yes"<<endl;
}
else{
   cout<<"no"<<endl;
}
--------------------------------------------------------------------------
*/
/* void checkprime(bool isprime[],int n){
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2;i*i<=n;i++){//logic of iterating till sqaure root of n and not n
        if(isprime[i]==true){//if a number is prime it's multiples will not be prime
            for(int j=i*i;j<=n;j=j+i){//observation step
                isprime[j]=false;
            }
        }
    }
}

bool isprime[100001];*/
 

 
signed main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /* for(int i=0;i<=100001;i++){
        isprime[i]=true;
    }
    checkprime(isprime,100001); */
    int t=1;
    //cin>>t;
    while(t--){
      int n;
      cin>>n;
      int a[n];
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      //sort(a,a+n);
      vector<int> bf(35,0);
      // for(int i=n-1;i>=0;i--){
      //   cout<<a[i]<<" ";
      // }
      // cout<<endl;
      for (int i = 0; i < n; ++i)
      {
        for(int j=0;j<32;j++){
          int check=a[i]&(1<<j);
          if(check>0){
            bf[j]++;
          }
        }
      }
      set<int> s;
      vector<int> v;
      for(int i=31;i>=0;i--){
        if(bf[i]==1){
          for(int j=0;j<n;j++){
            int check=a[j]&(1<<i);
            if(check>0 and s.find(j)==s.end()){
              v.push_back(a[j]);
              s.insert(j);
              break;

            }
          }

        }
      }
      for(int i=0;i<n;i++){
        if(s.find(i)==s.end()){
          v.push_back(a[i]);
        }
      }
      for (int i = 0; i < v.size(); ++i)
      {
        cout<<v[i]<<" ";
      }
      cout<<endl;
      
  
    }
   
 
    return 0;
}