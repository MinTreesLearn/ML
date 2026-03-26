#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, temp;
    scanf("%lld", &n);
    unordered_map <ll,ll> ans;

    for (ll i = 1; i <= n; i++) {
        scanf("%lld", &temp);
        if (ans.count(temp-i) != 0) 
            ans[temp-i] += temp;
        else 
            ans[temp-i] = temp;
    }
    ll maxi = LLONG_MIN;
    for (auto &it : ans) {
        if (it.second > maxi)
            maxi = it.second;
    }
    printf("%lld", maxi);
    return 0;
}
