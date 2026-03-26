#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
void yes(){cout<<"YES\n";}
void  no(){cout<<"NO\n";}
long long mod = 1e9+7;
struct Point{
  int x,y;
};
void solve()
{
  int n;
  cin >> n;
  vector<Point> P(n+1);
  
  for(int i=0; i<n; i++){
    cin >> P[i].x >> P[i].y;
  }

  P[n] = P[0];
  bool ok = true;
  if(n&1){
    cout <<"NO\n";
  }else{
    for(int i=0; i<n/2; i++){
      if(P[i+1].x - P[i].x + P[i+n/2+1].x - P[i+n/2].x == 0 and P[i+1].y - P[i].y + P[i+n/2+1].y - P[i+n/2].y == 0){
        continue;
      }else{
        ok = false;
        break;
      }
    }

    if(ok == true){
      cout <<"YES\n";
    }else{
      cout <<"NO\n";
    }
  }

  
} 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
   // int t; cin >> t; while(t--)//
    solve();
}
   