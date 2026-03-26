#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
pair<long long int,int> p[n+1];
for(int i=0; i<n; i++){
cin>>p[i].first;
}
for(int i=0; i<n; i++)
cin>>p[i].second;
sort(p,p+n);
p[n].first=2*(pow(10,9));
p[n].second=0;
long long int ans=0;
priority_queue<int> q;
q.push(p[0].second);
long long int size=p[0].second;
for( int i=1; i<n+1; i++ ){
long long int c=p[i].first-p[i-1].first;
while((!q.empty())&&(c>0)){
size-=q.top();
q.pop();
ans+=size;
c--;
}
q.push(p[i].second);
size+=p[i].second;
}
cout<<ans<<"\n";
}


