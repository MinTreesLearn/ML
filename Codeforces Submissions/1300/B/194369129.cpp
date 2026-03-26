using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n;cin>>n;
    n*=2;
    int a[n+1];repp(n)cin>>a[i+1];
    a[0]=0;
    sort(a,a+n+1);

    int ans=mod;
    for(int i=1;i<n+1;i++){
        int j=2+(n-1)/2;
        //cout<<i<<" "<<j<<endl;
        if(j>i && j<n+1)
            ans=min(ans,a[j]-a[i]);
    }

    cout<<ans<<endl;
}



#define int int
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
    return 0;
}
