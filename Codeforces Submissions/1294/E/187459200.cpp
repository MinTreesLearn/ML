#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int mod=1e9+7;
const int N=4e5+10;
#define int long long
int qmi(int a,int b){
    int res=1;
    for(;b;a=a*a%mod,b>>=1)
        if(b&1)res=res*a%mod;
    return res;
}
int cnt[N];
void solve(){
    int n,m,ans=0;cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1));
    rep(i,1,n)rep(j,1,m)cin>>a[i][j];
    rep(j,1,m){
        rep(i,0,n)cnt[i]=0;
        int mn=n;
        rep(i,1,n)if((a[i][j]-j)%m==0 and a[i][j]<=n*m){
            int res=i-((a[i][j]-j)/m+1);
            if(res<0)res+=n;
            cnt[res]++;
        }
        rep(i,0,n-1)mn=min(mn,i+n-cnt[i]);
        ans+=mn;
    }
    cout<<ans;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int tc=1;
    //cin>>tc;
    for (int i=1;i<=tc;i++){
        solve();
    }
}