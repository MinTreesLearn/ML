#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int num,t;
	int a[2][1000];
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&num);
	for(int j=0;j<2;j++)
	for(int i=0;i<num;i++)
	{
		scanf("%d",&a[j][i]);
	}
	sort(a[0],a[0]+num);
	sort(a[1],a[1]+num);
	for(int j=0;j<2;j++)
	{
		for(int i=0;i<num;i++)
		{
			printf(i!=num-1?"%d ":"%d\n",a[j][i]);
		}
	}
}
}
