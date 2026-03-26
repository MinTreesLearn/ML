#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pair<int,int>>
#define ff first
#define ss second
#define forw(i,a,b) for(int i=a;i<b;i++)
#define backw(i,a,b) for(int i=a;i>=b;i--) 
using namespace std;
const int M=998244353;



void solve(){   
  int n;
  cin>>n;
  vi a(n);
  set<int> v;
  ll sum=0;
  forw(i,0,n){
    cin>>a[i];
  }
  int mx=INT_MIN,mn=INT_MAX;
  int ans=0;
  forw(i,0,n-1){
    if(a[i]==-1 && a[i+1]!=-1){
      mx=max(mx,a[i+1]);
      mn=min(mn,a[i+1]);
    }else if(a[i]!=-1 && a[i+1]==-1){
      mx=max(mx,a[i]);
      mn=min(mn,a[i]);
    }else{
      ans=max(ans,abs(a[i]-a[i+1]));
    }
  }
  int avg=(mx+mn)/2;
 
  if(a[0]==-1)a[0]=avg;
  forw(i,1,n){
    if(a[i]==-1) a[i]=avg;
    ans=max(ans,abs(a[i]-a[i-1]));
  }
  cout<<ans<<" "<<avg<<endl;

}

int main(){
  int t;
  cin>>t;
  while(t--){
    // cout<<"test "<<t<<endl;
    solve();
  }
}