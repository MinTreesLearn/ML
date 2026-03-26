#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<deque>
#include<queue>
#include<random>
#include<climits>
#include<ctime>
#include<string>

#define ft first
#define sd second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int balance = 0;
    bool bad = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!bad) {
            if (s[i] == '(') {
                balance++;
                continue;
            }
            if (balance)
                balance--;
            else {
                bad = true;
                balance--;
                ans++;
            }
        } else {
            ans++;
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;


                
            }
            if (balance >= 0) {
                bad = false;
            }
        }
    }
    if (balance == 0) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
