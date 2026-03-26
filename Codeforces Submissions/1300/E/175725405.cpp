#include<bits/stdc++.h>
using namespace std;

long long shu[1000500],sum[1000500];
double ans[1000500];
int cno=0;

struct node{
	int l,r;
	double ave;
	
}no[1000500];

int main(){
	
	int t,cnt;

	scanf("%d",&cnt); 
	
	for(int i=1;i<=cnt;i++){
		scanf("%lld",&shu[i]);
		sum[i]=sum[i-1]+shu[i];
	}
	
	for(int i=1;i<=cnt;i++){
		no[++cno].l=i;
		no[cno].r=i;
		no[cno].ave=shu[i];
		
		while(no[cno].ave<=no[cno-1].ave&&cno>=2){
			no[cno-1].ave=(sum[i]-sum[no[cno-1].l-1])*1.0/(i-no[cno-1].l+1);
			no[cno-1].r=no[cno].r;
			cno--;
		}	
	}
	for(int i=1;i<=cno;i++){
		for(int j=no[i].l;j<=no[i].r;j++) 
			ans[j]=no[i].ave;
	}
	
	for(int i=1;i<=cnt;i++)
		printf("%.11f\n",ans[i]);
		
	return 0;
} 
		     		 		 			 	 		 	 	  	 		