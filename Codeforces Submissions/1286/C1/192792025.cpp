#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,a[110][27];string s,S;
int main(){
cin>>n;cout<<"? 1 "<<n<<endl;
for (i=1;i<=n*(n+1)/2;i++){cin>>s;
for (auto ch:s) a[s.length()][ch-97]++;
}
if (n>1) cout<<"? 2 "<<n<<endl;
for (i=1;i<=n*(n-1)/2;i++){cin>>s;
for (auto ch:s) a[s.length()][ch-97]--;
}
for (i=1;i<=n;i++)
for (j=0;j<26;j++)
if (a[i][j])
for (S+=char(j+97),k=i+1;k<=n;k++)
a[k][j]--;
cout<<"! "<<S<<endl;
return 0;
}