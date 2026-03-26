#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define W while
#define I inline
#define RI int
#define LL long long
#define Cn const
#define CI Cn int&
#define gc getchar
#define D isdigit(c=gc())
#define pc(c) putchar((c))
using namespace std;
namespace Debug{
	Tp I void _debug(Cn char* f,Ty t){cerr<<f<<'='<<t<<endl;}
	Ts I void _debug(Cn char* f,Ty x,Ar... y){W(*f!=',') cerr<<*f++;cerr<<'='<<x<<",";_debug(f+1,y...);}
	Tp ostream& operator<<(ostream& os,Cn vector<Ty>& V){os<<"[";for(Cn auto& vv:V) os<<vv<<",";os<<"]";return os;}
	#define gdb(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}using namespace Debug;
namespace FastIO{
	Tp I void read(Ty& x){char c;int f=1;x=0;W(!D) f=c^'-'?1:-1;W(x=(x<<3)+(x<<1)+(c&15),D);x*=f;}
	Ts I void read(Ty& x,Ar&... y){read(x),read(y...);}
	Tp I void write(Ty x){x<0&&(pc('-'),x=-x,0),x<10?(pc(x+'0'),0):(write(x/10),pc(x%10+'0'),0);}
	Tp I void writeln(Cn Ty& x){write(x),pc('\n');}
}using namespace FastIO;
Cn int N=110;
int n,vis[N],col[N];
struct node{int a[27],L;}A,B,lst[N];
I node Mul(node a,int b){for(int i=0;i<26;i++)a.a[i]*=b;return a;}
I node Sub(node a,node b){for(int i=0;i<26;i++)a.a[i]-=b.a[i];return a;}
I node RD(){node t;memset(t.a,0,sizeof(t.a));string s;cin>>s;RI l=s.length(),i;for(t.L=l,i=0;i<l;i++) t.a[s[i]-'a']++;return t;}
#define fi first
#define se second
vector<pair<int,pair<int,int> > > G[N];
#define pb push_back
I void U(CI a,CI b,CI x,CI y){
	if(a==b) return assert(x==y),vis[a]=1,col[a]=x,void();
	G[a].pb({b,{x,y}}),G[b].pb({a,{x,y}});
}
I void Q(CI l,CI r){
	cout<<"? "<<l<<" "<<r<<endl;
	RI i,j,k,m=r-l+1,t=m*(m+1)/2;vector<node> v;
	for(i=0;i<t;i++) v.pb(RD());
	for(i=0;i<t;i++) if(v[i].L==m) A=v[i];
	for(i=1;i<=(m+1)/2;i++){
		B=Mul(A,i+1);for(auto k:v) if(k.L==m-i) B=Sub(B,k);
		for(j=1;j<i;j++) B=Sub(B,Mul(lst[j],i-j+1));
		lst[i]=B;for(j=0;j<26;j++) if(B.a[j]){B.a[j]--;for(k=j;k<26;k++) if(B.a[k]){U(l+i-1,r-i+1,j,k);break ;}break ;}
	}return ;
}
queue<int> q;
int main(){
	RI i,u,y,z,l,r;read(n);
	if(n==1){cout<<"? 1 1"<<endl;string s;cin>>s;cout<<"! "<<s<<endl;return 0;}
	Q(1,n),Q(1,n/2),Q((n+1)/2,n);
	W(!q.empty()) q.pop();
	for(i=1;i<=n;i++) vis[i]&&(q.push(i),0);
	W(!q.empty()){u=q.front(),q.pop();for(auto i:G[u]) y=i.fi,z=col[u]==i.se.fi?i.se.se:i.se.fi,!vis[y]&&(vis[y]=1,col[y]=z,q.push(y),0),assert(col[y]==z);}
	cout<<"! ";for(i=1;i<=n;i++) pc(col[i]+'a');pc('\n');return 0;
}