#include <utility>
#include <bits/stdc++.h>
using namespace std;


#define si size
#define f first
#define s second
#define vec vector
#define pb push_back

typedef vec <int> vi;

void solve(){
    vi seq;
    pair <vi, vi> res;
    string s;
    int n, cnt = 0;
    cin >> s;
    n = s.length();

    for(int i = 0; n > i; i++){
        seq.pb(int(s[i]) - 48);
    }

    for(int i = 0, j = 0; n > i; i++){
        if(i == 0){
            res.f.pb(seq[0]);
            res.s.pb(1);
        }
        else if(seq[i] != res.f[j]){
            res.f.pb(seq[i]);
            res.s.pb(1);
            j++;
        }
        else res.s[j] += 1;
    }

    if(res.f.si() == 1 && res.f[0] == 1) 
        cout << "0\n";
    else if(res.f.si() == 2 && res.f[0] == 0 && res.f[1] == 1)
        cout << "0\n";
    else if(res.f.si() == 2 && res.f[0] == 1 && res.f[1] == 0)
        cout << "0\n";
    else if(res.f.si() == 3 && res.f[0] == 0 && res.f[1] == 1 && res.f[2] == 0)
        cout << "0\n";
    else{
        for(int i = 1; res.f.si() - 1 > i; i++){
            if(res.f[i] == 0) cnt += res.s[i];
            if(res.s[i] == 0) break;
        }
        cout << cnt << endl;
    }
}

int main(){
    int t; cin >> t;
    while(t--) solve();
}

// :D