#include<bits/stdc++.h>
using namespace std;
#define endl '\n';
#define int int64_t
#define mod (int)(1e9+7)
void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    bool flag=true;
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            flag=false;
            if(i+1<n && arr[i+1]!=-1){
                mini=min(mini,arr[i+1]);
                maxi=max(maxi,arr[i+1]);
            }
            if(i-1>=0 && arr[i-1]!=-1){
                mini=min(mini,arr[i-1]);
                maxi=max(maxi,arr[i-1]);
            }
        }
    }
    // cout<<maxi<<" "<<mini<<endl;
    if(flag){
        cout<<0<<" "<<0<<endl;
        return;
    }
    int k=(maxi+mini)/2;
    for(int i=0;i<n;i++){
        if(arr[i]==-1) arr[i]=k;
    }
    int ans=0;
    for(int i=0;i<n-1;i++) ans=max(ans,abs(arr[i]-arr[i+1]));
    cout<<ans<<" "<<k<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}