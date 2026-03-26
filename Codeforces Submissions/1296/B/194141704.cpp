#include <iostream>
#include <deque>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	//piza force
	/*long long x,t,out=0;
	cin >> t;
	for (long long i = 0; i < t; i++)
	{
		cin >> x,out=0;
		while (x > 0)
			if (x%6==0||(x % 6 >= x % 8 && x % 6 >= x % 10&&x%8!=0&&x%10!=0))
				x -= 6,out+=15;
			else if (x%8==0||(x % 8 >= x % 10&&x%10!=0))
				x -= 8, out += 20;
			else
				x -= 10, out += 25;
		cout << out << endl;
	}*/
	//odd divisor
	/*int prime[]{  3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,};
	string yes;
	ll x, n;
	cin >> n;
	for (ll o = 0; o < n; o++)
	{
		cin >>x,yes="no";
		if (x % 2 != 0&&x>1)
			yes = "yes";
		else
		for (int i = 0; i <43; i++)
			if (x % prime[i] == 0)
			{
				yes = "yes";
				break;
			}
		cout << yes << endl;
	}*/
	int t; double x, out;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> x,out = x;
		while (x >= .001)
		{
			out += double(x / 10), x = x/ 10;
		}
		out=floor(out);
		cout << long(out) << endl;
	}
}
