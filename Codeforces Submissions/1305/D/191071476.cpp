// LUOGU_RID: 100771727
#define poj
//#define zcz
#ifdef poj
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<stack>
#include<map>
#else
#include<bits/stdc++.h>
#endif
using namespace std;
#ifdef zcz
class fastin{
	private:
#ifdef poj
	static const int MAXBF=1<<20;
#else
	const int MAXBF=1<<27;
#endif
	FILE *inf;
	char *inbuf,*inst,*ined;
	inline char _getchar(){
		if(inst==ined)inst=inbuf,ined=inbuf+fread(inbuf,1,MAXBF,inf);
		return inst==ined?EOF:*inst++;
	}
	public:
	fastin(FILE*_inf=stdin){
		inbuf=new char[MAXBF],inf=_inf,inst=inbuf,ined=inbuf;
	}
	~fastin(){delete inbuf;}
	template<typename Int> fastin&operator>>(Int &n){
		static char c;
		Int t=1;
		while((c=_getchar())<'0'||c>'9')if(c=='-')t=-1;
		n=(c^48);
		while((c=_getchar())>='0'&&c<='9')n=(n<<3)+(n<<1)+(c^48);
		n*=t;
		return*this;
	}
	fastin&operator>>(char*s){
		int t=0;
		static char c;
		while((c=_getchar())!=' '&&c!='\n')s[t++]=c;
		s[t]='\0';
		return *this;
	}
}fi;
class fastout{
	private:
#ifdef poj
	static const int MAXBF=1<<20;
#else
	const int MAXBF=1<<27;
#endif
	FILE *ouf;
	char *oubuf,*oust,*oued;
	inline void _flush(){fwrite(oubuf,1,oued-oust,ouf);}
	inline void _putchar(char c){
		if(oued==oust+MAXBF)_flush(),oued=oubuf;
		*oued++=c;
	}
	public:
	fastout(FILE*_ouf=stdout){
		oubuf=new char[MAXBF],ouf=_ouf,oust=oubuf,oued=oubuf;
	}
	~fastout(){_flush();delete oubuf;}
	template<typename Int> fastout&operator<<(Int n){
		if(n<0)_putchar('-'),n=-n;
		static char S[20];
		int t=0;
		do{S[t++]='0'+n%10,n/=10;}while(n);
		for(int i=0;i<t;++i)_putchar(S[t-i-1]);
		return*this;
	}
	fastout&operator<<(char c){_putchar(c);return *this;}
	fastout&operator<<(char*s){
		for(int i=0;s[i];++i)_putchar(s[i]);
		return *this;
	}
}fo;
#define cin fi
#define cout fo
#else
#define czc ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#endif
#define mod 1000000007
#define ll long long
#define isinf 0x3f3f3f3f
#define ilinf 0x7fffffff
#define lsinf 0x3f3f3f3f3f3f3f3f
#define llinf 0x7fffffffffffffff
int n,f[1010][1010],g[1000],u,v,vis[1010];
queue<int> q;
int main(){
//	#ifndef zcz
//	czc;
//	#endif
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		f[u][v]=f[v][u]=1;
		++g[u];++g[v];
	}
	for(int i=1;i<=n;i++){
		if(g[i]==1)q.push(i);
	}
	while(q.size()>=2){
		u=q.front();q.pop();
		v=q.front();q.pop();
		vis[u]=vis[v]=1;
		cout<<"? "<<u<<' '<<v<<'\n';
		cout.flush();
		int lca;
		cin>>lca;
		if(lca==u||lca==v){
			cout<<"! "<<lca;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(f[u][i]){
				g[i]--;
				if(g[i]==1)q.push(i);
			}
			if(f[v][i]){
				g[i]--;
				if(g[i]==1)q.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		cout<<"! "<<i<<'\n';
		return 0;
	}
	return 0;
}