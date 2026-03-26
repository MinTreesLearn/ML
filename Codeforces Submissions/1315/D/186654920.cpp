#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vll vector<int>
#define all(v) v.begin(), v.end()
#define testcases int t; cin>>t; while(t--)

void solve() {
    int n ;
    cin >>n ;
    vll t(n) ;
    map<int, vll>sweepLine ;
    for (int i = 0; i < n; ++i)
    {
        int x ;
        cin >> x ;
        sweepLine[x].push_back(i) ;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> t[i] ;
    }
    int ans = 0, prev = 0 ;
    priority_queue<pair<int, int>>pq ; // time , pos 
    for(auto &[curr , vec] : sweepLine){
        int i = 0 ;
        while(prev + i < curr and pq.size()){
            auto time = pq.top().first ;
            auto pos = pq.top().second ;
            pq.pop() ;

            ans += time * (prev + i - pos) ;
            i++ ; 
        }

        for(auto ele : vec){
            pq.push({t[ele] , curr}) ;
        }
        prev = curr ;
    }
    int i = 0 ;
    while(pq.size()){
         auto time = pq.top().first ;
         auto pos = pq.top().second ;
         pq.pop() ;

         ans += time * (prev + i - pos) ;
         i++ ;
    }

    cout << ans ;

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // testcases
    solve();
}
