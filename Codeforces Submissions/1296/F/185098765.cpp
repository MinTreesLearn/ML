#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
const int INF=1e9;
struct edge{
    int to,idx,val,id;
    edge(){}
    edge(int a,int b,int c,int d){
        to=a,idx=b,val=c,id=d;
    }
};
struct qry{
    int a,b,c;
    qry(){}
    qry(int a1,int b1,int c1){a=a1,b=b1,c=c1;}
};

int n;
vector<vector<edge>> adj;
int cnt=0;
int from=0,goal=0;
int mn=0;
bool dfs(int k,int pa){
    if(k==goal){
        return 1;
    }
    for(edge &e:adj[k]){
        if(e.to==pa){
            continue;
        }
        if(dfs(e.to,k)){
            if(e.val<=mn){
                cnt++;
                e.val=mn;
                adj[e.to][e.idx].val=mn;
            }
            return 1;
        }
    }
    return 0;
}

int main(){
    cin>>n;
    adj.resize(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].push_back(edge(b,adj[b].size(),-INF,i));
        adj[b].push_back(edge(a,adj[a].size()-1,-INF,i));
    }
    int q;cin>>q;
    vector<qry> ask(q);
    for(int i=0;i<q;i++){
        int a,b,c;cin>>a>>b>>c;
        ask[i]=qry(a-1,b-1,c);
    }
    sort(all(ask),[&](qry a,qry b){return a.c>b.c;});
    for(int i=0;i<q;i++){
        int a,b,c;
        a=ask[i].a;
        b=ask[i].b;
        c=ask[i].c;
        cnt=0;
        mn=c;
        from=a;
        goal=b;
        dfs(a,a);
        if(cnt==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    vector<int> ans(n-1);
    for(int i=0;i<n;i++){
        for(edge &e:adj[i]){
            ans[e.id]=e.val;
        }
    }
    for(int j:ans){
        if(j==-INF){
            j=1000000;
        }
        cout<<j<<' ';
    }

    return 0;
}
