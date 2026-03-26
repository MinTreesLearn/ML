
///   In the name of ALLAH     ///

#include <bits/stdc++.h> 
#define ll long long 
using namespace std;



int main() {
     ios_base::sync_with_stdio(0); cin.tie(0);
     
     ll x; cin >> x;
     ll a,b;

     for(ll i=1; i*i <= x; i++) {
     	if(x % i == 0) {
     		if(__gcd(i,x/i) == 1) {
     			a = i;
     		}
     	}
     }
     cout << a << " " << x / a << '\n';
     
     
     
    

     return 0;
}
