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
        if(m[x+1].size()<m[x].size())
        {
            swap(m[x+1],m[x]);
            swap(sum[x+1],sum[x]);
        }
        m[x+1].insert(m[x].begin(),m[x].end());
        sum[x+1]+=sum[x];
//        while(s.size()!=1)
//        {
//            ans+=*s.begin();
//            m[x+1].insert(*s.begin());
//            s.erase(s.begin());
//        }
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
