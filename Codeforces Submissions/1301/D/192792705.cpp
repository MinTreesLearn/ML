#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
typedef pair<int,char>pii;
vector<pii>ans;
int n,m,k;
void run(int cnt,char ch){
if(!k||!cnt)return;
if(cnt>=k){

ans.push_back({k,ch});
k=0;
return ;
}
k-=cnt;
ans.push_back({cnt,ch});
}
void solve(){
cin>>n>>m>>k;
if(4*n*m-2*n-2*m<k){
cout<<"NO"<<endl;
return;
}
cout<<"YES"<<endl;
run(m-1,'R');
for(int i=1;i<m;i++) run(n-1,'D'),run(n-1,'U'),run(1,'L');
for(int i=1;i<n;i++) run(1,'D'),run(m-1,'R'),run(m-1,'L');
run(n-1,'U');
cout<<ans.size()<<endl;
for(auto x:ans) cout<<x.first<<" "<<x.second<<endl;
}
int main(){
int t;
t=1;
while(t--){
solve();
}
return 0;
}