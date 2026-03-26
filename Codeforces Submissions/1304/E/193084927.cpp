#include <bits/stdc++.h>
// v.erase( unique(all(v)) , v.end() )    ----->   removes duplicates and resizes the vector as so
using namespace std;
#define ll long long
#define lld long double
const lld pi = 3.14159265358979323846;
#define pb push_back
#define pf push_front
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
constexpr int mod = (int)(1e9+7);
#define log(x) (31^__builtin_clz(x)) // Easily calculate log2 on GNU G++ compilers
const int N=1e5+7;
int n,d[N];vector<int> adj[N];int in[N],out[N],tick;pair<int,int> A[2*N];
pair<int,int> M[20][2*N];int par[N];

void dfss(int node,int p,int dist)// Call this then call build_sparse
{in[node]=(++tick);par[node]=p;d[node]=dist;
if(!dist)par[node]=node;
for(int i=0;i<adj[node].size();i++)if(adj[node][i]!=p)dfss(adj[node][i],node,dist+1);
out[node]=(++tick);
}

void build_sparse()
{for(int i=1;i<=n;i++)A[in[i]]=A[out[i]]={d[i],i};
for(int i=0 ; i<tick+1 ; i++) M[0][i] = A[i]; // base-case
   for(int j=1 ; 1<<j <= tick+1 ; j++) // while 2^j fits inside the array
      for(int i=0 ; i+(1<<j) <= tick+1 ; i++) 
         M[j][i] = min(M[j-1][i], M[j-1][i+(1<<(j-1))]);
}
pair<int,int> inline get(int l, int r){
   int k = log(r-l+1);
   return min(M[k][l], M[k][r-(1<<k)+1]);
}

int get_LCA(int x,int y)
{if(out[x]>out[y])swap(x,y);
if(x==y)return x;
pair<int,int> p=get(out[x],out[y]-1);
return par[p.second];
}

int get_LCA(int x,int y,int z)
{return get_LCA(x,y)^get_LCA(x,z)^get_LCA(y,z);}

int main()
{ios_base::sync_with_stdio(0),cin.tie(0);
cin>>n;
for(int i=0;i<n-1;i++){
  int a,b;cin>>a>>b;
  adj[a].pb(b);
  adj[b].pb(a);
}
dfss(1,0,0); build_sparse();
int q;cin>>q;
while(q--){
  int x,y,a,b,k;cin>>x>>y>>a>>b>>k;
  int path1=d[a]+d[b]-2*d[get_LCA(a,b)];
  int d1=d[a]+d[x]-2*d[get_LCA(a,x)]+d[y]+d[b]-2*d[get_LCA(y,b)]+1;
  int d2=d[a]+d[y]-2*d[get_LCA(a,y)]+d[x]+d[b]-2*d[get_LCA(x,b)]+1;
  int path2=min(d1,d2);
  int dist=2e9;
  if(path1%2!=k%2&&path2%2==k%2){
    dist=path2;
  }
  else if(path2%2!=k%2&&path1%2==k%2){
    dist=path1;
  }
  else if(path2%2==k%2&&path1%2==k%2){
    dist=min(path1,path2);
  }
  if(dist<=k)cout<<"YES\n";else cout<<"NO\n";
}





 
 
 
    return 0;
}
/*






 
 
 
*/