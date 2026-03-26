#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
#define ld long double
typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define FORR(i,a,b) for (int i = a; i > b; i--)
#define srch binary_search
#define ub upper_bound
#define lb lower_bound
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PP pop_back
#define F first
#define SQ(x) x * x
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define LSOne(S) __builtin_ctz((S & -S))
#define nx continue;
#define tc int te; cin >> te; while(te--)
#define pq priority_queue
#define fateen     ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef pair<int,int> pii;
const int inf = 1e18;
const int mod = 1e9 + 7;

signed main() {
    fateen;
tc {
        int n;
        cin >> n;
        vi v(n);
        int evencnt = 0, oddcnt = 0;
        FOR(i, 0, n) {
            cin >> v[i];
            if (v[i] & 1) oddcnt++;
            else evencnt++;
        }

        if (evencnt >= 1) {
            int i = 0;
            cout << 1 << endl;
            while (i < n) {
                if (!(v[i] & 1)) {
                    cout << ++i << endl;
                    break;
                }
                i++;
            }

        } else if (oddcnt >= 2) {
            int cnt = 0;
            int i = 0;
            cout << 2 << endl;
            while (cnt != 2) {
                if (v[i] & 1) {
                    cout << ++i << " ";
                } else i++;
                cnt++;
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
	  	  	   				 	   		 	 	  	 	