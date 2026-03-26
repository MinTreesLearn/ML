using namespace std;
#include <bits/stdc++.h>
#define int long long
#define repp(n) for(int i=0;i<n;i++)
#define mod 1000000007



void solve()
{
    int n,ans=0;cin>>n;
    string a;cin>>a;

    repp(n){
        if(a[i]=='A')
            continue;
        int cnt=1;
        for(int j=i-1;j>-1;j--){
            if(a[j]=='P')
                cnt++;
            else{
                ans=max(ans,cnt);
                break;
            }
        }
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
