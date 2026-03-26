#include<bits/stdc++.h>
using namespace std;
int t,a,b,x,y;
int main(){for(cin>>t;t--;cout<<max(a*y,max(a*(b-y-1),max(b*x,b*(a-x-1))))<<'\n')cin>>a>>b>>x>>y;}