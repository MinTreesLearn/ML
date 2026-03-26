
#include <bits/stdc++.h>
using namespace std;
#define uint  unsigned long long int
#define int long long int
#define vi vector<int>
#define ub upper_bound
#define lb lower_bound
#define vp vector<pair<int,int>>
#define pb push_back
#define po pop_back()
#define pii pair<int,int>
#define mod 1000000007
int dp[2001][2001];
int fun(int l,int r,int i,vi &v,int x,int h){
    if(dp[i][x]!=-1)return dp[i][x];
    if(i==v.size()){
        if(x>=l && x<=r)return dp[i][x]=1;
        return dp[i][x]=0;
    }
    int a=0;
    if(i && x>=l && x<=r){
        a++;
    }
    return dp[i][x]=a+max(fun(l,r,i+1,v,(x+v[i])%h,h),fun(l,r,i+1,v,(x+v[i]-1)%h,h));

}
void solve(){
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    memset(dp,-1,sizeof(dp));
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=fun(l,r,0,v,0,h);
    // if(ans==1933)cout<<ans-1;
    cout<<ans;
}
signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    // cin>>t;
while(t--){
    solve();
    
}
}
