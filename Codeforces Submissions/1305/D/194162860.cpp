#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define ep insert
#define endl '\n'
#define elif else if
#define pow pwr
#define sqrt sqrtt
#define int long long
typedef unsigned long long ull;
using namespace std;
const int N=1005;
vector<int> adj[N];
int n,dis[N],curnode=1;
void dfs(int node,int d,int p){
    dis[node]=d;
    for (auto u:adj[node]){
        if (u==p) continue;
        dfs(u,d+1,node);
    }return;
}
void del(int node,int p,int t){
    for (int i=0;i<adj[node].size();i++){
        if (adj[node][i]==p) continue;
        if (adj[node][i]==t){
            //cout<<node<<endl;
            for (int j=0;j<adj[t].size()-1;j++){
                if (adj[t][j]!=node) continue;
                swap(adj[t][j],adj[t][adj[t].size()-1]);
                break;
            }adj[t].ppb();
            return;
        }del(adj[node][i],node,t);
    }
    return;
}
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for (int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    while (true){
        int x,y,z=INT_MIN;
        for (int i=1;i<=n;i++) dis[i]=INT_MIN;
        dfs(curnode,0,0);
        for (int i=1;i<=n;i++){
            if (z>=dis[i]) continue;
            x=i;
            z=dis[i];
        }
        dfs(x,0,0);
        z=INT_MIN;
        for (int i=1;i<=n;i++){
            if (z>=dis[i]) continue;
            y=i;
            z=dis[i];
        }
        if (x==y){
            cout<<"! "<<x<<endl;
            cout.flush();
            return 0;
        }
        cout<<"? "<<x<<' '<<y<<endl;
        cout.flush();
        int lca;cin>>lca;
        if (lca==-1) return 0;
        del(x,0,lca);
        del(y,0,lca);
        curnode=lca;
    }
    return 0;
}
