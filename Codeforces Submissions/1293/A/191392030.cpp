#include<bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t>0){
    t--;
    int n,s,k;
    cin >> n >> s >> k;
    set<int> st;
    for(int i=-(k+3);i<=(k+3);i++){
      int cf=s+i;
      if(1<=cf && cf<=n){st.insert(cf);}
    }
    for(int i=0;i<k;i++){
      int x;
      cin >> x;
      st.erase(x);
    }
    int res=1e9;
    auto it=st.lower_bound(s);
    if(it!=st.end()){res=min(res,(*it)-s);}
    if(it!=st.begin()){
      it--;
      res=min(res,s-(*it));
    }
    cout << res << "\n";
  }
  return 0;
}
