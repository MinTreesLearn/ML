#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T,n,p[200005];
char s[200005];
int main(){
scanf("%d",&T);
while(T--){
scanf("%d%s",&n,s+1);
for(int i=1;i<=n;i++)p[i]=n-i+1;
for(int i=1,j=1;i<n;j=i=j+1){
while(s[j]=='<')j++;
reverse(p+i,p+j+1);
}
for(int i=1;i<=n;i++)printf("%d ",p[i]);
puts("");
for(int i=1;i<=n;i++)p[i]=i;
for(int i=1,j=1;i<n;j=i=j+1){

while(s[j]=='>')j++;
reverse(p+i,p+j+1);
}
for(int i=1;i<=n;i++)printf("%d ",p[i]);
puts("");
}
return 0;
}