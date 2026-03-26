#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;
#define boost ios::sync_with_stdio(0); cin.tie(0) 
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define YES cout<<"YES"<<"\n";
#define NO cout<<"NO"<<"\n";


/***************************************************************************/
const int N= 2e5+1;
int n;
std::vector<pair<int,int>> graph[N];
int colour[N];
int cols[N];
void dfs(int vertex,int num,int par=0){
    int col=1;
    cols[num]=-1;
    int i=1;
    for(auto p: graph[vertex]){
        int x=p.fi,in= p.se;
        if(x==par)   continue;
        if(cols[i]==-1) i++;
        colour[in]= cols[i++];
    }
    cols[num]=num;
    for(auto p: graph[vertex]){
        int x=p.fi,in= p.se;
        if(x==par)   continue;
        dfs(x,colour[in],vertex);
    }
    return;
}

int main(){
    boost; 
    int k;
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    int sizes[n];
    for(int i=0;i<n;i++){
        sizes[i]= graph[i+1].size();
    }
    sort(sizes,sizes+n);
    int greater=0,last=sizes[n-1];
    int ans=n-1;
    int curr_freq=0;
    // for(int i=0;i<n;i++){
    //     cout<<sizes[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=n-1;i>=0;i--){
        if(last>sizes[i])   greater++;
        else{
            if(i!=n-1)
            curr_freq++;
        }
        if(last!=sizes[i]){
            greater+= curr_freq;
            curr_freq=0;
        }
        if(greater>k){
            break;
        }
        last=sizes[i];
        ans=sizes[i];
    }
    cout<<ans<<"\n";
    int num=1;
    for(int i=1;i<=n+1;i++){
        cols[i]=num;
        num++;
        num%=ans;
        if(num==0)  num=ans;
    }
    dfs(1,0);
    for(int i=0;i<n-1;i++){
        cout<<colour[i]<<" ";
    }
    cout<<"\n";
}