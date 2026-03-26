//DEEPANSHU SONKAR
//2113092

#include<bits/stdc++.h>

#define turbo()                                                                \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0);

#define ll long long 
const ll mod=1000000007;
const ll INF= 1e9+7;
#define pb push_back
#define pp pop_back
#define mp make_pair
#define pf push_front
#define vll vector<ll>
#define get(a,n) vll a(n); for(int i=0;i<n;i++) cin>>a[i];
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define all(x) ((x).begin(),(x).end())
#define vsort(vec) sort(vec.begin(),vec.end());
#define rvsort(vec) sort(vec.begin(),vec.end(),greater<int>());

#define tc() long long int t;cin>>t;while(t--)
#define rep(var,start,to) for(ll var=start;var<to;var++)
#define rep1(a, b, c) for (ll a = b; a >= c; a--)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define google cout<<"Case #"<<i+1<<": ";
 
 
 
 
using namespace std;
 
 
 
 
bool isprime(int n) {
  bool f = true;
  if (n == 0 || n == 1) {
    f = false;
  }
 
  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      f = false;
      break;
    }
  }
 
  return f;
}


void codingkarlo_BC(){
    string s;cin>>s;
    vector<int> x,x1;
    vector<int> ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            x.pb(i+1);
        }
        else{
            x1.pb(i+1);
        }
    }
    reverse(x1.begin(),x1.end());
    for(int i=0;i<min(x.size(),x1.size());i++){
        if(x[i]>x1[i]){
            break;
        }
        else{
            ans.pb(x[i]);
            ans.pb(x1[i]);
        }
    }
    if(ans.size()==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
        vsort(ans);
        cout<<ans.size()<<endl;
        print(ans,ans.size());
    }
  }
  
  

signed main()
{
    turbo()
    codingkarlo_BC();
   //tc(){ codingkarlo_BC(); /*google*/ }
   
 
 
    return 0;
}