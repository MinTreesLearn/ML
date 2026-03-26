                                    //  ॐ
#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
#define ll long long int

vector<int> adj[1005],good(1005,1);

int query(int u,int v){
    cout<<"? "<<u<<' '<<v<<'\n';
    int ret;
    cin>>ret;
    assert(ret!=-1);
    return ret;
}

int bfs(int st,int n){
    deque<int> q;
    vector<int> dis(n+1,-1);
    q.push_back(st);
    dis[st]=0;
    int last;

    while(!q.empty()){
        int v=q.front();
        q.pop_front();
        
        if(good[v])
         last=v;

        for(auto u : adj[v]){
              if(dis[u]==-1){
                   if(!good[u]){
                       dis[u]=dis[v];
                       q.push_front(u);
                   }

                   else{
                       dis[u]=dis[v]+1;
                       q.push_back(u);
                   }
              }
        }
    }
    
    assert(dis[last]>0);
    return last;
}

void del_path(int a,int b,int n){
    queue<int> q;
    vector<int> dis(n+1,-1),par(n+1);
    q.push(a);
    dis[a]=0;

    while(!q.empty()){
        int v=q.front();
        q.pop();
     

        for(auto u : adj[v]){
              if(dis[u]==-1){
                   dis[u]=dis[v]+1;
                   q.push(u);
                   par[u]=v;
              }
        }
    }

    int curr=b;
    while(curr!=a){
        good[curr]=0;
        curr=par[curr];
    }

}

int main(){
   
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
 
    int test = 1;
    // cin>>test;

    while(test--){
                          
                          int n;
                          cin>>n;

                          int cnt=n;
                          
                          for(int i=1;i<n;i++){
                               int a,b;
                               cin>>a>>b;
                               adj[a].push_back(b);
                               adj[b].push_back(a);
                          }
                          

                          while(cnt>=2){
                              int root;
                              for(int i=1;i<=n;i++){
                                  if(good[i]){
                                      root=i;
                                  }
                              }

                              int first=bfs(root,n);
                              int second=bfs(first,n);
                              int lca=query(first,second);

                              if(lca==first || lca==second){
                                  cout<<"! "<<lca<<'\n';
                                  return 0;
                              }

                              del_path(lca,first,n);
                              del_path(lca,second,n);
                              cnt=0;

                              for(int i=1;i<=n;i++){
                                   cnt+=good[i];
                              }
                          }

                          int ans;

                          for(int i=1;i<=n;i++){
                               if(good[i]){
                                  ans=i;
                               }
                          }

                          cout<<"! "<<ans;

                              
                          cout<<'\n';
        
   }
        return 0;
}