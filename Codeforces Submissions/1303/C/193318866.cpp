#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define enter cout<<'\n';
#define INF 99999999999999999
#define MOD 1000000007

int main() 
{
ios_base::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
   string s;
   cin>>s;
   ll n;
   n=s.size();
   vector<set<int>>g(26);
   int start=-1;
   if(n==1)
   {
      cout<<"YES"<<'\n'<<"abcdefghijklmnopqrstuvwxyz"<<'\n';
      continue;
   }
   for(int i=1;i<n;i++)
   {
      g[s[i]-'a'].insert(s[i-1]-'a');
      g[s[i-1]-'a'].insert(s[i]-'a');
   }
   bool tf=true;
   for(int i=0;i<26;i++)
   {
      if(g[i].size()==1 && start==-1)
      start=i;
      if(g[i].size()>2)
      {
         tf=false;
         break;
      }
      if(g[i].size()==2)
      start=i;
   }

   if(!tf)
   {
      cout<<"NO"<<'\n';
      continue;
   }

   queue<pair<int,int>>q;
   deque<int>dq;
   dq.push_front(start);
   bool vis[26]={ };
   q.push({0,start});
   vis[start]=1;

   while(!q.empty())
   {
      ll curr=q.front().S;
      ll dir=q.front().F;
      q.pop();
      for(auto x:g[curr])
      {
         if(g[curr].size()>=2)
         {
            if(g[curr].size()==2 && curr==start){}
            else
            {
            tf=false;
            break;
            }
         }

         if(!dir)
         {
            vis[x]=true;
            dq.push_front(x);
            q.push({1,x});
            g[x].erase(curr);
            dir=2;
            continue;
         }
         if(vis[x]==true)
         {
            tf=false;
            break;
         }
         vis[x]=true;
         q.push({dir,x});
         g[x].erase(curr);
         if(dir-1)
         dq.push_back(x);
         else
         dq.push_front(x);
      }
      if(!tf)
      break;

   }
   if(!tf)
   {
      cout<<"NO"<<'\n';
      continue;
   }
   cout<<"YES"<<'\n';
   while(!dq.empty())
   {
      cout<<(char)(dq.front()+'a');
      dq.pop_front();
   }
   for(char i='a';i<='z';i++)
   if(!vis[i-'a'])
   cout<<i;

   enter
}
}

