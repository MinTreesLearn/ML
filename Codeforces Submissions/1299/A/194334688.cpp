#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mk make_pair
#define lowbit(x) (x&(-x))
#define pb emplace_back
#define pr pair<int,int>
#define let const auto
const int N=1e5+5;
int read(){
	int x=0,f=1; char c=getchar();
	while(('0'>c||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=0,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return f?x:-x;
}
int n,a[N],cnt[35];
int main(){
	n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++)
		for(int j=0; j<=30; j++) if(a[i]&(1<<j)) cnt[j]++;
	auto calc = [&](int i){
		int res=0;
		for(int j=0; j<=30; j++) if((a[i]&(1<<j))&&cnt[j]==1) res|=1<<j;
		return res;
	};
	int Max=calc(1),p=1;
	for(int i=2,v; i<=n; i++) if((v=calc(i))>Max) Max=v,p=i;
	printf("%d ",a[p]);
	for(int i=1; i<=n; i++) if(i!=p) printf("%d ",a[i]);
	puts("");
	return 0;
}
