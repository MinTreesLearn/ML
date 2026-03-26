#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;
#define int long long
int gauss(int x)
{
    return x*(x+1)/2;
}
void solve()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(auto &c:a)cin>>c.first;
    for(auto &c:a)cin>>c.second;
    sort(a.begin(),a.end());
    int sum=0,rez=0;
    priority_queue<int>q;
    int acm=-1;
    a.push_back({2e9,-1});
    for(int i=0;i<=n;)
    {
        while(acm!=a[i].first && q.size())
        {
            sum-=q.top();
            q.pop();
            rez+=sum;
            acm++;
        }
        acm=a[i].first;
        while(a[i].first==acm)
        {
            sum+=a[i].second;
            q.push(a[i].second);
            i++;
        }
    }
    cout<<rez;
}
main()
{
    auto sol=[](bool x)->string
    {
        if(x)return "YES";
        return "NO";
    };
    int tt=1;
    //cin>>tt;
    while(tt--)
    {
        solve();
        cout<<'\n';
    }
}
