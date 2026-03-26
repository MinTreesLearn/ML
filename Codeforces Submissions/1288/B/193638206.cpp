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
	   ll a,b,c=0,d=0;
	   cin>>a>>b;
	   if(a<9&&b<9)
	     cout<<'0'<<endl;
	    else
	    {
	        d=9;
	        while(d<=b)
	        {
	            c+=a;
	            d*=10;
	            d+=9;
	        }
	        cout<<c<<endl;
	    }
	}
	return 0;
}


