#include <bits/stdc++.h>
using namespace std;
#define ll long long
// ll int N = 1e9+7;
#define f(n) for (auto i = 0; i < n; i++)
#define fo(i, k, n) for (auto i = k; i < n; i++)
#define ff first
#define ss second
#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define sorr                          \
  {                                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
  }
double pi = 2 * acos(0.0);
const int N = 1e9 + 7;
ll int comp=1e18+1;
// Sort the array in descending order
// sort(arr, arr + n, greater<int>());
// global varible = 0.
//  cout<<fixed<<setprecision(9);
// memset(array name,value to be filled,sizeof(array name));

// void rest(int a){
//   f(a){par[i]=0;sze[i]=0;}return;
// }
int par[150008];
int sz[150008];

void make(int q)
{
  par[q] = q;
  sz[q] = 1;
}
int find(int q)
{
  if (par[q] == q)
    return q;
  return par[q] = find(par[q]);
}
void Union(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x != y)
  {
    if (sz[x] < sz[y])
      swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
  }
}
//  bool vis[10005];

// bool is_valid(int x,int y,int n,int qx,int qy){
//   return(x>0&&y>0&&x<=n&&y<=n&&((qx-x)!=(qy-y))&&((qy-y)!=-(qx-x))&&x!=qx&&y!=qy);
// }
// vector<pair<int,int>>mov{
//   {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}
// };


// void rest(int n){
//   f(n+2)v[i].clear();
// }

// ll int t[2000006];
// ll int val[2000006];
  //  val[3]=1;

// vector<int>v[100005];
// bool vis[1005];
// // ll int val[200005][20];
// ll int dis[1005];
// ll int par[1005];
// f(1005) {par[i]=-1;dis[i]=INT_MAX;}
// vector<pair<ll int,ll int>>v[1005];
// void dfs(int strt){
// set<pair<ll int,ll int>>s;s.insert({0,strt});
// dis[strt]=0;
// while(s.size()){
//   pair<ll int ,ll int >p=*s.begin();s.erase(s.begin());
//   ll int ind=p.second,wt=p.first;  vis[ind]=true;
//   for(auto x:v[ind]){
//     ll int nex=x.first,wigh=x.second;
//     if(wigh+wt<dis[nex]&&!vis[nex]){
//        dis[nex]=wigh+wt;par[nex]=ind;
//        s.insert({dis[nex],nex});
//     }
//   }
// }
// return;
// }
// void path(ll int source,vector<pair<ll int,ll int>>&vec,ll int& ans=0){
// while(source!=-1){
// if(par[source]!=-1)  {vec.pb({par[source],source});if(m[par[source]][source]==0)ans++;}
// return path(par[source],vec,ans);
// }
// return; 
// }
// map<int,int>m;
// void to_find(){
//   for(int i=0;i<5000050;i++){
//     ll int d=(2*i)+1;
//     m[d]++;
//   }
//   return 0;
// }
bool is_val[200004];
bool vis[200004];
bool dfs(int ind,vector<vector<int>>&v){
  if(ind==1)return true;
  vis[ind]=true;
  for(auto child:v[ind]){
    if(vis[child]||(!is_val[child]))continue;
   if( dfs(child,v))return true;
  }
  return false;
}
int main(){
int t;cin>>t;while(t--){
ll int a,b,p,res=0;cin>>a>>b>>p;
vector<pair<ll int,ll int>>v;string s;cin>>s;ll int n=s.size();
f(n-1){
  if(s[i]!=s[i+1]&&s[i]=='A'){v.pb({a,i+1});res+=a;}
 else  if(s[i]!=s[i+1]&&s[i]=='B'){v.pb({b,i+1});res+=b;}
}
if(s[n-1]==s[n-2]){if(s[n-1]=='A'){v.pb({a,n-1});res+=a;}else {v.pb({b,n-1});res+=b;}}
if(p>=res){cout<<1<<endl;}
else{int ind=0;
  while(p<res&&ind<v.size()){res-=v[ind].first;ind++;}
 cout<<v[ind-1].second+1<<endl;
}
}
return 0;}

