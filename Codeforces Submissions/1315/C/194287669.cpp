#include <bits/stdc++.h>
using namespace std;

void solve(){ 
    int n; cin>>n;
    int cs;
    vector <int> s,c;
    for (int i = 1 ; i <= 2*n ; i ++){
        s.push_back(i);
    }
    for (int i = 0 ; i < n ; i ++){
        cin>>cs;
        c.push_back(cs);
        remove(s.begin(),s.end(),cs);
        s.pop_back();
    }
    bool found = false;
    vector<int> ans;
    for(auto x:c){
        found = false;
        for(auto y:s){
            if(x<y){
                ans.push_back(y);
                remove(s.begin(),s.end(),y);
                s.pop_back();
                found = true;
                break;
            }
        }
        if (not found){
            cout<<-1;
            return ;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<c[i]<<" "<<ans[i]<<" ";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        solve();
        cout<<'\n';
    }
    
	return 0;
}
