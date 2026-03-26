#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ios_base::sync_with_stdio(false);   cout.tie(nullptr);  cin.tie(nullptr);
    int T=1; cin>>T;
    while(T--) {
      int ans=0,dis=1; string s;
      cin>>s; char c;
      for(int i=0;i<s.size();i++){
          if(s[i]=='L'){
              dis++;
          }
          else{
              ans=max(ans,dis);
              dis=1; c=i;
          }
      }
      ans=max(ans,dis);
      
      cout<<ans<<'\n';

    }
    return 0;
}