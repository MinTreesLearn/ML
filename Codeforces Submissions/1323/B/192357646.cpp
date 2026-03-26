#include<bits/stdc++.h>
using namespace std;


void count(vector<int> &src, vector<long long> &dest){
    int i = 0;
    int n = src.size();

    while (i < n){
        int j = i;
        while (j < n && src[j] == 1){
            j++;
        }

        int len_ones = (j - i);
        int cnt = 1;
        while (len_ones > 0){
            dest[len_ones] += cnt;
            len_ones--;
            cnt++;
        }

        i = j + 1;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n ;i++){
        cin >> a[i];
    }

    for (int i = 0; i < m; i++){
        cin >> b[i];
    }

    vector<long long> a_cnt(n + 1, 0);
    vector<long long> b_cnt(m + 1, 0);

    count(a, a_cnt);
    count(b, b_cnt);

    long long cnt = 0;
    for (int i = 1; i <= n; i++){
        int idx = k / i;
        int mod = k % i;
        
        if (idx <= m && mod == 0){
            cnt += (a_cnt[i] * b_cnt[idx]);
        }
    }
    cout<<cnt<<"\n";
    return 0;
}