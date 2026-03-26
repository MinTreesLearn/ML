#include<iostream>
#include<vector>
using namespace std;
int n;
int tem[2005];
int c[2005];
vector<int> a[2005];
int f = 0;
int Size[2005];
int ans[2005];
int find(int x)
{
	int t = 0;
	for(int i = 1; i <= n ; i++)
	{
		if(tem[i] == 0)
		continue;
		t ++;
		if(t == x)
		{
			tem[i] = 0;
			return i;
		}
	}
	return -1;
}
void dfs(int x)
{
	Size[x] = 1;
	ans[x] = find(c[x] + 1);
	if(ans[x] == -1)
    f = -1;
	for(auto v:a[x])
	{
		dfs(v);
		Size[x] += Size[v];
	}
	if(Size[x] - 1 < c[x])
	{
		 f = -1;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	tem[i] = 1;
	int root = 0;
	for(int i = 1; i <= n; i++)
	{
		int l;
		scanf("%d%d",&l,&c[i]);
		a[l].push_back(i);
		if(l == 0)
		{
			root = i;
		}
	}
	dfs(root);
	if(f == -1)
	printf("NO");
	else
	{
		printf("YES\n");
		for(int i = 1; i <= n; i++)
		printf("%d ",ans[i]);
	}
}
			  	    	 			 		  	        		