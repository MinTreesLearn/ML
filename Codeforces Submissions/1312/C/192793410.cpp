#include<bits/stdc++.h>

using namespace std;

void solve(){
long long int n,k,b[200]={0},y=0,x;
cin>>n>>k;
for(int i=0;i<n;i++){
cin>>x;
long long int a=0;
while(x>0){
b[a]+=x%k;
if(b[a]>1){y++;break;}
x/=k;a++;}
}
if(y>0)cout<<"NO\n";
else cout<<"YES\n";
}

int main(){
int t;
cin>>t;
while(t--) solve();
return 0;
}