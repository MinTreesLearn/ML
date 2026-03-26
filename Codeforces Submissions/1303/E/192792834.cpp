#include <bits/stdc++.h>
using namespace std;
const int N=405;
int n,m,dp[N][N];
char s[N],t[N];
bool check(int d) {
for (int i=0; i<=n; i++) for (int j=0; j<=d; j++) dp[i][j]=-1;
dp[0][0]=0;
for (int i=1; i<=n; i++)
for (int j=0; j<=d; j++) {
if (dp[i-1][j]!=-1) dp[i][j]=max(dp[i][j],dp[i-1][j]+(dp[i-1][j]<m-d && t[d+dp[i-1][j]+1]==s[i]));
if (j>0 && dp[i-1][j-1]!=-1 && t[j]==s[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
}
return (dp[n][d]==m-d);
}
int main() {
//	freopen("sa1.in","r",stdin);
int T; scanf("%d",&T);
while (T--) {
scanf("%s%s",s+1,t+1);
n=strlen(s+1),m=strlen(t+1);
int flag=0; for (int d=0; d<=m; d++) if (check(d)) { flag=1; break; }
puts(flag?"YES":"NO");
}
return 0;
}
