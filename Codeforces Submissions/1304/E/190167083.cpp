#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define N 100005
ll q,n,m,k,ans=0,x,y,l,r,s,z;
ll lg[N],fa[N][21];
ll dep[N];
ll cnt=0,head[N];
bool flag;
struct edge{
	ll x,y;
}e[2*N];
template<typename T>inline void read(T &n){
	T w=1; n=0; char ch=getchar();
	while (!isdigit(ch) && ch!=EOF){ if (ch=='-') w=-1; ch=getchar(); }
	while (isdigit(ch) && ch!=EOF){ n=(n<<3)+(n<<1)+(ch&15); ch=getchar(); }
	n*=w;
}
template<typename T>inline void write(T x){
	if (x==0){ putchar('0'); return ; }
	T tmp;
	if (x>0) tmp=x;
	else tmp=-x;
	if (x<0) putchar('-');
	char F[105];
	long long cnt=0;
	while (tmp){
		F[++cnt]=tmp%10+48;
		tmp/=10;
	}
	while (cnt) putchar(F[cnt--]);
}
void addedge(ll x,ll y){
	cnt++;
	e[cnt].x=head[x];
	e[cnt].y=y;
	head[x]=cnt;
	return ;
}
void dfs(ll x,ll father){
	fa[x][0]=father;
	ll i; ll go;
	for (i=head[x]; i; i=e[i].x){
		go=e[i].y;
		if (go==father) continue;
		dep[go]=dep[x]+1;
		dfs(go,x);
	}
	return ;
}
void init(){
	ll i,j;
	lg[1]=0;
	for (i=2; i<=n; i++) lg[i]=lg[i>>1]+1;
	for (i=1; (1<<i)<=n; i++)
		for (j=1; j<=n; j++)
			if (fa[j][i-1]>0 && fa[fa[j][i-1]][i-1]>0) 
				fa[j][i]=fa[fa[j][i-1]][i-1];
	return ;
}
ll Lca(ll x,ll y){
	ll i; ll k;
	if (dep[x]<dep[y]) swap(x,y);
	k=lg[dep[x]-dep[y]];
	for (i=k; i>=0; i--)
		if (dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if (x==y) return x;
	k=lg[dep[x]];
	for (i=k; i>=0; i--)
		if (fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
ll dist(ll x,ll y){
	ll l=Lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}
bool check(ll x,ll y){
	if (x>y) return false;
	if (x%2!=y%2) return false;
	return true;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    ll i,j;
    read(n);
    for (i=2; i<=n; i++){
    	read(x); read(y);
    	addedge(x,y);
    	addedge(y,x);
	}
	dep[1]=1;
	dfs(1,-1);
	init();
	read(q);
	while (q--){
		read(x); read(y); read(l); read(r); read(k);
		flag=false;
		flag |= check ( dist(l,r) , k );
		flag |= check ( dist(l,x) + dist(r,y) + 1 , k );
		flag |= check ( dist(l,y) + dist(r,x) + 1 , k );
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}