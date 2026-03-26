// Problem: C. Fadi and LCM
// Contest: Codeforces - Codeforces Round #613 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1285/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
typedef long long int       ll;
int lcm(int x, int y){return x/__gcd(x,y)*y;}


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
  	ll n;
	cin >> n;
	ll a=0,b=0;
	for(ll i = 1; i*i <= n; i++){
		if(n%i==0){
			if(lcm(i , n/i) == n){
				a=i;
				b=n/i;				
			}
		}
	}
    cout<< a << " " << b << '\n';
  
	return 0;
}

		   	   	 		      	    				 		