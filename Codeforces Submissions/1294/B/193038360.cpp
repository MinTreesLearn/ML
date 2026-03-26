#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float double

signed main(){
  int t=1;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    map<int,pair<int,int>> mp;
    string ans="YES",line="";
    for(int i=0;i<n;i++){
      int a,b;cin>>a>>b;
      pair<int,int> pa;
      auto it=mp.find(a);
      if(it==mp.end()){
        pa={b,b};
        mp[a]=pa;
      }
      else{
        pa={min(mp[a].first,b),max(mp[a].second,b)};
        mp[a]=pa;
      }
    }
    int x=0,y=0;
    
    for(auto it=mp.begin();it!=mp.end();it++){
      
      int a=(*it).first,b_min=(*it).second.first,b_max=(*it).second.second;
      if(b_min<y){ans="NO";break;}
      while(a>x){x++;line+='R';}
      while(b_max>y){line+='U';y++;}

    }
    cout<<ans<<endl;
    if(ans=="NO")continue;
    cout<<line<<endl;

  }

  return 0;
}