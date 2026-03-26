#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve()
{
    int n, m, k;
	string str;
	cin >> n >> str;
	
	for (char i = 'z'; i >= 'b'; i -- ) {
		if (str.size() == 1) break;
		
		while (true) {
			if (str.size() == 1) break;

			bool flag = false;
			for (int j = 0; j < str.size(); j ++ ) {
				if (str[j] != i) continue;
				
				if (j == 0) {
					if (str[j + 1] == i - 1) {
						flag = true;
						str.erase(str.begin() + j, str.begin() + j + 1);
						break;
					}
				}
				else if (j == str.size() - 1) {
					if (str[j - 1] == i - 1) {
						flag = true;
						str.erase(str.begin() + j, str.begin() + j + 1);
						break;
					}
				}
				else {
					if (str[j - 1] == i - 1 || str[j + 1] == i - 1) {
						flag = true;
						str.erase(str.begin() + j, str.begin() + j + 1);
						break;
					}
				}
			}
			
			if (!flag) break;
		}
	}
	
	cout << n - (int)str.size() << "\n";
	return ;
}
signed main()
{
    int t = 1;
    while (t -- ) {
        solve();
    }
    return 0;
}
