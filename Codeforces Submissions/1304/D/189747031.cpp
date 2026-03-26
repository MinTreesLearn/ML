#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int m = n;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (i < n - 1 && s[i] == '<') {
                ++i;
                ++len;
            }
            for (int j = i; j >= i - len + 1; --j) {
                a[j] = m--;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        m = 1;
        for (int i = 0; i < n; ++i) {
            int len = 1;
            while (i < n - 1 && s[i] == '>') {
                ++i;
                ++len;
            }
            for (int j = i; j >= i - len + 1; --j) {
                a[j] = m++;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
