#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){ 
  int n;
  cin >> n;
  int x = 0, y = 0;
  vector<pair<int,int>>kor(n);
  for(int i = 0; i < n; ++i){
    cin >> kor[i].first >> kor[i].second;
  }
  sort(kor.begin(),kor.end());
  string ans = "";
  for(int i = 0; i < n; ++i){
    if(x > kor[i].first || y > kor[i].second){
      cout << "NO\n";
      return;
    } else {
      int t1 = abs(kor[i].first - x);
      int t2 = abs(kor[i].second - y);
      while(t1--){
        ans.push_back('R');
      }
      while(t2--){
        ans.push_back('U');
      }
      x = kor[i].first;
      y = kor[i].second;
    }
  }
  cout << "YES\n" << ans << '\n';
} 

int main(){
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
  int TC = 1;
  cin >> TC;
  while(TC--){
    solve();
  }
}
					 	 			    	  	   			 	 	 	