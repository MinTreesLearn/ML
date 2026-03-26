#include <bits/stdc++.h>
using namespace std;
void solve(){
int n,d;cin>>n>>d;
vector<int> v(n+1,1);
int l=1,r=n-1,p=n*(n-1)/2-d;
while(l<r){
while(p<r-l||v[l]==v[l-1]*2&&l<r) ++l;
if(l<r){
++v[l];
p-=r-l;
--r;
}
}
if(p!=0) cout<<"NO\n";
else{
cout<<"YES\n";
int pre=1;
for(int i=1;i<=l;i++){
for(int j=0;j<v[i];j++)
cout<<pre+j/2<<' ';
pre+=v[i-1];
}
cout<<"\n";
}
}
int main()
{
int t;cin>>t;
while(t--)
solve();
return 0;
}