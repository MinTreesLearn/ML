#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
	int t; cin >> t;
	while (t--) 
	{
		int d = 0;
		cin >> s;
		n = s.size();
		int len = 0;
		for (int i = 0; i < n; i++)
		{
			int j = i + 1;
			if (s[i] == 'R')
			{
				d = max(d, j - len);
				len = j;
			}
		}
		d = max(d, n + 1 - len);
		cout << d << "\n";
	}
	return 0;
}