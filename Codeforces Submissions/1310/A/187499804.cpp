#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())

using namespace std;
using ll = long long;

class Task {
public:
    void solve() {
        int l;
        cin >> l;
        vector<ll> arr(l);
        for (int i = 0; i < l; i++) {
            cin >> arr[i];
        }
        map<ll, vector<ll>> count_to_prize;
        ll tmp;
        for (int i = 0; i < l; i++) {
			cin >> tmp;
			count_to_prize[arr[i]].pb(tmp);
		}
		vector<pair<ll, vector<ll>>> book;
		for (auto p : count_to_prize) {
			book.pb({p.first, p.second});
		}
		reverse(book.begin(), book.end());
        ll result = 0;
        priority_queue<ll> q;
        ll q_total = 0;
		ll now_check = 0;
		while (!book.empty()) {
			if (q_total == 0 && book.back().first > now_check) {
				now_check = book.back().first;
				continue;
			}
			else if (book.back().first > now_check) {
				q_total -= q.top();
				q.pop();
				result += q_total;
			}
			else {
				for (int i : book.back().second) {
					q_total += i;
					q.push(i);
				}
				book.pop_back();
				q_total -= q.top();
				q.pop();
				result += q_total;
			}
			now_check++;
		}
		while (!q.empty()) {
			q_total -= q.top();
			q.pop();
			result += q_total;
		}
		cout << result << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Task solver;
    solver.solve();
    return 0;
}
