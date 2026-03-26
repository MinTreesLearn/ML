#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define ll long long int
#define pb push_back
 
using namespace std;

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
bool check_prime(int n) {
  bool is_prime = true;

  // 0 and 1 are not prime numbers
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }

  return is_prime;
}

int main(){

  int n,k;
  cin >> n;

  int aux = 0, diff = 0;
  vector<int> l, suporte;

  while(n--){
    int a,b;
    cin >> a >> b;

    if(a%b==0){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }

  return 0;
}