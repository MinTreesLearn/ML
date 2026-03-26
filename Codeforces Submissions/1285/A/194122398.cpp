#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const ll mod = 998244353;
const int mm = 3e5 + 10;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	cin>>n;
	string a;
	cin>>a;
	int l=0,r=0;
	for(auto i:a){
		if(i=='L')l++;
		else r++;
	}
	cout<<l+r+1;
}
