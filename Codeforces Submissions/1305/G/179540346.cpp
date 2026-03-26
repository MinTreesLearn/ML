// LUOGU_RID: 93094030
#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=3e5+5,M=2e5+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,fa[maxn],cnt[maxn],mx,x;
long long ans;
int find(int x){if(x==fa[x])return x;return fa[x]=find(fa[x]);}
void merge(int x,int y){
	int u=find(x),v=find(y);
	if(u==v)return;
	ans+=1ll*(x+y)*(cnt[u]+cnt[v]-1);fa[u]=v;cnt[v]=1;
}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();cnt[0]++;
	for(int i=1;i<=n;i++)x=read(),cnt[x]++,ans-=x;
	mx=(1<<18)-1;
	for(int i=0;i<=mx;i++)fa[i]=i;
	for(int i=mx;i>=0;i--){
		for(int j=i;j;j=(j-1)&i)if(cnt[j]&&cnt[i^j])merge(j,i^j);
		if(cnt[i])merge(i,0);
	}cout<<ans<<endl;
 	return 0;
}