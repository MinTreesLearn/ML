#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> odd;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int n;
    string str;
    cin >> n >> str;
    stack<int> st;
    int l = 0, r = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '(') ++l;
        if (str[i] == ')') ++r;
        if (st.size() != 0 && str[st.top()] == '(' && str[i] == ')') {
            st.pop();
        } else {
            st.push(i);
        }
        if (l == r && st.size() > 0) {
            while (st.size() > 1) st.pop();
            ans += i - st.top() + 1;
            st.pop();
        }
    }
    if (l != r) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}
