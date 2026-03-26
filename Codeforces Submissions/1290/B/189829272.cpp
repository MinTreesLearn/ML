#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int> 
#define pii pair<int, int>
#define m_p make_pair
#define pyes cout << "Yes\n"
#define pno cout << "No\n"
using namespace std;
#define fastIO()                \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (auto &x : a) out << x << ' '; return out;};
void print(vector<int> a) {
    for(auto it : a) {
        cout << it << " ";
    }
    cout << '\n';
}
void print(vector<vi> a) {
    for(auto it : a) {
        for(auto kt : it) {
            cout << kt << ' ';
        }
        cout << "\n";
    }
}
void print(pii a) {
    cout << a.first << "_" << a.second << '\n';
}
void print(vector<pii> a) {
    for(auto it : a) {
        cout << it.first << "_" << it.second << " ";
    }
    cout << '\n';
}
void print(vector<vector<pii>> a) {
    for(auto it : a) {
        for(auto kt : it)  {
            cout << kt.first << "_" << kt.second << " ";
        }
        cout << '\n';
    }
}
vector<vector<int>> prefx;
int query(int l, int r) {
	int ans = 0;
	for(int j=0; j<26; j++) {
		int x = prefx[j][r] - (l-1<0?0:prefx[j][l-1]);
		if(x) ans++;
	}
	return ans;
}
void solve() {
	string s;
	cin >> s;
	int n = s.size();
	prefx = vector<vector<int>> (26, vector<int> (n, 0));
	for(int i=0; i<(int)s.size(); i++) {
		prefx[s[i]-'a'][i]++;
		for(int j=0; j<26; j++) {
			if(i)
				prefx[j][i] += prefx[j][i-1];
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if(a == b) {
			pyes;
			continue;
		}
		if(s[a] != s[b]) {
			pyes;
			continue;
		}
		else if(query(a, b) >= 3) {
			pyes;
			continue;
		} else {
			pno;
		}
	}
}

signed main() {
  fastIO();
  int t = 1;
  for(int i=0; i<t; i++) solve();
  return 0;
}
