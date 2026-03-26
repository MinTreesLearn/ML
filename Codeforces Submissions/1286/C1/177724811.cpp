#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
using LL = long long;

void ask(int l, int r){
	cout << "? " << l << ' ' << r << endl;
}

int main(){

#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int n;
	cin >> n;
	if (n == 1){
		ask(1, 1);
		string s;
		cin >> s;
		cout << "! " << s << '\n';
		return 0;
	}
	multiset<string> s;
	ask(1, n);
	for(int i = 1; i <= n * (n + 1) / 2; i++){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		s.insert(str);
	}
	ask(1, n - 1);
	for(int i = 1; i <= n * (n - 1) / 2; i++){
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		s.erase(s.find(str));
	}
	vector<array<int, 26> > c(n + 1);
	string ans;
	for(auto str : s){
		int x = str.size();
		for(auto u : str) c[x][u - 'a']++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 26; j++)
			if (c[i][j] == c[i - 1][j] + 1){
				ans += char('a' + j);
				break;
			}
	}
	reverse(ans.begin(), ans.end());
	cout << "! " << ans << endl;

}