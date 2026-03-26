#include <stdio.h>
int main(){
int t,n,m,sum,temp;
scanf("%d",&t);
while(t--){
temp=0;
sum=0;
scanf("%d%d",&n,&m);
while(n--){
scanf("%d",&temp);
sum+=temp;
}
if(sum<m)
printf("%d\n",sum);
else
printf("%d\n",m);
}

return 0;
}
