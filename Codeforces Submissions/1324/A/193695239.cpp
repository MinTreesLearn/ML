#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int32_t test; cin >> test;
    int32_t n, tmp; bool check;
    while (test--)
    {
        cin >> n; 
        set <int32_t> st;
        for (int i = 0; i < n; i++)
        { cin >> tmp; st.insert(tmp); }
        if (st.size() == 1) cout << "YES\n";
        else 
        {
            vector <int32_t> scan;
            for (auto &x : st) scan.push_back(x);
            check = true;
            for (int i = 1; i < scan.size() && check; i++)
                if ((scan[i] - scan[i-1])%2 != 0) check = false;
            if (check) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}