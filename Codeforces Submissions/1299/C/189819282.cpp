#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18, MOD = 1e9+7, N = 1e6+5;

int n, arr[N], x;

void solve(){
    cin >> n;
    vector<pair<double, int>> st;
    for(int i = 0; i < n; i++){
        cin >> x;
        st.emplace_back(x, 1);
        while(st.size() >= 2){
            if(st[st.size()-2] >= st[st.size()-1]){
                st[st.size()-2].first = (st[st.size()-2].first*st[st.size()-2].second + st[st.size()-1].first*st[st.size()-1].second) / (st[st.size()-1].second+st[st.size()-2].second);
                st[st.size()-2].second = st[st.size()-1].second+st[st.size()-2].second;
                st.pop_back();
            } else {
                break;
            }
        }
    }

    for(pair<double, int> u : st){
        for(int i = 0; i < u.second; i++){
            cout << fixed << setprecision(12) << u.first << "\n";
        }
    }
    

    
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
 	 	  	 		  		 	 		 	 	 		