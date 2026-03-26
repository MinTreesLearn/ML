#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector< vector <int>>;
using vl = vector<ll>;
using vll = vector< vector <ll>>;
using vpi = vector <pair <int, int>>;
using vpl = vector <pair <ll, ll>>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define loop(i,n) for(int i = 0;i<n;i++)
#define loop1(i,n) for(int i = 1;i<n;i++)
#define loopx(i, x, n) for(int i = x; i<n; i++);
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;


ll arr[400001];
ll tree[1600004];

ll build(int l, int r, int index) {
    if (l == r) {
        tree[index] = arr[l];
        return tree[index];
    }
    int mid = (l + r) / 2;
    tree[index] = min(build(l, mid, 2 * index + 1), build(mid + 1, r, 2 * index + 2));
    return tree[index];
}

void update(int k, int u, int l, int r, int index) {
    int mid = (l + r) / 2;
    if (l == r) {
        tree[index] += u;
        arr[k] += u;
        return;
    }
    if (k <= mid) update(k, u, l, mid, 2 * index + 1);
    else update(k, u, mid + 1, r, 2 * index + 2);

    tree[index] = min(tree[index * 2 + 1], tree[index * 2 + 2]);
}


ll query(int l, int r, int start, int end, int index) {
    if (l > end || start > r) return 999999999;
    if (start <= l && r <= end) return tree[index];
    int mid = (l + r) / 2;
    return min(query(l, mid, start, end, 2 * index + 1) , query(mid + 1, r, start, end, 2 * index + 2));
}



int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q, x;
    cin >> q >> x;

    loop(i, x) arr[i] = i;
    build(0, x - 1, 0);
    while (q--) {
        int k;
        cin >> k;
        k %= x;
        update(k, x, 0, x - 1, 0);
        cout << query(0, x - 1, 0, x - 1, 0) << endl;



    }



    return 0;

}





