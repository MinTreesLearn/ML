// LUOGU_RID: 101723561
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define int long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define SZ(x) ((int)(x.size()))
#define INF 0x3f3f3f3f

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

inline void Write(__int128 x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) Write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e6+5;
int n,a[N],s[N],fa[N],up[N],top;
char opt[5];

pair<int,int> st[N];

__int128 ans;

inline int Q(int x)
{
	int l=1,r=top,rs=-1;
	while(l<=r)
	{
		if(st[mid].se>=x)
			rs=st[mid].fi,r=mid-1;
		else l=mid+1;
	}
	return rs;
}

map<int,int> sum;

signed main()
{
	n=read();fa[0]=-1;s[0]=-1;
	int lastans1=0,lastans2=0,lst=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",opt+1);
		int x=opt[1]-'a';
		x=(x+lastans1)%26;s[i]=x;
		if(i!=1)
		{
			if(s[i]!=s[fa[i-1]+1]) up[i-1]=fa[i-1];
			else up[i-1]=up[fa[i-1]];
		}
		int w=read(),res=lst;
		w^=lastans2;a[i]=w;fa[i]=fa[i-1];
		int u=i-1;
		while(u)
		{
			if(s[u+1]==s[i])
				u=up[u];
			else
			{
				int tmp=Q(i-u);
				sum[-tmp]--;res-=tmp;
				u=fa[u];
			}
		}
		while(top&&st[top].fi>=a[i]) --top;
		st[++top]=mp(a[i],i);int nm=0;
		for(auto j=sum.begin();j!=sum.end();)
		{
			if(-j->fi<=a[i]) break;
			res-=(-j->fi-a[i])*j->se;
			nm+=j->se;
			auto tmp=j;++j;sum.erase(tmp);
		}
		if(nm) sum[-a[i]]+=nm;
		if(s[1]==s[i])
		{
			sum[-a[i]]++;
			res+=a[i];
		}
		while(fa[i]!=-1&&s[fa[i]+1]!=s[i])
			fa[i]=fa[fa[i]];
		fa[i]++;
		lst=res;ans+=res;
		lastans1=(lastans1+res)%26;
		lastans2=(lastans2+res)%(1<<30);
		Write(ans);puts("");
	}
	return 0;
}