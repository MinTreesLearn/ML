#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define loop(n) for (int i{0}; i<n; ++i)
#define lop(n) for (int i{1}; i<n; ++i)
const int N = 2e5+7, mod= 1e9 + 7;


int left_most(int n){
    int pos = 0;
    while (n > 0) {
        n = n >> 1;
        pos++;
    }
    return pos;
}

bool sortbyfirst(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    return a.second < b.second;
    
}


void solve(){
    
    int n; cin>>n;
    vector <pair<int, int>> v;
    string s="";
    loop(n){
        int x,y; cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), sortbyfirst);
    //sort(v.begin(), v.end(), sortbysec);
    
    //cout<<v[0].first-0<<" "<<v[0].second-0<<endl;
    loop(v[0].first) s+='R';
    loop(v[0].second) s+='U';
    for (int i{1}; i<v.size(); ++i){
        //cout<<v[i].first<<" "<<v[i].second<<endl;
        int x_d, y_d;
        x_d= v[i].first- v[i-1].first;
        y_d= v[i].second-v[i-1].second;
        //cout<<x_d<<" "<<y_d<<endl;
        if (x_d <0 || y_d<0){
            cout<<"NO"<<endl;
            return;
        }
        loop(x_d) s+='R';
        loop(y_d) s+='U';
        
    }
    cout<<"YES"<<endl;
    cout<<s<<endl;

}

int main() {
    FAST_IO;
   
    int t; cin>>t;
    while(t--) 
        solve();
    
    
    
    
    
    
    return 0;
}