#include<bits/stdc++.h>
using namespace std;
int main(){
int a,b,c;
int n;
cin>>n;
while(n--){
int ans=0;
cin>>a>>b>>c;
if(a)a--,ans++;
if(b)b--,ans++;
if(c)c--,ans++;
if(a<c)swap(a,c);
if(a<b)swap(a,b);
if(a&&b)a--,b--,ans++;
if(a&&c)a--,c--,ans++;
if(b&&c)b--,c--,ans++;
if(a&&b&&c)ans++;
cout<<ans<<endl;}
}
