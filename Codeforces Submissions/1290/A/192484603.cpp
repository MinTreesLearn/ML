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
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <chrono>
#include <random>

#define ld long double
#define ll long long
using namespace std;

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    k = min(k,m-1);
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int rem = m - k-1;
    int ans = -1e9;
    for(int l=0;l<=k;l++){
        int mn = 1e9;
        for(int l2=0;l2<=rem;l2++){
            int r1 = k-l, r2 = rem-l2;
            mn = min(mn, max(arr[l+l2], arr[n-r1-r2-1]));
            // cout<<arr[l+l2]<<" "<<arr[n-(k-l)-(rem-l2)]<<endl;
        }
        ans = max(ans,mn);
    }
    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(15)<<fixed;
    int t=1;
    cin >> t;
    for (int c = 0; c < t; c++)
    {   
        // cout<<"Case #"<<c+1<<": ";
        solve();
    }
}