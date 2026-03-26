// LUOGU_RID: 96148485
#define FASTIO
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define SZ(v) ((int)v.size())
#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
template<typename T1,typename T2>void chkmin(T1 &x,T2 y){if(x>y)x=y;}
template<typename T1,typename T2>void chkmax(T1 &x,T2 y){if(x<y)x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1<<23
char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
#ifdef LOCAL
inline char getc(){return getchar();}
inline void putc(char c){putchar(c);}
#else
inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
inline void putc(char x){*p3++=x;}
#endif
template<typename T>void read(T &x){
	x=0;char c=getc();T neg=0;
	while(!isdigit(c))neg|=(c=='-'),c=getc();
	while(isdigit(c))x=x*10+(c-'0'),c=getc();
	if(neg)x=-x;
}
template<typename T>void recursive_print(T x){if(!x)return;recursive_print(x/10);putc(x%10^48);}
template<typename T>void print(T x){if(!x)putc('0');if(x<0)putc('-'),x=-x;recursive_print(x);}
template<typename T>void print(T x,char c){print(x);putc(c);}
void readstr(char *s){char c=getc();while(c<=32||c>=127)c=getc();while(c>32&&c<127)s[0]=c,s++,c=getc();(*s)=0;}
void printstr(string s){for(int i=0;i<s.size();i++)putc(s[i]);}
void printstr(char *s){int len=strlen(s);for(int i=0;i<len;i++)putc(s[i]);}
void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
#endif
const int MAXQ=2e6;
const int MAXN=300;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,qu,x[MAXQ+5],y[MAXQ+5],c[MAXQ+5],a[MAXN+5][MAXN+5],res[MAXQ+5];
int b[MAXN+5][MAXN+5],pre[MAXN+5][MAXN+5],f[MAXN*MAXN+5];
int getid(int x,int y){return (x-1)*m+y;}
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
bool merge(int x,int y){x=find(x);y=find(y);if(x!=y)return f[x]=y,1;return 0;}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	read(n);read(m);read(qu);
	for(int i=1;i<=qu;i++)read(x[i]),read(y[i]),read(c[i]);
	for(int l=1,r;l<=qu;l=r){
		r=l;while(r<=qu&&c[r]==c[l])++r;
		for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)b[j][k]=-1;
		for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)pre[j][k]=a[j][k];
		static tuple<int,int,int,int>vec[MAXN*MAXN+5];
		int C=0;
		for(int j=l;j<r;j++)if(pre[x[j]][y[j]]!=c[j])
			vec[++C]=mt(x[j],y[j],pre[x[j]][y[j]],j-1),pre[x[j]][y[j]]=c[j];
		for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)if(pre[j][k]!=c[l])
			vec[++C]=mt(j,k,pre[j][k],r);
		reverse(vec+1,vec+C+1);
		for(int j=1;j<=n*m;j++)f[j]=0;int cmp=0;
		for(int j=l;j<r;j++){
			if(a[x[j]][y[j]]!=c[j]){
				cmp++;
				for(int d=0;d<4;d++){
					int xx=x[j]+dx[d],yy=y[j]+dy[d];
					if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]!=c[j])continue;
					cmp-=merge(getid(x[j],y[j]),getid(xx,yy));
				}a[x[j]][y[j]]=c[j];
			}res[j]+=cmp;
		}
		for(int j=1;j<=n*m;j++)f[j]=0;cmp=0;
		for(int j=r-1,k=1;j>=l;j--){
			while(k<=C&&get<3>(vec[k])>=j){
				int X=get<0>(vec[k]),Y=get<1>(vec[k]),V=get<2>(vec[k]);cmp++;
				for(int d=0;d<4;d++){
					int xx=X+dx[d],yy=Y+dy[d];
					if(xx<1||xx>n||yy<1||yy>m||b[xx][yy]!=V)continue;
					cmp-=merge(getid(X,Y),getid(xx,yy));
				}b[X][Y]=V;++k;
			}res[j]+=cmp;
		}
	}
	for(int i=1;i<=qu;i++)print(res[i],'\n');
	print_final();
	return 0;
}