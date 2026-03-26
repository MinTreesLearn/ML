//#pragma GCC optomize ("Ofast")
//#pragma GCC optomize ("unroll-loops")
//#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
  
#define F first
#define S second 
#define ll long long
#define all(x) (x.begin(), x.end());
#define uint unsigned int
#define pb push_back
#define	ios	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
 
using namespace std;

const ll N=3e5+7 ,INF = 1e18, inf = 1e9 , mod = 1e9+7;

int n,m;

int a[N];
int mn[N];
int mx[N];
int cur[N];
int pred[N];

bool ok[N];

int t[N*4];
int x[N*4];

void upd_x(int pos,int val,int u=1,int ul=1,int ur=n){
	if(ul==ur){
		x[u]=val;
		return;
	}
	int um=(ul+ur)/2;
	if(pos<=um)upd_x(pos,val,u*2,ul,um);
	else upd_x(pos,val,u*2+1,um+1,ur);
	x[u]=x[u*2]+x[u*2+1];
}

int get_x(int l,int r,int u=1,int ul=1,int ur=n){
	if(l<=ul&&ur<=r)return x[u];
	if(ur<l||r<ul)return 0;
	int um=(ul+ur)/2;
	return get_x(l,r,u*2,ul,um)+get_x(l,r,u*2+1,um+1,ur);
}

void upd(int pos,int val,int u=1,int ul=1,int ur=m){
	if(ul==ur){
		t[u]=val;
		return;
	}
	int um=(ul+ur)/2;
	if(pos<=um)upd(pos,val,u*2,ul,um);
	else upd(pos,val,u*2+1,um+1,ur);
	t[u]=t[u*2]+t[u*2+1];
}

int get(int l,int r,int u=1,int ul=1,int ur=m){
	if(l<=ul&&ur<=r)return t[u];
	if(ur<l||r<ul)return 0;
	int um=(ul+ur)/2;
	return get(l,r,u*2,ul,um)+get(l,r,u*2+1,um+1,ur);
}

signed main(){
//  	freopen(".in", "r", stdin);
//  	freopen(".out", "w", stdout);
    ios;
	int tt=1;
//	cin>>tt;
	while(tt--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			mn[i]=i;
			mx[i]=i;
			cur[i]=i;
		}
		for(int i=1;i<=m;i++){
			cin>>a[i];
			mn[a[i]]=1;
			ok[a[i]]=1;
			upd_x(a[i],1);
			if(pred[a[i]]!=0)upd(pred[a[i]],0);
			upd(i,1);
			if(pred[a[i]]==0&&a[i]!=n){
				int val=get_x(a[i]+1,n);
				mx[a[i]]=max(mx[a[i]],min(cur[a[i]]+val,n));
			}
			else{
				int val=get(pred[a[i]],i);
				mx[a[i]]=max(mx[a[i]],min(cur[a[i]]+val-1,n));
			}
			pred[a[i]]=i;
			cur[a[i]]=1;
		}
		for(int i=1;i<=n;i++){
			if(ok[i]){
				int val=get(pred[i]+1,m);
				mx[i]=max(mx[i],min(val+1,n));
			}
		}
		vector<int>v;
		for(int i=1;i<=n;i++)if(!ok[i])v.pb(i);
		int cnt=n;
		for(int i=v.size()-1;i>=0;i--)mx[v[i]]=cnt--;
		for(int i=1;i<=n;i++)cout<<mn[i]<<" "<<mx[i]<<'\n';
	}
}