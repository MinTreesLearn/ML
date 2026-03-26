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
  vi a(n),pre(n+1),suf(n+1);
  forw(i,0,n) cin>>a[i];
  pre[0]=suf[n]=INT_MAX;
  forw(i,0,n){
    pre[i+1]=pre[i]& ~a[i];
  }
  backw(i,n-1,0){
    suf[i]=suf[i+1]& ~a[i];
  }
  int ans=-1;
  int pos;
  forw(i,0,n){
    if((a[i]&pre[i]&suf[i+1])>ans){
      ans=a[i]&pre[i]&suf[i+1];
      pos=i;
    }
  }
  swap(a[0],a[pos]);
  for(auto i:a) cout<<i<<" ";
  cout<<endl;




}

int main(){
  int t=1;
//   cin>>t;
  while(t--){
    // cout<<"test "<<t<<endl;
    solve();
  }
}