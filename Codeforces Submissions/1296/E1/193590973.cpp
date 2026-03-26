#include <iostream>
using namespace std;
int main() {
    int n;
    string s, t = "";
    cin >> n >> s;
    char c = 'a', d = 'a';
    for (int i = 0; i < n; i++) {
        if (c <= s[i]) {
            c = s[i];
            t += "0";
        }
        else if (d <= s[i]) {
            d = s[i];
            t += "1";
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << t;
}
