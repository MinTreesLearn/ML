//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define yes puts("YES")
#define no puts("NO")
#define mk make_pair
#define pii pair<int,int>
#define F first
#define S second
#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=2e5+7;

//int read(){	int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-') f=f*-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
//void write(int x){if(x>9) write(x/10);putchar(x%10+'0');}

namespace IO{
	const int sz=1<<22;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
	//	return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin),p1==p2?EOF:*p1++):*p1++;
		return getchar();
	}
	template<class T> void gi(T& x){
		x=0; int f=1;char c=gc();
		if(c=='-')f=-1;
		for(;c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(;c>='0'&&c<='9';c=gc())
			x=x*10+(c-'0');
		x=x*f;
	}
	inline void flush(){fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){*t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x<0)pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
	struct F{~F(){flush();}}f; 
}

int n,x[N],y[N];

void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>x[i]>>y[i];
	if(n&1){
		cout<<"NO\n";
		return;
	}
	int cx=(x[1]+x[n/2+1]),cy=(y[1]+y[n/2+1]);
	for(int i=2;i<=n/2;++i){
		int nx=(x[i]+x[n/2+i]),ny=(y[i]+y[n/2+i]);
		if(nx!=cx||ny!=cy){
			cout<<"NO\n";
			return; 
		}
	}
	cout<<"YES\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//  freopen("in.cpp","r",stdin);
//  freopen("out.cpp","w",stdout);
	int T=1;
//	cin>>T;
//	clock_t start,finish;
//	start=clock();
	while(T--){
		Solve();
	}
//	finish=clock();
//	cerr<<((double)finish-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}