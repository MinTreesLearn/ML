#include "bits/stdc++.h"

using namespace std;
signed main() {
   int n,m;
   scanf("%d%d",&n,&m);
   vector< vector< int >> a(n+3,vector<int>(m+3));
   for(int i = 1; i <=n ;i++)
       for(int j = 1 ; j  <=m;j++)
           cin >> a[i][j];

   int ans = 0;
   for(int i = 1; i <=m;i++){
       vector<int>cnt(n+3);
       for(int j = 1; j <=n;j++){
           if(a[j][i] < i or (a[j][i] - i) %m) continue;
           int row = (a[j][i] -i) / m + 1;
           if(row > n) continue;
           int offset = j - row;
           cnt[(offset + n)%n]++;
       }

      int cur = n;
      for(int j = 0 ; j < n; j++) cur = min(cur, j + n - cnt[j]);
      ans += cur;
   }
   printf("%d\n",ans);
}
