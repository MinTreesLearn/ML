#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>adj[2000];

bool vis[2000];
ll r=1;
ll dfs(ll x)
{
    vis[x]=true;
    
    for(auto t:adj[x])
    {
        if(!vis[t])
           return dfs(t);
    }
    
    return x;
}

int main()
{
    ll N;cin>>N;
    
    vis[1]=false;  ll u,v;
    for(ll i=0;i<N-1;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v); adj[v].push_back(u);
        vis[i+2]=false;
    }
    
    while(1)
    {
       ll x=dfs(r);
       ll y=dfs(r);
       
       if(x==r)break;
       
       cout<<"? "<<x<<" "<<y<<endl;
       cin>>r;
    }
    
    cout<<"! "<<r<<endl;
    
}