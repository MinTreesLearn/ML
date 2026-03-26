#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n; cin >> n;
    vector<array<int, 2>> A(n);
    for (auto& [x, y] : A)
        cin >> x;
    for (auto& [x, y] : A)
        cin >> y;
    sort(A.begin(), A.end());

    multiset<array<int, 2>, std::greater<>> Q;
    int s = 0;
    ll res{};
    int i = 0;
    while (i < (int)A.size() || !Q.empty())
    {
        while (i < (int)A.size() && A[i][0] == s)
        {
            Q.insert({A[i][1], A[i][0]});
            i++;
        }
        
        if (Q.empty())
        {
            s = A[i][0];
            continue;
        }
        auto [cost, val] = *Q.begin();
        res += (ll)(s - val) * cost;
        Q.erase(Q.begin());
        s++;
    }
    std::cout << res << '\n';
}
