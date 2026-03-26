#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#include <conio.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define el '\n'
#define pi 3.14159265358979323846
#define NumOfDigit(w) (int)(log10(w) + 1)
#define fr(p_) for(auto &p__ : p_) cout<<p__<<" ";
#define debug(x) cout<<"[" << #x << " is:" << x << "]"<<el;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// decimal --> fixed << setprecision
#define orderedset template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define tree typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set


bool sortbyPair(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second != b.second)
        return (a.second > b.second);
    else
        return (a.first < b.first);
}


ll fast_power(ll base, ll exp) {
    if (!exp) return 1;

    ll ans = fast_power(base, exp / 2);
    ans = (ans % 1000000007 * ans % 1000000007) % 1000000007;
    if (exp & 1)
        ans = (ans % 1000000007 * base % 1000000007) % 1000000007;
    return ans;
}


ll convert_binary_to_decimal(long long n) {
    int dec = 0, i = 0, rem;

    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        i++;
    }
    return dec;
}


bool is_prime(ll n) {
    if (n == 0 or n == 1)
        return 0;

    for (int i = 2; i < n; ++i) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ll lcm(ll a, ll b) {
    return ((((a / gcd(a, b)) % 1000000009) * (b % 1000000009)) % 1000000009);
}


//ll ncr2(ll n, ll r) {
//    ll ans = 1, fact = 2;
//    for (ll i = n - r + 1; i <= n; i++) {
//        ans *= i;
//        if (ans % fact == 0 and fact <= r)
//            ans /= fact++;
//    }
//    return ans;
//}

//ll factorial[1000006], inversefactorial[1000006];
//
//void calcFacAndInv(ll n) {
//    factorial[0] = inversefactorial[0] = 1;
//    for (ll i = 1; i <= n; i++) {
//        factorial[i] = (i * factorial[i - 1]) % 1000000007;
//        inversefactorial[i] = fast_power(factorial[i], 1000000007 - 2);
//    }
//}
//
//ll ncr1(ll n, ll r) {
//    return ((factorial[n] % 1000000007 *
//             ((inversefactorial[n - r] % 1000000007 * inversefactorial[r] % 1000000007) % 1000000007) % 1000000007) %
//            1000000007);
//}
//
//
//ll npr(ll n, ll r) {
//    return ((factorial[n] % 1000000007 * inversefactorial[n - r] % 1000000007) % 1000000007);
//}


//vector<bool> sieve(ll n) {
//    vector<bool> isPrime(n + 1, 1);
//    isPrime[0] = isPrime[1] = 0;
//    for (ll i = 2; i <= n; i++)
//        if (isPrime[i])
//            for (ll j = 2 * i; j <= n; j += i)
//                isPrime[j] = 0;
//    return isPrime;
//}

//vector<pair<ll, ll>> factorize(ll n) {
//    vector<pair<ll, ll>> fact;
//    for (ll i = 2; i * i <= n; i++) {
//        int cnt = 0;
//        while (n % i == 0) {
//            n /= i;
//            cnt++;
//        }
//        if (cnt) fact.push_back({i, cnt});
//    }
//    if (n > 1) fact.push_back({n, 1});
//    return fact;
//}

//vector<int> getdivisors(ll n) {
//    vector<int> divs;
//    for (ll i = 1; i * i <= n; i++) {
//        if (n % i == 0) {
//            divs.push_back(i);
//            if (i != n / i) divs.push_back(n / i);
//        }
//    }
//    return divs;
//}


// upper_bound -->(greater than only) -->return iterator
// lower_bound -->(greater than or equal) -->return iterator


//vector<ll> factorize(ll n) {
//    vector<ll> fact;
//    for (ll i = 2; i * i <= n; i++) {
//        while (n % i == 0) {
//            n /= i;
//            fact.push_back(i);
//        }
//    }
//    if (n > 1) fact.push_back(n);
//    return fact;
//}

ll n, g, b;

int main() {
    fast
    int t;
    cin >> t;
    while (t--) {
        ll n, g, b;
        cin >> n >> g >> b;

        ll need = (n + 1) / 2;
        ll lo = n, hi = 1e18, mid, ans = LONG_LONG_MAX;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            ll R = (mid / (g + b));
            ll rem = mid % (g + b);
            ll good = R * g;
            good += min(g, rem);
            if (good >= need) {
                hi = mid - 1;
                ans = mid;
            } else
                lo = mid + 1;
        }
        cout << ans << el;
    }
    return 0;
}