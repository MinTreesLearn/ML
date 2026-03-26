
#include <bits/stdc++.h>
using namespace std;

int main()
{
 int t;
 long long int n,x,m,ni,a,b;
 cin>>t;
 while(t--){
vector<int> v; 
  cin>>n;
  for(int i=0;i<2*n;i++){
  cin>>x;
  v.push_back(x);
  }
 sort(v.begin(),v.end());
  cout << v[n*2 / 2] - v[( n*2 / 2) - 1] << endl;}
    return 0;
}
