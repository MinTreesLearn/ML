#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

// long loooooooooooooooong;
void solve(ll kkkk, ll tttt)
{
    int n, q; cin >> n >> q;

    vector<vector<bool>> arr(n + 5, vector<bool> (2, false));
    set<int> sett;

    while (q--)
    {
        int a, b; cin >> a >> b; a--;
        arr[b][a] = !arr[b][a];

        if (arr[b][a] && arr[b + 1][1 - a] || arr[b][1 - a]  && arr[b + 1][a]  || arr[b][a]  && arr[b][1 - a] )
            sett.emplace(b);
        else
            sett.erase(b);

        if (arr[b - 1][a] && arr[b][1 - a] || arr[b - 1][1 - a] && arr[b][a] || arr[b - 1][a] && arr[b - 1][1 - a])
            sett.emplace(b - 1);
        else
            sett.erase(b - 1);

        if (sett.size())
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

void fast() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

int main()
{
    fast();
    int t = 0, i = 0;

//    int t; cin >> t;
//    for (int i = 1; i <= t; i++)

    solve(t, i);
    return 0;
}

