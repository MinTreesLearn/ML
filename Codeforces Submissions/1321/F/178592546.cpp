#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define re register
#define il inline
#define hash unorded_map
typedef long long lng;
typedef unsigned long long ulng;
typedef vector<int> veci;
#define fo(i,st,xb,y) for(re int i=st;i xb;i y)
#define N 200000
#define mod 998244353 //模数为998244353
#define base 5119 //5119进制
char s[N+10];
int n,m,h[N+10][2],bs[N+10]={1},ze[N+10];
il int Hash(re int l,re int r,re int o){return (-1ll*h[l-1][o]*bs[ze[r]-ze[l-1]]%mod+h[r][o]+mod)%mod;} //子序列哈希值
int main(){
	scanf("%d%s",&n,s+1);  
	fo(i,1,<=n,++)
		if(s[i]=='1') h[i][0]=h[i-1][0],h[i][1]=h[i-1][1],ze[i]=ze[i-1];
		else h[i][0]=(1ll*h[i-1][0]*base%mod+1+(i&1))%mod,
			h[i][1]=(1ll*h[i-1][1]*base%mod+1+((i&1)^1))%mod,ze[i]=ze[i-1]+1;
	fo(i,1,<=n,++) bs[i]=1ll*bs[i-1]*base%mod;
	scanf("%d",&m); fo(i,1,<=m,++){
		re int l1,l2,len; scanf("%d%d%d",&l1,&l2,&len);
		(Hash(l1,l1+len-1,l1&1)==Hash(l2,l2+len-1,l2&1)?puts("Yes"):puts("No"));
	}
	return 0;
}