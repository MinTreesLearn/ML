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
    string s;
    cin >> s;
    //s = "qdpinbmcrfwxpdbfgozvvocemjructoadewegtvbvbfwwrpgyeaxgddrwvlqnygwmwhmrhaizpyxvgaflrsvzhhzrouvpxrkxfza";
    map<char, ll> sl;
    for (int i = 0; i < s.size(); i++) {
        sl[s[i]]++;
    }
    //cout << sl['r'] << " " << sl['v'] << '\n';
    pair<char, ll> big1;
    pair<char, ll> big2;
    //cout << big1.first << " " << big1.second << "\n";
    //cout << big2.first << " " << big2.second << "\n";
    ll maxi = INT64_MIN;
    string s_helper = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < s_helper.size(); i++){
        ll now = 0;
        for (int j = 0; j < s_helper.size(); j++){
            big1 = {s_helper[i], sl[s_helper[i]]};
            big2 = {s_helper[j], sl[s_helper[j]]};
            now = 0;
            if (i == j){
                maxi = max(maxi, max((sl[s_helper[i]] * (sl[s_helper[i]] - 1)) / 2, (sl[s_helper[i]])));
                //cout << sl[s_helper[i]] << '\n';
            }
            else {
                for (int k = 0; k < s.size(); k++) {
                    if (s[k] == big1.first) {
                        now = now + (max(0ll, big2.second));
                        //cout << s_helper[i] << " " << s_helper[j] << " " << big2.second << " " << now << '\n';
                    }
                    if (s[k] == big2.first) {
                        big2.second--;
                    }
                }
                maxi = max(maxi, now);
            }
        }
    }
    cout << maxi;
    return 0;
}
