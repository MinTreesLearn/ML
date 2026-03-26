#include <bits/stdc++.h>
using namespace std;

#define print(a) for(auto x : a) {cout << x << " ";} cout << endl;

typedef long long lli;
typedef vector<int> vi;
typedef vector<lli> vl;

int main(){
	
	int t;
	cin >> t;
	while (t --){
		int n;
		cin >> n;
		int o = 0, e = 0;
		for (int i = 0; i < n; i++){
			int k;
			cin >> k;
			if (k % 2 == 0){
				e ++;
			} else {
				o ++;
			}
		}
		if (o % 2 != 0){
			cout << "YES" << endl;
		} else if (o % 2 == 0 && e > 0 && o > 0){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}
	