#include<bits/stdc++.h>
using namespace std;
#define lll pair<long,pair<long,long>>
#define ll pair<long,long>
#define st first
#define nd second
const long  N=5e3+10;

long n,x,y,ans[N],D[N],H[N],C[N][N],m,cnt;
vector<long> ds[N];
lll Q[N];

void DFS(long a,long p){
    for(long v: ds[a]){
        if(v!=p){
            H[v]=H[a]+1;
            D[v]=a;
            DFS(v,a);
        }
    }
}
bool check(long a,long b,long val){
    if(H[a]<H[b]) swap(a,b);
    cnt=0;
    while(H[a]>H[b]){
        if(ans[C[a][D[a]]]<=val) {ans[C[a][D[a]]]=val; cnt++;}
        a=D[a];
    }
    while(a!=b){
        if(ans[C[a][D[a]]]<=val) {ans[C[a][D[a]]]=val; cnt++;}
        a=D[a];
        if(ans[C[b][D[b]]]<=val) {ans[C[b][D[b]]]=val; cnt++;}
        b=D[b];
    }
    if(!cnt) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(long i=1; i<n; i++){
        cin>>x>>y;
        ds[x].push_back(y);
        ds[y].push_back(x);
        C[x][y]=i;
        C[y][x]=i;
    }
    cin>>m;
    for(long i=1; i<=m; i++){
        cin>>Q[i].nd.st>>Q[i].nd.nd>>Q[i].st;
    }
    sort(Q+1,Q+m+1,greater<lll>());
    H[1]=1;
    DFS(1,1);
    for(long i=1; i<=m; i++){
        if(!check(Q[i].nd.st,Q[i].nd.nd,Q[i].st)){
            cout<<-1;
            return 0;
        }
    }
    for(long i=1; i<n; i++) cout<<max(1l,ans[i])<<' ';
}
