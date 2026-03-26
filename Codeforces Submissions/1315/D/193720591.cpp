#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve()
{
    int n;cin>>n;
    map<int,multiset<int>>m;
    map<int,int>sum;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        m[a[i]].insert(x);
        sum[a[i]]+=x;
    }
    int ans=0;
    for(auto&[x,s]:m)
    {
        if(s.size()<=1)continue;
        sum[x]-=*s.rbegin();
        ans+=sum[x];
        s.erase(--s.end());
        if(m[x+1].size()<s.size())swap(m[x+1],s);
        m[x+1].insert(s.begin(),s.end());
        sum[x+1]+=sum[x];
    }
    cout<<ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int t=1;
//    cin>>t;
    while(t--)solve();
}
