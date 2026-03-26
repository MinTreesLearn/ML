// LUOGU_RID: 100224854
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
#define N 200005
ll n,m,k,ans=0,x,y,l,r,s,z;
ll cnt=0,head[N];
struct edge{
	ll x,y,col,id;
}e[2*N];
ll d[N];
bool flag[N];
ll col[N];
struct point{
	ll d,id;
}a[N];
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
void addedge(ll x,ll y,ll id){
	cnt++;
	e[cnt].x=head[x];
	e[cnt].y=y;
	e[cnt].col=-1;
	e[cnt].id=id;
	head[x]=cnt;
	return ;
}
bool cmp(point x,point y){
	return x.d>y.d;
}
void dfs(ll x,ll fa,ll c){
//	printf("%lld : c = %lld \n",x,c);
	ll i; ll go;
	if (flag[x]){
		if (x==1) c=1;
		for (i=head[x]; i; i=e[i].x){
			go=e[i].y;
			if (go==fa) continue;
			e[i].col=c;
			dfs(go,x,c);
		}
	}
	else {
		ll col=0;
		for (i=head[x]; i; i=e[i].x){
			go=e[i].y;
			if (go==fa) continue;
			col++;
			if (col==c) col++;
			e[i].col=col;
			dfs(go,x,col);
		}
	}
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
    ll i,j;
    read(n); read(k);
    for (i=2; i<=n; i++){
    	read(x); read(y);
    	addedge(x,y,i);
    	addedge(y,x,i);
    	d[x]++; d[y]++;
	}
	for (i=1; i<=n; i++) {
		a[i].d=d[i];
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for (i=1; i<=k; i++) flag[a[i].id]=true;
	ans=a[k+1].d;
	write(ans); putchar('\n');
	dfs(1,-1,-1);
	for (i=1; i<=cnt; i++){
		if (e[i].col==-1) continue;
		col[e[i].id]=e[i].col;
	}
	for (i=2; i<=n; i++) {
		write(col[i]); putchar(' ');
	}
    return 0;
}