#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define Thank_Queue_Spiderman ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define BITS sizeof(int) * 8
#define TestCase ll T;  cin >> T
int arr[1000000];
bool flag = false;


int main() {
    Thank_Queue_Spiderman
    TestCase;
    while(T--){
        int n; cin >> n;
        string s; cin >> s;
        int odd = 0;
        for (char c : s) if ((c - '0') & 1) odd++;
        if (odd <= 1) { cout << -1  << endl; continue; }
        int cnt = 0;
        for (char c : s) {
            if ((c - '0') & 1) { cout << c; cnt++; }
            if (cnt == 2) break;
        }
        cout << endl;
    }
    
}


