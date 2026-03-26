#include<bits/stdc++.h>
#define MOD 1000000007
#define eps 1e-9
#define emailam  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll              long long
#define ull             unsigned long long
#define MAX 200010
#define pb push_back
#define all(a)  a.begin(),a.end()
#define pf push_front
#define fi first
#define se second
#define pii pair<int,int>
const int INF = INT_MAX;
using namespace std;
const int N=1e6+10;
#define int long long
/*----------------------------------------------------------------*/
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
/*----------------------------------------------------------------*/
void READ(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
int n,m;
int dp[20][1001];
const int mod=1e9+7;
int calc(int i,int j){
    if(i==m){
        return 1;
    }
    int &ret=dp[i][j];
    if(~ret){
        return ret;
    }
    ret=0;
    for(int k=j;k<=n;k++){
        ret=(ret+calc(i+1,k))%mod;
    }
    return ret;
}
void solve(){
    cin>>n>>m;
    m*=2;
    memset(dp,-1,sizeof dp);
    cout<<calc(0,1)<<endl;
}



signed main() {
    emailam
    //READ();
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}