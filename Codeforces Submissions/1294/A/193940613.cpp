#include <iostream>
#include <cmath>
using namespace std;

int sum(long long int a, long long int b, long long int c){
  return a+b+c;
}

int main()
{
  int t;
  long long int a, b, c, n;
  long long int diff;
  cin >> t;
  while(t--){
    cin >> a >> b >> c >> n;
    int arr[3]={a, b, c};
    sort(arr, arr+3);
    diff=arr[2]-arr[0];
    diff+=arr[2]-arr[1];
    if(n >= diff){
      n-=diff;
      if(n%3==0){
        cout << "YES" << endl;
      }else{
        cout << "NO" << endl;
      }

    }else{
      cout << "NO" << endl;
    }
  }


  return 0;
}
