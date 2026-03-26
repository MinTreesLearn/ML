#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(false);   cout.tie(nullptr);  cin.tie(nullptr);
    int T=1; //cin>>T;
    while(T--) {
       int n; cin>>n;
       ll cnt=0;
       vector<ll>a(n),v(n);
       for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i]=a[i]-v[i];
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            int l=i+1,r=n-1,ans=-1,mid;
            while(l<=r){
                mid=(l+r)/2;
                ll x=v[mid]+v[i];
                if(x>0){
                    ans=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if(ans!=-1)cnt+=(n)-ans;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}