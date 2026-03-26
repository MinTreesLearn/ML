#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y,z;
}t[1000011];
const int mod=1000000007;
int n,m,sum,x[200011],y[200011],z[200011],h[200011],f[200011],val[200011],ans,p[11],idx[200011],cnt,g[511][11],son[511][511],idd[41],ss[2][2][511],la,col[200011],dep[200011],vis[41];
bool fl[200011];
queue<int> qx,qy,qz;
map<int,int> mp;
void link(int a,int b,int c){
	cnt++;
	t[cnt].x=b;
	t[cnt].y=h[a];
	t[cnt].z=c;
	h[a]=cnt;
}
int add(int a,int b){
	if(a+b>=mod)return a+b-mod;
	return a+b;
}
int del(int a,int b){
	if(a-b<0)return a-b+mod;
	return a-b;
}
int mul(int a,int b){
	return ((int)(1ll*a*b%mod));
}
int ksm(int a,int b){
	int s=1;
	while(b){
		if(b&1)s=mul(s,a);
		a=mul(a,a);
		b=(b>>1);
	}
	return s;
}
bool ins(int a){
	for(int i=4;i>=0;i--){
		if((a&(1<<i))==0)continue;
		a=a^p[i];
	}
	if(a==0)return 0;
	for(int i=4;i>=0;i--){
		if(a&(1<<i)){
			for(int j=4;j>i;j--){
				if(p[j]&(1<<i)){
					p[j]=p[j]^a;
				}
			}
			p[i]=a;
			break;
		}
	}
	return 1;
}
int find(){
	int s=0;
	for(int i=0;i<=4;i++)s=s*32+p[i];
	return s;
}
void dfs(int a){
	if(a>=32){
		int c=find();
		if(!mp[c]){
			sum++;
			mp[c]=sum;
			int s=0;
			for(int i=4;i>=0;i--){
				g[sum][i]=p[i];
				if(p[i]>0)s++;
			}
			if(s==0)idd[0]=sum;
			if(s==1){
				for(int i=4;i>=0;i--){
					if(p[i]>0){
						s=p[i];
						break;
					}
				}
				idd[s]=sum;
			}
		}
		return;
	}
	dfs(a+1);
	int ss[11];
	for(int i=0;i<=4;i++)ss[i]=p[i];
	if(ins(a))dfs(a+1);
	for(int i=0;i<=4;i++)p[i]=ss[i];
}
int getson(int a,int b){
	for(int i=0;i<=4;i++)p[i]=g[a][i];
	for(int i=0;i<=4;i++){
		if(g[b][i]==0)continue;
		if(!ins(g[b][i]))return 0;
	}
	return mp[find()];
}
void down(int a,int fa){
	fl[a]=1;
	for(int i=h[a];i;i=t[i].y){
		if(t[i].x==1||t[i].x==fa)continue;
		if(fl[t[i].x]){
			vis[dep[a]^dep[t[i].x]^t[i].z]++;
		}else{
			dep[t[i].x]=dep[a]^t[i].z;
			down(t[i].x,a);
		}
	}
}
int build(int a){
	for(int i=0;i<32;i++)vis[i]=0;
	for(int i=0;i<=4;i++)p[i]=0;
	dep[a]=0;
	down(a,0);
	if(vis[0]>0)return 0;
	for(int i=1;i<32;i++){
		if(vis[i]>2)return 0;
		if(vis[i]){
			if(!ins(i)){
				return 0;
			}
		}
	}
	return mp[find()];
}
int main(){
	dfs(1);
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			son[i][j]=getson(i,j);
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=-1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		if(x[i]>y[i])swap(x[i],y[i]);
		if(x[i]==1)f[y[i]]=z[i];
		link(x[i],y[i],z[i]);
		link(y[i],x[i],z[i]);
	}
	cnt=0;
	for(int i=1;i<=m;i++){
		if(f[x[i]]>=0&&f[y[i]]>=0){
			cnt++;
			idx[cnt]=x[i];
			val[cnt]=-1;
			cnt++;
			idx[cnt]=y[i];
			val[cnt]=f[x[i]]^f[y[i]]^z[i];
			f[x[i]]=-1;
			f[y[i]]=-1;
			col[x[i]]=build(x[i]);
			col[y[i]]=col[x[i]];
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i]<0)continue;
		col[i]=build(i);
		cnt++;
		idx[cnt]=i;
		val[cnt]=-1;
	}
	la=0;
	ss[0][0][idd[0]]=1;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=sum;j++){
			ss[la^1][0][j]=0;
			ss[la^1][1][j]=0;
		}
		for(int j=1;j<=sum;j++){
			ss[la^1][0][j]=add(ss[la^1][0][j],add(ss[la][0][j],ss[la][1][j]));
			if(col[idx[i]]>0){
				int c=son[j][col[idx[i]]];
				if(c>0)ss[la^1][1][c]=add(ss[la^1][1][c],ss[la][0][j]);
				if(val[i]<0)ss[la^1][1][c]=add(ss[la^1][1][c],ss[la][1][j]);
				else if(val[i]>0){
					c=son[j][idd[val[i]]];
					if(c>0)ss[la^1][1][c]=add(ss[la^1][1][c],ss[la][1][j]);
				}
			}
		}
		la=(la^1);
	}
	for(int i=1;i<=sum;i++)ans=add(ans,add(ss[la][0][i],ss[la][1][i]));
	printf("%d\n",ans);
} 
