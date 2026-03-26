#include <bits/stdc++.h>
using namespace std;
using ll=long long;
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (ll i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
int computeXOR(int n)
{
   
  // If n is a multiple of 4
  if (n % 4 == 0)
    return n;
 
  // If n%4 gives remainder 1
  if (n % 4 == 1)
    return 1;
 
  // If n%4 gives remainder 2
  if (n % 4 == 2)
    return n + 1;
 
  // If n%4 gives remainder 3
  return 0;
}

   int main() {
	// your code goes here
	ll test;
	cin>>test;
	while(test--)
	{ 
	   ll n,d,A=0,B=0;
	   cin>>n>>d;
	   A=(n-1)*(n-1);
	   B=(n-2)*(n-2);
	   if((A-4*(d-n))>=0||(B-4*(d-n+1))>=0)
	     cout<<"YES"<<endl;
	   else
	     cout<<"NO"<<endl;
	}
	return 0;
}


