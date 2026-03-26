#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b,x,y;
		scanf("%d%d%d%d",&a,&b,&x,&y);
		int p1=a-x-1,q1=b-y-1,p2=x-1+1,q2=y-1+1;
		int f1=p1*b,f2=q1*a,f3=p2*b,f4=q2*a;
		printf("%d\n",max(f1,max(f2,max(f3,f4))));
	}
	return 0;
}

	 			 	  	 	  	 				  					 	