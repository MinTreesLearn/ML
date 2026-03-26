// <3 //
#include<bits/stdc++.h>
#define ll long long
#define out return 0;
#define str string
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main()
{
    FAST
    int n, k = 0, m = 0, l = 0;
    cin>>n;
    int a[n], b[n];
    for (int i = 0; i < n; i ++)
    {
        cin>>a[i];
        m += a[i];
    }
    for (int i = 0; i < n; i ++)
    {
        cin>>b[i];
        l += b[i];
        if (b[i] == 0 && a[i] == 1) k ++;
    }
    if (k == 0)
    {
        cout<<-1;
        out
    }
    int ans;
    ans = (l - m + 1) / k;
    if ((l - m + 1) % k > 0) ans ++;
    cout<<max(0, ans) + 1;
    out
}
