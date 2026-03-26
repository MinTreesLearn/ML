// LUOGU_RID: 94410454
#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll n,m,k,ans[10001],ansn;
char ansf[10001];

inline ll read()
{
    ll x = 0;
    char ch = getchar();
    while (ch > '9' || ch < '0')
        ch = getchar();
    while (ch <= '9' && ch >= '0')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    return x;
}

signed main()
{
	n=read();
	m=read();
	k=read();
	if(k>(4*n*m-2*n-2*m))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(ll i=1;i<m;i++)
    {
    if(k>(n-1<<1))
	{
		k-=(n-1<<1)+1;
		if(n-1)
		{
			ans[++ansn]=n-1;
			ansf[ansn]='D';
			ans[++ansn]=n-1;
			ansf[ansn]='U';
		}
		ans[++ansn]=1;
		ansf[ansn]='R';
	}
	else
	{
		if(k>n-1&&n-1)
		{
			ans[++ansn]=n-1,ansf[ansn]='D';
			ans[++ansn]=k-n+1,ansf[ansn]='U';
		}
		else if(k&&n-1)ans[++ansn]=k,ansf[ansn]='D';
		cout<<ansn<<endl;
		for(ll i=1;i<=ansn;i++)
		{
			printf("%lld ",ans[i]);
			putchar(ansf[i]);
			putchar(10);
		}
		return 0;
	}
    }
	for(ll i=2;i<=n;i++)
    {
        if(k>(m-1<<1))
	{
		k-=(m-1<<1)+1;
		ans[++ansn]=1;
		ansf[ansn]='D';
		if(m-1)
		{
			ans[++ansn]=m-1;
			ansf[ansn]='L';
			ans[++ansn]=m-1;
			ansf[ansn]='R';
		}
	}
	else
	{
		if(k)
		{
			k--;
			ans[++ansn]=1;
			ansf[ansn]='D';
		}
		if(k>m-1&&m-1)
		{
			if(m-1)ans[++ansn]=m-1;
			ansf[ansn]='L';
			ans[++ansn]=k-m+1;
			ansf[ansn]='R';
		}
		else if(k&&m-1) ans[++ansn]=k,ansf[ansn]='L';
		cout<<ansn<<endl;
		for(ll i=1;i<=ansn;i++)
		{
			printf("%lld ",ans[i]);
			putchar(ansf[i]);
			putchar(10);
		}
		return 0;
	}
    }
	if(k>n-1)
	{
		if(n-1)ans[++ansn]=n-1,ansf[ansn]='U';
		ans[++ansn]=k-n+1;
		ansf[ansn]='L';
	}
	else if(k&&n-1)
	{
		ans[++ansn]=k;
		ansf[ansn]='U';
	}
	cout<<ansn<<endl;
	for(ll i=1;i<=ansn;i++)
	{
		printf("%lld ",ans[i]);
		putchar(ansf[i]);
		putchar(10);
	}
	return 0;
}