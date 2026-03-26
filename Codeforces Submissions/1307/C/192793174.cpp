// LUOGU_RID: 96383303
#include<bits/stdc++.h>
using namespace std;
string s;
long long ans1;
long long sum[205][205],ans[205];
int main(){
cin >> s;
for(int i = 0;i < s.size();i++){
for(int j = 97;j <= 122;j++){
if(ans[j]){
sum[j][s[i]] += ans[j];
ans1 = max(ans1,sum[j][s[i]]);
}
}
ans[s[i]]++;
ans1 = max(ans1,ans[s[i]]);
}
cout << ans1;
return 0;
}