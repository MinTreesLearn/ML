#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,a,b,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&a,&b,&x,&y);
		
		int s1=a*y;
		int s2=b*x;
		int s3=a*(b-y-1);
		int s4=b*(a-x-1);
		
		int s=max(s1,max(s2,max(s3,s4)));
		printf("%d\n",s);
	}
}
			 				  		 	 	   	  			 	 	 	