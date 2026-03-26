#include<bits/stdc++.h>
using namespace std;
typedef __int128 I;
typedef pair<I,I> Pair;
typedef unsigned long long ull;
const ull P=18446744073709551615ull;

ull val[70][70],res[9][9][260][260],x,y;
int q,Log[300],vis[70][70];
I a[8]={0,3,5,17,257,641,65537,6700417},b[8],m[8];
unordered_map<ull,int> Map;

ull multiply(ull a, ull b);
ull multiply2(int x, int y);

ull multiply(ull a, ull b){
	ull ans=0;
	for (int i=0; i<64; i++)
		for (int j=0; j<64; j++)
			if (((a>>i)&1) && ((b>>j)&1)) ans^=multiply2(i,j);
	return ans;
}
ull multiply2(int x, int y){
	if (!x || !y) return val[x][y]=1ull<<(x+y);
	if (vis[x][y]) return val[x][y];
	int p=0; vis[x][y]=1;
	for (int i=0; i<=6; i++)
		if ((1<<i)<=max(x,y)) p=i;
	ull v=(1ull<<(1<<p));
	if (x>=(1<<p) && y>=(1<<p)){
		return val[x][y]=multiply(v+(v>>1),multiply2(x-(1<<p),y-(1<<p)));
	} else
	if (x>=(1<<p)){
		return val[x][y]=multiply2(x-(1<<p),y)*v;
	} else {
		return val[x][y]=multiply2(x,y-(1<<p))*v;
	}
}

void prework(){
	for (int i=0; i<64; i++)
		for (int j=0; j<64; j++) multiply2(i,j);
	for (int i=0; i<8; i++) Log[1<<i]=i;
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++){
			for (int k=0; k<(1<<8); k++)
				for (int l=0; l<(1<<8); l++){
					res[i][j][k][l]=res[i][j][k^(k&-k)][l];
					if (k&-k){
						for (int t=0; t<8; t++)
							if ((l>>t)&1) res[i][j][k][l]^=val[i*8+Log[k&-k]][j*8+t];
					}
				}
		}
}

inline ull Mul(ull x, ull y){
	ull ans=0;
	for (int i=0; i<8; i++)
		for (int j=0; j<8; j++) ans^=res[i][j][(x>>(i*8))&255][(y>>(j*8))&255];
	return ans;
}
inline ull fastpow(ull x, ull y){
	ull z=1;
	for (; y; y>>=1,x=Mul(x,x))
		if (y&1) z=Mul(z,x);
	return z;
}
Pair exgcd(I n, I m){
	if (n==1) return {1,0};
	Pair r=exgcd(m,n%m);
	return {r.second,r.first-(n/m)*r.second};
}
I Inv(I a, I b){
	Pair r=exgcd(a,b);
	return (r.first+b)%b;
}
int solve(int k, ull x, ull y){
	ull v1=1,v2=1; int d=sqrt(k)+1; Map.clear();
	x=fastpow(x,P/k);
	y=fastpow(y,P/k);
	for (int i=0; i<=d; i++){
		if (Map.find(v1)==Map.end()) Map[v1]=i;
		if (i!=d) v1=Mul(v1,x);
	}
	v1=fastpow(v1,P-1);
	for (int i=0; i<=d; i++){
		ull cur=Mul(y,v2);
		if (Map.find(cur)!=Map.end()) return (i*d+Map[cur])%k;
		v2=Mul(v2,v1);
	}
	return -1;
}
int main(){
	prework();
	for (cin>>q; q; q--){
		scanf("%llu%llu",&x,&y); bool flag=0;
		memset(m,0,sizeof(m));
		memset(b,0,sizeof(b));
		for (int i=1; i<=7; i++){
			b[i]=(I)solve((int)a[i],x,y),m[i]=1;
			if (b[i]==-1){ flag=1; break; }
		}
		if (flag){ puts("-1"); continue; }
		for (int i=1; i<=7; i++)
			for (int j=1; j<=7; j++)
				if (i!=j) m[i]*=a[j];
		I ans=0;
		for (int i=1; i<=7; i++) ans=(ans+m[i]*Inv(m[i],a[i])%P*b[i]%P)%P;
		printf("%llu\n",(ull)ans);
	}
	return 0;
}
/*
7
8 2
2 2
1 1
2 3
8 10
321321321321 2
123214213213 4356903202345442785
*/