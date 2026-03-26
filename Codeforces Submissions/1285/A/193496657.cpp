#define lli long long int
#include <bits/stdc++.h>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lli n, lc = 0, rc = 0;
  cin>>n;
  string s;
  cin>>s;
  for(int i=0;i<n;i++) {
    if(s[i] == 'L') {
        lc++;
    }
    else {
        rc++;
    }
  }
  cout<<(lc+rc+1)<<"\n";
  return 0;
}