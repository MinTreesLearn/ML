// LUOGU_RID: 99550923
#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int sum=0,ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i>1&&k>0)
            {
                sum=min(k/(i-1),a[i]);
                ans+=sum;
                k-=(i-1)*a[i];
            }
            if(i==1) ans+=a[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}