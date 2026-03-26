#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <bitset>
#include <unordered_map>

using namespace std;
#define x first
#define y second 
#define mest(x,y) memset(x, y, sizeof x)
#define endl "\n"
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define ppb pop_back
#define INF 0x3f3f3f3f
#define ll_INF 0x7f7f7f7f7f7f7f7f
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define PII pair<int,int> 
#define PIII pair<int,pair<int,int>>
#define int long long
int dir[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
 
const int N = 1510; 
//int h[N], e[N], ne[N], idx;
int g[N];
int n, m, k;

void solve()
{
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> g[i];

	unordered_map<int, vector<PII>> mp;
	for(int i = 1; i <= n; i ++)
	{
		int s = 0;
		for(int j = i; j <= n; j ++)
		{
			s += g[j];
			mp[s].push_back({i, j});
		}
	}

	int res = 0;
	vector<PII> ans;

	for(auto  &q : mp)
	{
		vector<PII> w = q.y;
		sort(w.begin(), w.end(), [&](PII a, PII b){
			return a.y < b.y;
		});
		vector<PII> tmp;
		int ed = w[0].y, s = 1;
		tmp.push_back(w[0]);
		for(auto t : w)
		{
			int l = t.x, r = t.y;
			if(l > ed)
			{
				s ++;
				tmp.push_back({l, r});
				ed = r;
			}
		}

		if(res < tmp.size())
		{
			res = tmp.size();
			ans = tmp;
		}
	}

	cout << res << endl;
	for(auto t : ans)
	{
		cout << t.x << " " << t.y << endl;
	}

}
signed main()
{
	int _ = 1;
// 	cin >> _;
	while(_ --)
	{
		solve();
	}
	return 0;	
}