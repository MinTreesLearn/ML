#include <bits/stdc++.h>
#define N 100005
#define wr cout << "Continue debugging\n";
#define all(x) (x).begin(), (x).end()
#define ll long long int
#define pii pair <int, int>
#define pb push_back
#define ff first
#define ss second
using namespace std;

int p[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	char lst1 = 'a', lst2 = 'a';
	for (int i = 0; i < n; i++){
		if (s[i] >= lst1) lst1 = s[i];
		else if (s[i] >= lst2){
			lst2 = s[i];
			p[i] = 1;
		}else return cout << "NO", 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++){
		cout << p[i];
	}
}	