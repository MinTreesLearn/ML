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
    int n; string s;
    cin >> n >> s;
    int ansL = count(s.begin(), s.end(),'L');
    int ansR = count(s.begin(), s.end(),'R');
    cout << ansL+ansR+1 << endl;
}


