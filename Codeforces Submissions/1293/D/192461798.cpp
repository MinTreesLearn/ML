#include <stdio.h>
#define LL long long
LL x[65],y[65],ax,ay,bx,by,xs,ys,t,cnt=0;
const LL INF=1e16+1;
LL min(LL a,LL b){
	return a<b?a:b;
}
LL max(LL a,LL b){
	return a>b?a:b;
}
LL abs(LL a){
	return a>=0?a:-a;
}
int main(){
	LL i,j,ans=0;
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	while(x[cnt]<INF&&y[cnt]<INF)
		cnt++,x[cnt]=ax*x[cnt-1]+bx,y[cnt]=ay*y[cnt-1]+by;
	scanf("%lld%lld%lld",&xs,&ys,&t);
	for(i=0;i<=cnt;i++)
		for(j=i;j<=cnt;j++){
			LL tot=min(abs(xs-x[i])+abs(ys-y[i]),abs(xs-x[j])+abs(ys-y[j]));
			tot+=x[j]-x[i]+y[j]-y[i];
			if(tot<=t)ans=max(ans,j-i+1);
		}
	printf("%lld\n",ans);
	return 0;
}
 	  	  	 						  							 		 			