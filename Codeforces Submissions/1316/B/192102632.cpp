#include<bits/stdc++.h>
#include<stdio.h>

#define T(n) for(int i=0; i<n; i++)
#define T2(k) for(int j=0; j<k; j++)
#define fi first
#define se second
#define os ios_base::sync_with_stdio(false);
#define INFI 0x3f3f3f3f

using namespace std;
typedef long long ll;

int arr[129];
int arr2[2000006];

int main(){
    int aan;
    cin >> aan;
    T(aan){
     int n;
    string s;
    cin >> n >> s;
    map<char, int> mp;
    for(int i = 0; i < n; i++) {
        mp[s[i]]++;
    }
    auto mn = mp.begin();
    int l = -1;
    string ans;
    char c = mn->fi;
    for(int i = 0; i < n; i++) {
        if(s[i] == c) {
            string add = s.substr(0, i);
            if((n - i) % 2 != 0) {
                reverse(add.begin(), add.end());
            }
            string t = s.substr(i) + add;
            if(l == -1) {
                l = i;
                ans = t;
            } else if(ans > t) {
                ans = t;
                l = i;
            }
        }
    }
    cout << ans << "\n" << l+1 << "\n";
    }   
    return 0;
}