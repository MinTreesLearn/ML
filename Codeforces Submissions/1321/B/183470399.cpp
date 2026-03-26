#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>


using namespace std;

#define x first
#define y second
#define int long long

typedef pair<int, int> PII;

const int N = 2e5 + 10, M = 2 * N;
int a[N];
int n;


signed main()
{
    int T = 1;
    // cin >> T;
    while(T --){
        int n;
        cin >> n;
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        map<int, int> mp;
        for (int i = 0; i < n; i ++ ){
            mp[a[i] - i] += a[i];
        }
        int ans = 0;
        for(auto x:mp){
            ans = max(ans, x.second);
        }
        cout << ans << endl;
    }
    return 0;
}
/*

10 7 1 9 10 15
1  2 3 4 5  6


1 7 9 10 10 15
3 2 4 1  5  6

*/