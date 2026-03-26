#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int maxn=2*1e5+11;
const int Maxx=1e5+11;
const int mod=1e9+7;
int t;
int n;
int p[2005],c[2005];
vector<int>son[2005];
int ans[2005];
int f;
vector<int> dfs(int x)
{
    vector<int>tmp;
    for(auto P:son[x])
    {
        vector<int>res=dfs(P);
        tmp.insert(tmp.end(),res.begin(),res.end());
    }
    if(c[x]>int(tmp.size())) {f=1;return tmp;}
    tmp.insert(tmp.begin()+c[x],x);
    return tmp;
}
void solve()
{
     cin>>n;
     int root=0;
     for(int i=1;i<=n;++i)
     {
         cin>>p[i]>>c[i];
         if(!p[i]) root=i;
         else son[p[i]].push_back(i);
     }
     f=0;
     vector<int>res=dfs(root);
     if(f) {cout<<"NO"<<endl;return;}
     cout<<"YES"<<endl;
     for(int i=0;i<int(res.size());++i) ans[res[i]]=i+1;
     for(int i=1;i<=n;++i)
     {
         cout<<ans[i]<<" ";
     }
     cout<<endl;
}
int main()
{
    //scanf("%d",&t);
    ios::sync_with_stdio(false);cin.tie(0);
    //ios::sync_with_stdio(false);cin.tie(0);cin>>t;while(t--)
    solve();
    return 0;
}