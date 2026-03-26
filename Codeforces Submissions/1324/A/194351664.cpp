#include <bits/stdc++.h>
using namespace std;
int main() {
  int t,n,odd,even;
  cin>>t;
  while(t--){
    odd=0,even=0;
    cin>>n;
    int a[n];
    for(int j=0;j<n;j++){
      cin>>a[j];
      if(a[j]%2==0){
        even++;
      }
      else{
        odd++;
      }
    }
    if(even==n||odd==n){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}