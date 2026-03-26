#include <bits/stdc++.h>
#define ll long long
using namespace std;
int T,a,b,c,d,a1,a2;
string s;
#define ios std::ios::sync_with_stdio(false),cin.tie(0), cout.tie(0)

int main() {
	ios;

	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> d;
		c++;
		d++;
		a1 = max((c-1) * b,(a-c) *b);
			a2 = max((d-1)*a,(b-d)*a);
			a1 = max(a1, a2);
			cout << a1 << endl;
	}

		return 0;
}
 				 			 		 		  			 					 	