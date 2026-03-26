#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
#define MOD 998244353
struct Segment{
	long long l,r;
} seg[1001010],a[1001010];
long long down,up,n,m,lst,now,i,tn;
long long lsh[1001010];
long long inv[1001010],dp[1010][1010];
long long pow(long long x,long long y,long long p){
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
	    if (y&1) ans=ans*x % p;
	return ans;
}
bool check(int l,int r,int pos){
	if (l>r) return true;
	for (int i=l;i<=r;i++)
	    {
	    if (a[i].r<seg[pos].l) return false;
	    if (a[i].l>seg[pos].r) return false;
	}
	return true;
}
long long C(long long n,long long m){
	long long ans=1;
	for (long long i=n-m+1;i<=n;i++) ans=ans*i % MOD;
	for (long long i=1;i<=m;i++) ans=ans*inv[i] % MOD;
	return ans;
}
long long Calc(long long n,long long m){
	return C(n+m-1,n);
}
/*
13 41
42 419
420 1336
1337 1337
*/
int main()
{
	n=read();
	for (i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
	for (i=1;i<=n/2;i++) swap(a[i],a[n-i+1]);
	for (i=1;i<=n;i++) lsh[++tn]=a[i].l,lsh[++tn]=a[i].r;
	sort(lsh+1,lsh+tn+1);
	inv[1]=1;
	for (i=2;i<=n;i++) inv[i]=(MOD-MOD/i)*inv[MOD % i] % MOD;
	tn=unique(lsh+1,lsh+tn+1)-lsh-1;
	for (i=1;i<tn;i++) {
		seg[++m].l=lsh[i];
		seg[m].r=lsh[i];
		seg[++m].l=lsh[i]+1;
		seg[m].r=lsh[i+1]-1;
	}
	seg[++m].l=lsh[tn];seg[m].r=lsh[tn];
	dp[0][0]=1;
	for (i=1;i<=m;i++) 
	   for (lst=0;lst<=n;lst++)
	      for (now=lst;now<=n;now++)
	         if (check(lst+1,now,i))
	          dp[i][now]=(dp[i][now]+dp[i-1][lst]*Calc(now-lst,seg[i].r-seg[i].l+1)) % MOD;
	down=1;
	for (i=1;i<=n;i++) down=down*(a[i].r-a[i].l+1) % MOD;
	
	down=pow(down,MOD-2,MOD) % MOD;
	
	up=dp[m][n];
	printf("%lld\n",up*down % MOD);
return 0;
}
/*
dp[i][j] ±íÊ¾Ç°i¸öÇø¼ä°üº¬ÁËÇ°j¸öÊýµÄ·½°¸Êý
ÏÖ½«ËùÓÐÇø¼ä¿Ù³öÀ´ 
*/