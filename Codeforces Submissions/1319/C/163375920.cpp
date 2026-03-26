#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int t = 0; t < n; t++) {
        int mxpos = -1;
        for (int i = 0; i < int(s.size()); i++) {
            if (i > 0 && s[i] == s[i - 1] + 1)
                if (mxpos == -1 || s[mxpos] < s[i])
                    mxpos = i;
            
            if (i + 1 < int(s.size()) && s[i] == s[i + 1] + 1)
                if (mxpos == -1 || s[mxpos] < s[i])
                    mxpos = i;
        }

        if (mxpos != -1)
            s.erase(s.begin() + mxpos);
    }
    cout << n - int(s.size()) << "\n";
}