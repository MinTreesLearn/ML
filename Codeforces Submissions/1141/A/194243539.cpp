#include <bits/stdc++.h>
using namespace std;
	
int main()
{
	int n, m, div, count = 0;
	cin >> n >> m;
	if(n == m)
		cout << 0;
	else if(m%n)
		cout << -1;
	else
	{
		div = m/n;
		while(div % 2 == 0)
		{
			div = div/2;
			count++;
		}	
		while(div % 3 == 0)
		{
			div = div/3;
			count++;
		}	
		if(div == 1)
			cout << count;
		else 
			cout << -1;
	}
}
