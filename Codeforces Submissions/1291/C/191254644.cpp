#include<bits/stdc++.h>
using namespace std;
const int maxn = 4010;
int t,n,m,k;
int a[maxn];
int main()
{
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans = 0;
        k=min(m-1,k);
        for(int i=0;i<=k;i++)
        {
            int tmp = 1e9;
            for(int j=0;j<m-k;j++)
            {
               tmp=min(tmp,max(a[i+j],a[n-1-(k-i)-(m-k-j-1)]));
            }
            ans = max(ans,tmp);
        }
        cout<<ans<<endl;
    }
    return 0;
}
