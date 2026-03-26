#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1e9 + 7

string a = "abcdefghijklmnopqrstuvwxyz";

void dfs(string& k, char x, map<char, vector<char>>& mp, map<char, bool>& visited){
    if(x < 'a' || x > 'z') return;
    k += x;
    visited[x] = true;
    // if(mp[x][0] == ' ') return;
    for(char c: mp[x]){
        if(!visited[c]) dfs(k, c, mp, visited);
    }
}

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    vector<bool> visited(26, false);
    visited[s[0] - 'a'] = true;
    string res(1, s[0]);

    int pos = 0;

    for(int i=1; i<n; ++i){
        if(visited[s[i] - 'a']){
            if(pos && res[pos - 1] == s[i]) pos--;
            else if(pos < res.size() - 1 && res[pos + 1] == s[i]) pos++;
            else{
                cout << "NO\n";
                return;
            }
        }

        else{
            visited[s[i] - 'a'] = true;
            if(!pos) res = s[i] + res;
            else if(pos == res.size() - 1){
                res += s[i];
                pos++;
            }
            else{
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n" << res;
    for(int i=0; i<26; ++i){
        if(!visited[a[i] - 'a']) cout << a[i];
    }
    cout << "\n";

    // map<char, vector<char>> mp;
    // for(int i=1; i<n-1; ++i){
    //     vector<char> v = mp[s[i]];
    //     if(find(begin(v), end(v), s[i - 1]) == end(v)) mp[s[i]].push_back(s[i - 1]);
    //     if(find(begin(mp[s[i]]), end(mp[s[i]]), s[i + 1]) == end(mp[s[i]])) mp[s[i]].push_back(s[i + 1]); 
    // }

    // if(find(begin(mp[s[0]]), end(mp[s[0]]), s[1]) == end(mp[s[0]])) mp[s[0]].push_back(s[1]);
    // if(find(begin(mp[s[n - 1]]), end(mp[s[n - 1]]), s[n - 2]) == end(mp[s[n - 1]])) mp[s[n - 1]].push_back(s[n - 2]);

    // int cnt = 0;
    // char pos;
    // for(auto x: mp){
    //     if(x.second.size() == 1){
    //         pos = x.first;
    //         cnt++;
    //     }
    // }

    // if(n > 1 && cnt != 2) cout << "NO\n";

    // else{
    //     string res = "";
    //     map<char, bool> visited;
    //     dfs(res, pos, mp, visited);
    //     // for(auto x: mp){
    //     //     if(!visited[x.first]) dfs(res, x.first, mp, visited);
    //     // }

    //     for(int i=0; i<26; ++i){
    //         if(mp[a[i]].empty()) res.push_back(a[i]);
    //     }

    //     cout << "YES\n" << res << "\n";
    // }

    // for(auto x: mp){
    //     cout << x.first << " ";
    //     for(int k=0; k<x.second.size(); ++k){
    //         cout << x.second[k] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
