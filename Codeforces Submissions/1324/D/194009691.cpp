#define RAGHAV_PATEL ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define int long long int
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 int  printNcR(int n, int r)
{
   int  p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            int  m = gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }     
    }
    else
        p = 1;

    return p;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    vector<int> diff(n);
    int p=0,ng=0,z=0;
    for(int i=0;i<n;i++){
        diff[i]=a[i]-b[i];
        if(diff[i]==0)
            z++;
        else if(diff[i]>0)
            p++;
        else 
            ng++;

    }
    int ans=0;
   
    if(p>=2)
        ans += (printNcR(p, 2));
    if(p>0&&z>0)
        ans+=(printNcR(p,1) * printNcR(z,1));   
   // cout<<"ans 1 : "<<ans<<"\n";
    sort(diff.begin(), diff.end());
    for(int i=0;i<n;i++){
        if(diff[i]<0)
        {
            int x = n-(upper_bound(diff.begin(), diff.end(),abs(diff[i]))-diff.begin());
            ans+=x;
        }
        else{
            break;
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
    RAGHAV_PATEL
    int t, i;
    //cin >> t;
     t = 1;

    while (t)
    {
        solve();
        t--;
    }
}

/*
 int l = ans.size();
            while(l>=0&&ans[l]==0)
                l--;
*/