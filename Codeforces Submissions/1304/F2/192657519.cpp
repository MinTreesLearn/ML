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
#define left p<<1 , l , (l+r)>>1
#define right p<<1|1 , ((l+r)>>1)+1 , r
const int N=4e4+7;
const int M=52;
vector<int> seg[2],lazy[2];

void push(int t,int p){
    if(!lazy[t][p]) return;
    seg[t][p<<1] += lazy[t][p]; seg[t][p<<1|1] += lazy[t][p];
    lazy[t][p<<1] += lazy[t][p]; lazy[t][p<<1|1] +=lazy[t][p];
    lazy[t][p] = 0;
}

void upd(int t,int i , int j , int inc , int p , int l , int r){
    if(j<l || r<i) return;
    if(i<=l && r<=j){
      lazy[t][p] += inc;
      seg[t][p] += inc;
      return;
    }
    push(t,p);
    upd(t,i,j,inc,left); upd(t,i,j,inc,right);
    seg[t][p]=max(seg[t][p<<1],seg[t][p<<1|1]);
}
int a[M][N];

int main()
{ios_base::sync_with_stdio(0),cin.tie(0);
int n,m;cin>>n>>m;int k;cin>>k;
for(int i=0;i<2;i++){
  seg[i].resize(4*m);lazy[i].resize(4*m);
}
for(int i=0;i<n;i++){
  for(int j=1;j<=m;j++){
    cin>>a[i][j];a[i][j]+=a[i][j-1];
  }
}
if(n==1){
  int ans=0;
  for(int i=k;i<=m;i++)ans=max(ans,a[0][i]-a[0][i-k]);
  cout<<ans<<'\n';return 0;
}

for(int i=1;i<=m;i++){
  int sum=a[1][i]-a[1][max(i-k,0)]+a[0][i]-a[0][max(i-k,0)];
  upd(0,i,i,sum,1,1,m);
}
for(int c=2;c<=n;c++){
  for(int i=0;i<4*m;i++)seg[1][i]=lazy[1][i]=0;
  for(int i=1;i<=m;i++){
    int sum=a[c][i]-a[c][max(i-k,0)]+a[c-1][i]-a[c-1][max(i-k,0)];
    int minus=a[c-1][i]-a[c-1][i-1];
    upd(0,i,min(i+k-1,m),-minus,1,1,m);
    upd(1,i,i,sum+seg[0][1],1,1,m);
    if(i>=k)upd(0,i-k+1,i,(a[c-1][i-k+1]-a[c-1][i-k]),1,1,m);
  }
  swap(seg[0],seg[1]); swap(lazy[0],lazy[1]);
}
cout<<seg[0][1]<<'\n'; 
 
 
 
 
 
 
    return 0;
}
/*






 
 
 
*/