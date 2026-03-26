#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=3e5+5;
const ll MOD=1e9+7,MAX=1e18;
const double ep=1e-6, pi=3.14159265359;
long long inv(long long a, long long b=MOD){
    return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int dx[8] = { 1, 0, -1, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 1, 0, -1, -1, 1, 1, -1 };
ll n,m=0,k;
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<int>graph[N];
int ask(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<'\n';
    cout.flush();
    int x;
    cin>>x;
    return x;
}
bool vis[N],taken[N];
void dfs(int x)
{
    vis[x]=1;
    for(auto i:graph[x])
    {
        if(!vis[i])dfs(i);
    }
}
void fn()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int>leafs,v2;
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()==1)
        {
            leafs.push_back(i);
        }
    }
    while(leafs.size()>1)
    {
        int a=leafs.back();
        leafs.pop_back();
        int b=leafs.back();
        leafs.pop_back();
        if(vis[b])
        {
            leafs.push_back(a);
        }
        else
        {
            int x=ask(a,b);
            vis[x]=1;
            if(x==a)
            {
                cout<<"! "<<a<<'\n';
                return;
            }
            if(x==b)
            {
                cout<<"! "<<b<<'\n';
                return;
            }
            if(!taken[x])v2.push_back(x),taken[x]=1;
            if(!vis[a]||b==x)dfs(a);
            if(!vis[b])dfs(b);
            vis[x]=0;
        }
    }
    if(leafs.size()&&!taken[leafs[0]])
    {
        v2.push_back(leafs[0]);
    }
    leafs=v2;
    cout.flush();
    while(leafs.size()>1)
    {
        int a=leafs.back();
        leafs.pop_back();
        int b=leafs.back();
        leafs.pop_back();
        if(vis[b])
        {
            leafs.push_back(a);
        }
        else
        {
            int x=ask(a,b);
            leafs.push_back(x);
            vis[x]=1;
            if(!vis[a]||b==x)dfs(a);
            if(!vis[b])dfs(b);
        }
    }
    cout<<"! "<<leafs[0]<<'\n';
    cout.flush();
}
int main()
{
    fastio();
    int t=1;
    //cin>>t;
    while(t--)fn();
    return 0;
}
