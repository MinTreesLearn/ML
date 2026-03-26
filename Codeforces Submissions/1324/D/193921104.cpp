#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

#define not_less_than(v, n) lower_bound(v.begin(), v.end(), n)                   // n >=
#define not_more_than(v, n) lower_bound(v.rbegin(), v.rend(), n, greater<int>()) // n <=
#define more_than(v, n) upper_bound(v.begin(), v.end(), n)                       // n <
#define less_than(v, n) upper_bound(v.rbegin(), v.rend(), n, greater<int>())     // n >

int dx[] = {-1, -1, -1, 0, 0, +1, +1, +1};
int dy[] = {-1, +1, 0, -1, 1, -1, 0, +1};
    
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);   
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        v[i] = a[i] - b[i];
    }
    sort(v.begin(), v.end());

    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        int ans = 1 - v[i];
        int l = i, r = n-1;
        while(l <= r)
        {
            int mid = (l+r)/2;
            if(v[mid] >= ans)
                r = mid - 1;
            else
                l = mid + 1;
        }
        sum += n - l;
        if(ans <= 0)
            sum--;
    }

    cout << sum << endl;
}