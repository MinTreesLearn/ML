#define RAGHAV_PATEL ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define int long long int
int find_sumdigit(int number)
{
    int ans = 0;
    while (number > 0)
    {

        ans += number % 10;
        number /= 10;
    }

    return ans;
}
void solve()
{
    int n;
    cin >> n;
   vector<int>v(n);
   for(int i=0;i<n;i++)
    cin>>v[i];
    vector<int>fv(n);
    vector<int>bv(n);
    for(int i=0;i<n;i++){
        fv[i]=i;
        bv[i]=n-i-1;
    }
    
   int fr=-1,br=n;
   for(int i=0;i<n;i++){
      if(v[i]>=fv[i])
      fr++;
      else{
        break;
      }
   }
   for(int i=n-1;i>=0;i--){
    if(v[i]>=bv[i])
    br--;
    else
        break;
   }
  // cout<<fr<<" "<<br<<" ";
   if(fr>=br)
    cout<<"Yes\n";
    else 
    cout<<"No\n";

}

signed main()
{
    RAGHAV_PATEL
    int t, i;
    cin >> t;
    // t = 1;

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