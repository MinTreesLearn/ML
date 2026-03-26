#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		ll t;
		cin >> t;
		while( t-- ){
			string s;
			cin >> s;
			ll cnt = 0, z = 0, cal = 0 , ans = 0;
			for(ll i = 0; i < s.size(); i++)if(s[i] == '1') {cal = i, z++; break;}
			for(ll i = s.size() - 1; i  >= 0; i--)if(s[i] == '1') {ans = i; break;}
			for(ll i = cal; i  <= ans; i++)if(s[i] == '0') cnt++;	
			if(z == 0) cout << false << endl;
			else cout << cnt << endl; 
			}
	}
	/*
	
	*/
	
	