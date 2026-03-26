#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
#include <sstream>

using namespace std;

#define file                       \
  freopen("out.txt", "w", stdout); \
  freopen("in.txt", "r", stdin)
#define inf unsigned long long32_MAX
#define FIn    \
  cin.tie(0);  \
  cout.tie(0); \
  ios_base::sync_with_stdio(false)
#define endl '\n'


int main()
{ 
  FIn; 
  //file;
  int t; cin >> t;
  while(t--){
    int n,m,k; cin >> n >> m >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    if(k>=m){
      int rslt=0;
      for(int i=0;i<m;i++){
        rslt =max(rslt,arr[i]);
      }
      for(int i=n-1;i>n-1-m;i--){
        rslt = max(rslt,arr[i]);
      }
      cout << rslt << endl;
    }
    else{
        int nuc = m-k-1;
        int am  = n-m;
        int best= 0;

        for(int i=0;i<=k;i++){
          int loc = (int) 1e9 +5;
          for(int j=0;j<=nuc;j++){
           int mn =max(arr[i+j],arr[i+j+am]);
            loc  = min(loc,mn);
          }
          best = max(loc,best);
        }
        cout << best << endl; 

    }


  }

return 0;
}