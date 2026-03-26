#include<bits/stdc++.h>
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
const long long  INF = INT_MAX;
using namespace std;
const int N=1e2+3,M=10;
const int mod=998244353;
/*----------------------------------------------------------------*/
int dx[] = {+0, +0, -1, +1, +1, +1, -1, -1};
int dy[] = {-1, +1, +0, +0, +1, -1, +1, -1};
/*----------------------------------------------------------------*/
void READ(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
int n;
int arr[105];
int dp[N][N][N][3];
int calc(int i,int j,int k,int l){
    if(i==n){
        return 0;
    }
    int &ret=dp[i][j][k][l];
    if(~ret){
        return ret;
    }
    ret=INF;
    int x=0;
    if(arr[i]){
        if(arr[i]%2!=l)x=1;
        ret=calc(i+1,j,k,arr[i]%2)+x;
    }
    else{
        if(j>0&&k>0){
            ret=min(calc(i+1,j-1,k,0)+(l!=0),calc(i+1,j,k-1,1)+(l!=1));
        }
        else if(j>0){
            ret=calc(i+1,j-1,k,0)+(l!=0);
        }
        else if(k>0){
            ret=calc(i+1,j,k-1,1)+(l!=1);
        }
    }
    return ret;

}
void solve(){
    cin>>n;
    int remO=0,remE=0,odd=0,even=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2)odd++;
        else if(arr[i]%2==0&&arr[i]) even++;
    }
    memset(dp,-1,sizeof dp);
    if(n%2==0){
        remO=n/2-odd;
        remE=n/2-even;
    }
    else{
        remO=(n+1)/2-odd;
        remE=n/2-even;
    }
    if(arr[0]) {
        cout << calc(1, remE, remO, arr[0]%2) << endl;
    }
    else{
        cout<<min(calc(1,remE-1,remO,0),calc(1,remE,remO-1,1))<<endl;
    }
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