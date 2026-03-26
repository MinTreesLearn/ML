#include<bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define el "\n"

using namespace std;
const ll N=2e5+10;
const ll mod=1e9+7;
int dx[]={0,-1,0,1,-1,1,-1,1};
int dy[]={-1,0,1,0,1,-1,-1,1};
ll n,m,k,x,y,z;
vector<int>adj[N],radj[N];
int dis[N],path[N];
void bfs(int st)
{
    for (int i=0;i<=n;i++)
    {
        dis[i]=1e9;
    }
    dis[st]=0;
    queue<int>q;
    q.push(st);
    while(q.size())
    {
        int node=q.front();
        q.pop();
        for (auto j:radj[node])
        {
            if (dis[j]==1e9)
            {
                q.push(j);
                dis[j]=1+dis[node];
            }
        }
    }
}
void dowork()
{
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    cin>>k;
    for (int i=0;i<k;i++)
    {
        cin>>path[i];
    }
    bfs(path[k-1]);
    int mn=0,mx=0;
    for (int i=0;i<k-1;i++)
    {
        int nxt=dis[path[i+1]],les=dis[path[i]]-1,cnt=0;
        for (auto j:adj[path[i]])
        {
            if (dis[j]==les)
            {
                cnt++;
            }
        }
        //cout<<i<<" "<<path[i]<<" "<<path[i+1]<<" "<<les<<" "<<nxt<<el;
        if (les<nxt)
        {
            mn++;
            mx++;
        }
        else if (cnt>1)
        {
            mx++;
        }
    }
    cout<<mn<<" "<<mx<<el;
}
int main(){
    fast
    //freopen("billboard.in","r",stdin);
    //freopen("billboard.out","w",stdout);
    int t;
    t=1;
    //cin>>t;
    while (t--)
    {
        dowork();
    }
}
