// LUOGU_RID: 102634965
#include<bits/stdc++.h>
//#define feyn
#define int long long
#define ll __int128
using namespace std;
const int N=200010;
const int mod=1e15+7;
inline void read(int &wh){
    wh=0;int f=1;char w=getchar();
    while(w<'0'||w>'9'){if(w=='-')f=-1;w=getchar();}
    while(w<='9'&&w>='0'){wh=wh*10+w-'0';w=getchar();}
    wh*=f;return;
}

int m,n,cnt[N];
char w[N];

int p[N]={1},aa[N],bb[N],pl[N];
inline int get(int l,int r,int a[]){
	ll now=(ll)a[r]-(ll)a[l-1]*p[r-l+1];
	return (now%mod+mod)%mod; 
}

signed main(){
	
	#ifdef feyn
	freopen("in.txt","r",stdin);
	#endif
	
	read(m);scanf("%s",w+1);int num=0;
	for(int i=1;i<=m;i++)cnt[i]=cnt[i-1]+(w[i]=='0');
	for(int i=1;i<=m;i++)if(w[i]=='0')pl[++num]=i&1;
	for(int i=1;i<=num;i++){
		p[i]=p[i-1]*2%mod;
		aa[i]=(aa[i-1]*2ll+pl[i])%mod;
		bb[i]=(bb[i-1]*2ll+1-pl[i])%mod;
	}
	read(n);
	while(n--){
		int x,y,len;read(x);read(y);read(len);
		if(cnt[x+len-1]-cnt[x-1]!=cnt[y+len-1]-cnt[y-1]){
			puts("No");continue;
		}
		if((x&1)==(y&1)){
			if(get(cnt[x-1]+1,cnt[x+len-1],aa)==get(cnt[y-1]+1,cnt[y+len-1],aa))puts("Yes");
			else puts("No");
		}
		else{
			if(get(cnt[x-1]+1,cnt[x+len-1],aa)==get(cnt[y-1]+1,cnt[y+len-1],bb))puts("Yes");
			else puts("No");
		}
	}
	
	return 0;
}