#include<bits/stdc++.h>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    string s; cin >> s;

    int prefix = 0, toChange = 0, index = 0, answer = 0;

    for(int i = 0; i < n; i++)
    {
        prefix += (s[i] == '(');
        prefix -= (s[i] == ')');
        if(prefix < 0) toChange = 1;

        if(prefix == 0)
        {
            if(toChange) answer += (i - index + 1);
            index = i + 1;
            toChange = 0;
        }
    }

    cout << (index == n ? answer : -1);
}