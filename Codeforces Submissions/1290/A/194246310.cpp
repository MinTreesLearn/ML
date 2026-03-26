#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+10;
int arr[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i) cin>>arr[i];
        if(k>=m) k=m-1;
        int ans=-1,len1=n-k,len2=len1-(m-k-1);
        for(int i=1;i<=k+1;++i){
            int tmp=0x3f3f3f3f;
            for(int j=i;j<=i+m-k-1;++j)
                tmp=min(tmp,max(arr[j],arr[j+len2-1]));
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}