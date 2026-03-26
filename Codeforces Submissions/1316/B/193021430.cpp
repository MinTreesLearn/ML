#include <bits/stdc++.h>
using namespace std;

#define ll long long






string modify(string &s,int n,int k){
    string result_prefix = s.substr(k - 1, n - k + 1);
	string result_suffix = s.substr(0, k - 1);
	if (n % 2 == k % 2)
		reverse(result_suffix.begin(), result_suffix.end());
	return result_prefix + result_suffix;
}

void solve();


int main(){
    int testNumber;
    cin>>testNumber;
    while(testNumber--){
        solve();
    }
    return 0;
}

void solve(){
    string s, best_s, temp;
	int n, best_k;
    cin >> n >> s;
		best_s = modify(s, n, 1);
		best_k = 1;
		for (int k = 2; k <= n; ++k) {
			temp = modify(s, n, k);
			if (temp < best_s) {
				best_s = temp;
				best_k = k;
			}
		}
		cout << best_s << '\n' << best_k << '\n';
      
}