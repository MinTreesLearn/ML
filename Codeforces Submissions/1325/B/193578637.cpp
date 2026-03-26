#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void test_case(int test)
{
	int n;
	cin >> n;
	set<int> a;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		a.insert(temp);
	}

	cout << a.size() << "\n";
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t) test_case(t);
	return 0;
}