#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
	int tt;
	cin >> tt;
	while(tt--) {
	 int A, B, X, Y;
     cin >> A >> B >> X >> Y;
     cout << max({X * B, (A - 1 - X) * B, A * Y, A * (B - 1 - Y)}) << '\n';
	}
}