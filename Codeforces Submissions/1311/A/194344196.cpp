#include <bits/stdc++.h>
using namespace std;
#define ll long long

  


int main (){
  int t;
  cin >> t;
  while (t--){
      int a , b ;
      cin >> a >> b;
      if (a==b) cout<<0<<endl;
       else cout<< 1 + int((a < b) ^ ((b - a) & 1)) << endl;
  }

}



