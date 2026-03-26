#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e5+10;
const int MOD=998244353;
int fac[M],ifac[M],n,m;
int pw(int x,int y)
{
	if(y==0)
		return 1;
	int p=pw(x,y/2);
	if(y%2==1)
		return p*p %MOD *x %MOD;
	return p*p %MOD;
}
int modinv(int x)
{
	return pw(x,MOD-2);
}
int comb(int x,int y)
{
	return fac[x] * ifac[y] %MOD * ifac[x-y] %MOD;
}
void prec()
{
	fac[0]=1;
	ifac[0]=1;
	for(int i=1;i<M;i++)
	{
		fac[i]=fac[i-1]*i %MOD;
		ifac[i]=modinv(fac[i]);
	}
}
int32_t main()
{
	prec();
	cin>>n>>m;
	if(n==2)return cout<<0<<endl,0;
	cout<<comb(m,n-1) * (n-2) %MOD * pw(2,n-3) %MOD<<endl;
}
