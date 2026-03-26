#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
  int n;
  cin>>n;
  n+=n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  cout<<v[n/2]-v[(n/2)-1]<<"\n";
  return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long long t=1;
    cin>>t;
    while(t--){
      solve();
    }
    return 0;
}