#include<bits/stdc++.h>
using namespace std;
int dp[51][20009];
int a[51][20009];
int pf[51][20009];
int st[80009];
int lazy[80009];
void push(int id){
if (lazy[id]==0)return;
st[id*2]+=lazy[id];
st[id*2+1]+=lazy[id];
lazy[id*2]+=lazy[id];
lazy[id*2+1]+=lazy[id];
lazy[id]=0;
}
void update(int id,int l,int r,int u,int v,int val){
if (l>v||r<u||u>v)return;
if (u<=l&&r<=v){
    st[id]+=val;
    lazy[id]+=val;
    return;
}
int mid=(l+r)/2;
push(id);
update(id*2,l,mid,u,v,val);
update(id*2+1,mid+1,r,u,v,val);
st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
if (l>v||r<u||u>v)return 0;
if (u<=l&&r<=v){
    return st[id];
}
push(id);
int mid=(l+r)/2;
return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
signed main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(nullptr);
	//freopen("usaco.INP","r",stdin);
	//freopen("usaco.ANS","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>a[i][j];
            pf[i][j]=pf[i][j-1]+a[i][j];
        }
	}
	for (int i=k;i<=m;i++){
        dp[1][i]=pf[1][i]-pf[1][i-k];
	}
	for (int i=2;i<=n;i++){
        deque<int>id;
        memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
        for (int j=k;j<=m;j++){
            update(1,1,m,j,j,dp[i-1][j]);
        }
        for (int j=k;j<=m;j++){
            while (!id.empty()&&j-1-k>=id.front())id.pop_front();
            if (!id.empty()){
                int fi=id.front(),se=id.back();
                update(1,1,m,fi,se,a[i][j-k]);
                //cerr<<fi<<" "<<se<<" "<<j<<'\n';
            }
            dp[i][j]=get(1,1,m,k,j)+pf[i][j]-pf[i][j-k];
            //if (i==4&&j==m)cerr<<pf[i][j]-pf[i][j-k]<<'\n';
            id.push_back(j);
        }
        memset(st,0,sizeof(st));
        memset(lazy,0,sizeof(lazy));
        for (int j=k;j<=m;j++){
            update(1,1,m,j,j,dp[i-1][j]);
        }
        id.clear();
        for (int j=m;j>=k;j--){
            while (!id.empty()&&id.front()-k>=j+1)id.pop_front();
            if (!id.empty()){
                int fi=id.back(),se=id.front();
                update(1,1,m,fi,se,a[i][j+1]);
                //cerr<<fi<<" "<<se<<" "<<i<<" "<<j<<'\n';
            }
            dp[i][j]=max(dp[i][j],get(1,1,m,j,m)+pf[i][j]-pf[i][j-k]);
            id.push_back(j);
        }
	}
	int ans=0;
	for (int i=k;i<=m;i++){
        ans=max(ans,dp[n][i]);
	}
	cout<<ans;
}

