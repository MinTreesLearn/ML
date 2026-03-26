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
int n,x[N],y[N];
int main(){
	n=read();
	for(int i=1; i<=n; i++) x[i]=read(),y[i]=read();
	if(n&1) return puts("NO"),0;
	int sx=x[1]+x[n/2+1],sy=y[1]+y[n/2+1]; 
	for(int i=2; i<=n/2; i++)
		if(x[i]+x[n/2+i]!=sx||y[i]+y[n/2+i]!=sy) return puts("NO"),0;
	puts("YES");
	return 0;
}
