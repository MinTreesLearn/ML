// Don't Quit  O_O

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define INF LLONG_MAX
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007

// Will become Master  ^_^

vector<vector<lli>> adj(200005);
lli vis[200005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t=1,n,i;
    // cin>>t;
    while(t--)
    {
        lli m,k;
        cin>>n>>m>>k;
        lli sp[k];
        set<lli> special;
        for(i=0;i<k;i++)
        {
            cin>>sp[i];
            special.insert(sp[i]);
        }
        lli u[m],v[m];
        for(i=0;i<m;i++)
        {
            cin>>u[i]>>v[i];
            adj[u[i]].pb(v[i]);
            adj[v[i]].pb(u[i]);
        }
        lli dist[n+1];
        lli par[n+1];
        queue<pair<lli,lli>> q;
        q.push({1,0});
        dist[1]=0;
        par[1]=0;
        while((int)q.size())
        {
            pair<lli,lli> p=q.front();
            vis[p.ff]=1;
            q.pop();
            for(auto &x : adj[p.ff])
            {
                if(!vis[x])
                {
                    q.push({x,p.ss+1});
                    par[x]=p.ff;
                    dist[x]=p.ss+1;
                    vis[x]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        vis[i]=0;
        q.push({n,0});
        lli distn[n+2];
        distn[n]=0;
        while((int)q.size())
        {
            pair<lli,lli> p=q.front();
            vis[p.ff]=1;
            q.pop();
            for(auto &x : adj[p.ff])
            {
                if(!vis[x])
                {
                    q.push({x,p.ss+1});
                    distn[x]=p.ss+1;
                    vis[x]=1;
                }
            }
        }
        set<lli> path;
        path.insert(n);
        lli curr=par[n];
        while(curr!=1)
        {
            // cout<<curr<<" ";
            path.insert(curr);
            curr=par[curr];
        }
        path.insert(1);
        // cout<<"\n";
        lli count=0;
        bool flag=false;
        for(i=0;i<m;i++)
        {
            if(special.count(u[i]) && special.count(v[i]))
            flag=true;
        }
        for(i=0;i<k;i++)
        {
            if(!path.count(sp[i]))
            count++;
        }
        // cout<<count<<" "<<flag<<" "<<dist[n]<<"\n";
        lli nearest[n+2][2];
        for(i=1;i<=n;i++)
        {
            vis[i]=0;
            if(path.count(i))
            {
                q.push({i,0});
                vis[i]=1;
                nearest[i][0]=0;
                nearest[i][1]=i;
            }
        }
        while((int)q.size())
        {
            pair<lli,lli> p=q.front();
            vis[p.ff]=1;
            q.pop();
            for(auto &x : adj[p.ff])
            {
                if(!vis[x])
                {
                    q.push({x,p.ss+1});
                    nearest[x][0]=p.ss+1;
                    nearest[x][1]=nearest[p.ff][1];
                    vis[x]=1;
                }
            }
        }
        // for(i=1;i<=n;i++)
        // cout<<nearest[i][0]<<" "<<nearest[i][1]<<"\n";
        if(flag)
        {
            cout<<dist[n];
            continue;
        }
        else
        {
            lli mx=0,ans=0;
            vector<pair<lli,lli>> v;
            for(i=0;i<k;i++)
            {
                v.pb({dist[sp[i]], distn[sp[i]]});
            }
            sort(v.begin(),v.end());
            lli suff[k];
            suff[k-1]=v[k-1].ss;
            for(i=k-2;i>=0;i--)
            {
                suff[i]=max(suff[i+1],v[i+1].ss);
            }
            for(i=0;i<k-1;i++)
            {
                ans=max(ans,v[i].ff+1+suff[i]);
            }
            ans=min(ans,dist[n]);
            cout<<ans;
            // vector<lli> v;
            // lli ans=0,mn=n+10;
            // for(i=0;i<k;i++)
            // {
            //     if(path.count(sp[i]))
            //     {
            //         v.pb(dist[sp[i]]);
            //         mn=min(mn,dist[sp[i]]);
            //     }
            // }
            // if(mn==n+10)
            // {
            //     lli mx=0,pos;
            //     for(i=0;i<k;i++)
            //     {
            //         mx=max(mx,nearest[sp[i]][0]+distn[nearest[sp[i]][1]]);
            //         if(mx==nearest[sp[i]][0]+distn[nearest[sp[i]][1]])
            //         pos=sp[i];
            //     }
            //     for(i=0;i<k;i++)
            //     {
            //         if(pos==sp[i])
            //         continue;
            //         ans=max(ans,dist[sp[i]]+1+mx);
            //     }
            //     if(ans>dist[n])
            //     ans=dist[n];
            //     cout<<ans<<"\n";
            //     continue;
            // }
            // // cout<<dist[n]<<"*";
            // for(i=0;i<k;i++)
            // {
            //     if(!path.count(sp[i]))
            //     {
            //         if(dist[sp[i]]+1>=mn)
            //         ans=max(ans,dist[n]);
            //         else
            //         ans=max(dist[n]-(mn-dist[sp[i]]-1),ans);
            //     }
            // }
            // // cout<<ans<<"*"<<mn<<"*";
            // sort(v.begin(),v.end());
            // mn=n+10;
            // for(i=0;i<(int)v.size()-1;i++)
            // {
            //     mn=min(mn,v[i+1]-v[i]);
            //     ans=max(ans,dist[n]-mn+1); 
            // }
            // // cout<<ans<<"*";
            // lli mx=0,pos=0;
            // for(i=0;i<k;i++)
            // {
            //     if(!path.count(sp[i]))
            //     {
            //         mx=max(mx,nearest[sp[i]][0]+distn[nearest[sp[i]][1]]);
            //         if(mx==nearest[sp[i]][0]+distn[nearest[sp[i]][1]])
            //         pos=sp[i];
            //     }
            // }
            // // cout<<mx<<"@@"<<pos<<"\n";
            // for(i=0;i<k;i++)
            // {
            //     if(pos==sp[i] || path.count(sp[i]))
            //     continue;
            //     ans=max(ans,dist[sp[i]]+1+mx);
            // }
            // // cout<<ans<<"*";
            // if(ans>dist[n])
            // ans=dist[n];
            // cout<<ans;
        }
    }
}