#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
long long t,sum;
int n,a;
cin>>t;
sum=t*t;
vector<int> x;
vector<int> y;
for(int i=0;i<t;i++){
cin>>n;
int ma=INT_MIN,mi=INT_MAX,b=INT_MAX;
bool can=false;
for(int j=0;j<n;j++){
cin>>a;
if(a>b){
can=true;
}else
b=a;
ma=max(ma,a);
mi=min(mi,a);
}
if(!can){
x.push_back(mi);
y.push_back(ma);
}
}
sort(y.begin(),y.end());
for(int i=0;i<x.size();i++)
sum-=upper_bound(y.begin(),y.end(),x[i])-y.begin();
cout<<sum;
return 0;
}
