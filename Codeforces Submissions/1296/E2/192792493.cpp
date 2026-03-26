#include <bits/stdc++.h>
using namespace std;
const int MAXN=200010;
int n,ans,dp[MAXN],mx[27];
char c[MAXN];
int main () {
scanf("%d%s",&n,c+1);
for (int i=n;i>=1;i--) {
dp[i]=mx[c[i]-'a']+1;
for (int j=c[i]-'a'+1;j<=25;j++) {mx[j]=max(mx[j],dp[i]);}
ans=max(ans,dp[i]);
}
printf("%d\n",ans);
for (int i=1;i<n;i++) {printf("%d ",dp[i]);}
printf("%d\n",dp[n]);
return 0;
}