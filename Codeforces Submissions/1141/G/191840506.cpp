#include<bits/stdc++.h>
using namespace std;
int n,k,t,r,u,v,b[200010],h[200010],ans[200010];
struct node
{
	int to,ne;
}a[1000010];
void add(int u,int v)
{
	a[++t].to=v;
	a[t].ne=h[u];
	h[u]=t;
}
void work(int u,int bu,int s)
{
	for(int i=h[u];i>0;i=a[i].ne)
	{		
		if(a[i].to==bu)
		{
			continue;
		}
		s++;
		if(s>r)
		{
			s=1;
		}
		ans[(i+1)/2]=s;
		work(a[i].to,u,s);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		b[u]++;
		b[v]++;
		add(u,v);
		add(v,u);
	}
	sort(b+1,b+n+1);
	r=b[n-k];
	cout<<r<<endl;
	work(1,0,0);
	for(int i=1;i<n;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 