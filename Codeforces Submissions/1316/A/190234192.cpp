#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int temp;
        int sum =0;
        for(int i =0; i<n; i++){
            cin>>temp;
            sum+=temp;
        }
        int ans = min(sum,m);
        cout<<ans<<endl;
    }
    return 0;
}