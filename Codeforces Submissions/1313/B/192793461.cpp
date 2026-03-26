#include <iostream>
#include <algorithm>
using namespace std;
void solve(){
int n,x,y;
cin>>n>>x>>y;
cout<<max(min(x+y-n+1,n),1)<<' '<<min(x+y-1,n)<<endl;
}
int main(){
int t;
cin>>t;
while(t--)solve();
return 0;
}
