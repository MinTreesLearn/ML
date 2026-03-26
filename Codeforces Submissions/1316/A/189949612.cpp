#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=a[i];
        int mini=min(sum,m);
        cout<<mini<<endl;
    }
}