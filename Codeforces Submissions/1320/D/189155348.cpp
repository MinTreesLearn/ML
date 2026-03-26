#include<bits/stdc++.h>
using namespace std;
int const M=200200,mod1=1e9+7,mod2=998244353;
int i,n,x,y,k,T,cnt[M];char s[M];
long long Pow1[M],Pow2[M],Hash1[2][M],Hash2[2][M];
int read(){
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-48,ch=getchar();
	return x;
}
int HASH1(int x,int k){return ((Hash1[x&1][x+k-1]-Hash1[x&1][x-1]*Pow1[cnt[x+k-1]-cnt[x-1]])%mod1+mod1)%mod1;}
int HASH2(int x,int k){return ((Hash2[x&1][x+k-1]-Hash2[x&1][x-1]*Pow2[cnt[x+k-1]-cnt[x-1]])%mod2+mod2)%mod2;}
int main(){
	scanf("%d%s",&n,s+1);
	for (i=Pow1[0]=Pow2[0]=1;i<=n;i++){
		Pow1[i]=Pow1[i-1]*233%mod1;Pow2[i]=Pow2[i-1]*2333%mod2;
		Hash1[0][i]=Hash1[0][i-1];Hash1[1][i]=Hash1[1][i-1];
		Hash2[0][i]=Hash2[0][i-1];Hash2[1][i]=Hash2[1][i-1];
		cnt[i]=cnt[i-1];if (s[i]^48) continue;cnt[i]++;
		Hash1[0][i]=(Hash1[0][i]*233+!(i&1)+1)%mod1;Hash1[1][i]=(Hash1[1][i]*233+(i&1)+1)%mod1;
		Hash2[0][i]=(Hash2[0][i]*2333+!(i&1)+1)%mod2;Hash2[1][i]=(Hash2[1][i]*2333+(i&1)+1)%mod2;
	}	
	T=read();while (T--){
		x=read();y=read();k=read();
		puts(HASH1(x,k)==HASH1(y,k)&&HASH2(x,k)==HASH2(y,k)?"Yes":"No");
	}
	return 0;
} 