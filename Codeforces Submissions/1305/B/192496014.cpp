#include <bits/stdc++.h>
#define Dattebayo() ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define all(v) ((v).begin()), ((v).end())
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define ll long long
#define F first
#define S second
#define endl "\n"
using namespace std;
///Where there's a will there's a way.
///Well, نـورت الكــود يـعـمـنـا

vector <vector<int>> res;
vector <int> ans;
string s;
void solve(){
    for(int i=0 ,j=s.size()-1 ; i<j ;i++){
        if(s[i]=='('){
            for( ; j>i ;j --)
                if(s[j]==')'){
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    s[i]='*',s[j]='*';
                    break;
                }
        }
    }
    sort(all(ans));
    res.push_back(ans);
}
bool check(){
    bool ex= false;
    for(char i : s){
        if(i=='(') ex= true;
        if(i==')' && ex) return false;
    }
    return true;
}
int main()
{
    Dattebayo();
    cin>>s;
    while(!check())
        solve();
    cout<<res.size()<<endl;
    if(!res.empty()){
        for(const auto& i:res){
            cout<<i.size()<<endl;
            for(auto j:i)
                cout<<j<<" ";
            cout<<endl;
        }
    }
}
