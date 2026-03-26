#include<bits/stdc++.h>
clock_t cl=clock();
#define ll long long
#define Il inline
#define mem(u,v) memset(u,v,sizeof(u))
#define rep(i,a,b) for(ll i=(a),KKK##i=(b);i<=KKK##i;i++)
#define drep(i,a,b) for(ll i=(a),KKK##i=(b);i>=KKK##i;i--)
#define go(u) for(ll i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
#define writesp(x) write(x),putchar(' ')
#define writeln(x) write(x),puts("")
//#define getchar nc
using namespace std;
inline char nc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
Il ll read(){ll sum=0,f=0;char ch=getchar();for(;!isdigit(ch);ch=getchar())f|=(ch=='-');for(;isdigit(ch);ch=getchar())sum=((sum<<1)+(sum<<3)+(ch^48));return f?-sum:sum;}
void write(const ll x){if(x<0){putchar('-');write(-x);return;}if(x>9)write(x/10);putchar(x%10+'0');}
char getc(){char c=getchar();while(!isalpha(c))c=getchar();return c;}
#define N 1100
#define pii pair<ll,ll>
#define MP make_pair
#define fi first
#define se second
ll n,m,k,m2[N],s[N],B,f[N][N],sum[N][N],lcp[N][N],tot;
pii b[N*N];
const ll M=1e9+7;char a[N];
ll gh(ll x,ll y){
	return (s[y]-s[x-1]*m2[y-x+1]%M+M)%M;
}
ll gl(ll x,ll y,ll k){
	ll l=0,r=k;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(gh(x,x+mid-1)==gh(y,y+mid-1))l=mid;
		else r=mid-1;
	}
	return l;
}
bool cmp(pii x,pii y){
	ll t=lcp[x.fi][y.fi],l1=x.se-x.fi+1,l2=y.se-y.fi+1;
//	cout<<lcp[1][4]<<endl;
//	cout<<t<<endl;
	if(t>=min(l1,l2))return l1<=l2;
	return a[x.fi+t]<a[y.fi+t];
}
ll solve(pii tmp){
	ll x=tmp.fi,len=tmp.se-tmp.fi+1;
	mem(f,0);mem(sum,0);
	f[n+1][0]=1;sum[n+1][0]=1;
	drep(i,n,1){
		ll p=lcp[x][i],t=n+2;
		if(p>=min(len,n-i+1)){
			if(len>n-i+1)t=n+2;
			else t=i+len-1;
		}
		else{
			if(a[tmp.fi+p]>a[i+p])t=n+2;
			else if(a[tmp.fi+p]==a[i+p])t=i+p-1;
			else t=i+p;
		}
//		cout<<"DE"<<i<<' '<<t<<endl;
		rep(j,1,m)f[i][j]=sum[t+1][j-1];
		rep(j,0,m)sum[i][j]=min(sum[i+1][j]+f[i][j],k);
	}
	
//	rep(i,1,n+1){
//		rep(j,0,m)cout<<f[i][j]<<" ";puts("");
//	}
//	rep(i,1,n+1){
//		rep(j,0,m)cout<<sum[i][j]<<" ";puts("");
//	}
	return f[1][m];
}
int main(){
	srand(time(0));
	n=read();m=read();k=read();
	rep(i,1,n)a[i]=getc();
	B=13+rand()%20;
	m2[0]=1;rep(i,1,n)m2[i]=m2[i-1]*B%M;
	rep(i,1,n)s[i]=(s[i-1]*B+(a[i]-'a'+1))%M;
	rep(i,1,n)rep(j,1,n)lcp[i][j]=gl(i,j,min(n-i+1,n-j+1));
	rep(i,1,n)rep(j,i,n)b[++tot]=MP(i,j);
	sort(b+1,b+tot+1,cmp);
//	rep(i,1,tot){
//		rep(j,b[i].fi,b[i].se)cout<<(char)a[j];puts("");
//	}
//	cout<<solve(MP(1,3))<<endl;
//	cout<<solve(MP(1,3))<<endl;
	ll l=1,r=tot;
	while(l<r){
		ll mid=(l+r+1)>>1;
		if(solve(b[mid])>=k)l=mid;
		else r=mid-1;
	}
	rep(i,b[l].fi,b[l].se)putchar(a[i]);
}
   		  		 	 			       	   				