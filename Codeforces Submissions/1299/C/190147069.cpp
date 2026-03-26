#include<bits/stdc++.h>

using namespace std;
using pl=pair<long long,long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  stack<pl> st;
  for(int i=0;i<n;i++){
    long long x;
    cin >> x;
    pl cur={x,1};
    while(!st.empty()){
      pl tp=st.top();
      if(tp.first*cur.second < cur.first*tp.second){break;}
      st.pop();
      cur.first+=tp.first;
      cur.second+=tp.second;
    }
    st.push(cur);
  }

  vector<double> res;
  while(!st.empty()){
    pl tp=st.top();st.pop();
    double cval=tp.first;
    cval/=tp.second;
    for(int i=0;i<tp.second;i++){
      res.push_back(cval);
    }
  }
  for(int i=n-1;i>=0;i--){
    std::cout << std::fixed;
    std::cout << std::setprecision(12) << res[i] << "\n";
  }

  return 0;
}
