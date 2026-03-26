#include<bits/stdc++.h>
#define maxn 1001
using namespace std;
int ans[maxn],tot;
char s[maxn];
int main(){
int l,r,len,i;
scanf("%s",s+1);
len=strlen(s+1);
l=1,r=len;
while(1){
while(l<=len&&s[l]==')')l++;
while(1<=r&&s[r]=='(')r--;
if(l>r)break;
ans[++tot]=l,ans[++tot]=r;
l++,r--;
}
if(!tot)printf("0\n");
else{
printf("1\n");
printf("%d\n",tot);
sort(ans+1,ans+1+tot);
for(i=1;i<tot;i++)printf("%d ",ans[i]);
printf("%d\n",ans[tot]);
}
return 0;
}
