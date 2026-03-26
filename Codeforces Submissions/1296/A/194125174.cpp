#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#define _CRT_SECURE_NO_WARNINGS //scanf & printf
#define fast std::ios_base::sync_with_stdio(0);cin.tie(NULL);
#define Input freopen("filename", "r", stdin);
#define ll long long
#define endl "\n"
//cout << fixed << setprecision(9);
using namespace std;
void solve()
{
    int t;
    cin >> t;
    int n;
    int sum;
    int odd;
    int even;
    for (int i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        odd = 0;
        even = 0;
        int arr[20000];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (arr[j] % 2 != 0 || arr[j] == 1) {
                odd++;
            }
            else {
                even++;
            }
            sum += arr[j];
        }

        if (sum % 2 != 0 || sum == 1) {
            cout << "YES" << endl;
        }
        else {
            if (odd != 0 && even != 0) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
}
int main()
{
	fast
		solve();
	return 0;
}

