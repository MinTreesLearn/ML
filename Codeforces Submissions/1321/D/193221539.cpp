#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define enter cout<<'\n';
#define INF 99999999999999999
#define MOD 1000000007

vector<vector<int>>g(200001);
vector<vector<int>>g1(200001);
vector<int>dist(200001,MOD);

void dfs(int i)
{
priority_queue<pair<int,int>>pq;
pq.push({0,i});
while(!pq.empty())
{
pair<int,int>curr=pq.top();
curr.F=-curr.F;
pq.pop();

if(curr.F>dist[curr.S])
continue;

for(auto x:g[curr.S])
{
   if(dist[x]>dist[curr.S]+1)
   {
      dist[x]=dist[curr.S]+1;
      pq.push({-dist[x],x});
   }
}
}

}
int main() 
{
ios_base::sync_with_stdio(0);
cin.tie(0);
ll n,m;
cin>>n>>m;
ll x,y;
for(int i=1;i<=m;i++)
      {
         cin>>x>>y;
         g[y].pb(x);
         g1[x].pb(y);
      }

ll k;
cin>>k;
ll arr[k];

for(int i=0;i<k;i++)
cin>>arr[i];


dist[arr[k-1]]=0;
dfs(arr[k-1]);


ll big=0,small=0;
for(int i=k-2;i>=0;i--)
{
   ll count=0;
   bool tf=false;
   for(auto x:g1[arr[i]])
   {
      if(dist[x]==dist[arr[i]]-1)
      {
      count++;
      if(x==arr[i+1])
      tf=true;
      }

   }
   if(tf==false)
   {
      big++;
      small++;
   }
   else
   if(count>1)
   big++;
  // cout<<small<<' '<<big<<'\n';
}
cout<<small<<' '<<big;
}

