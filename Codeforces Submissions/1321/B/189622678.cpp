#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n;
    cin>>n;
    vector<int> b_n(n);
    map<int, vector<int>> m;
    for(int i = 0; i<n; i++){
        cin>>b_n[i];
        if(m.find(b_n[i] - i) == m.end()){
            m.insert(make_pair(b_n[i]-i, 1));
            auto itr = m.find(b_n[i]-i);
            (*itr).second[0] = b_n[i];
        }
        else{
            auto itr = m.find(b_n[i] - i);
            ((*itr).second).push_back(b_n[i]);
        }
    }
    int ans = -99999999999999999;
    for(auto itr = m.begin(); itr!= m.end(); itr++){
        int curr = 0;
        auto itr2 = itr;
        int number = ((*itr2).second).size();
        for(int i = 0; i<number; i++){
            curr+= ((*itr2).second)[i];
        }
        ans = max(ans,curr);
    }
    cout<<ans<<endl;

}
