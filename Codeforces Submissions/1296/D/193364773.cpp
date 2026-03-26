#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include<fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
#define debug(x) std::cerr << __FUNCTION__ << ":" << __LINE__ << " " << #x << " = " << x << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> ar(n);
    for (int i = 0; i < n; i++){
        cin >> ar[i];
    }
    vector<ll> min_isp(n);
    for (int i = 0; i < n; i++){
        ll temp = ar[i] % (a + b);
        if (temp == 0){
            temp = a + b;
        }
        if (temp <= a) {
            min_isp[i] = 0;
        }
        else{
            temp-=a;
            if (temp <= 0){
                min_isp[i] = 0;
            }
            else{
                min_isp[i] = min_isp[i] + (temp / a) + 1 * (temp%a != 0);
            }
        }
    }
    sort(min_isp.begin(), min_isp.end());
    ll ans = 0;
    for (int i = 0; i < n; i++){
        if (c - min_isp[i] >= 0){
            ans++;
            c = c - min_isp[i];
        }
        else{
            break;
        }
    }
    cout << ans;
    return 0;
}