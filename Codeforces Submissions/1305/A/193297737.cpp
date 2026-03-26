#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<long long> vll;

int main() {
    int n, m, a;
    cin >> n;
    for (int i = 0; i < n; ++i) {

        cin >> m;
        vector<int> arr;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            arr.push_back(a);
        }
        vector<int> arr1;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            arr1.push_back(a);
        }
        std::sort(arr.begin(), arr.end());
        std::sort(arr1.begin(), arr1.end());
        for (int j = 0; j < m; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < m; ++j) {
            cout << arr1[j] << " ";
        }
        cout << endl;

    }
}