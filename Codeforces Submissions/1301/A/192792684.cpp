#include <bits/stdc++.h>
using namespace std;
int n,sum;
string a,b,c;
int main(){
cin >> n;
while(n--){
sum=0;
cin >> a >> b >> c;
for(int i=0;i<a.size();i++) if(a[i]==c[i] || c[i]==b[i]) sum++;
if(sum==a.size()) cout <<"YES\n";
else cout << "NO\n";
}
}