#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 5e5 + 5;
int arr[MAX], ldp[MAX], rdp[MAX], ans[MAX];

signed main(){

    //ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) cin >> arr[i];

    stack<int> stk;
    for(int i = 1; i <= n; ++i){
        while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        if (!stk.empty()){
            int last = stk.top();
            ldp[i] = arr[i]*(i-last) + ldp[last];
        }else ldp[i] = arr[i]*i;
        stk.push(i);
    }

    stk = stack<int>();

    for(int i = n; i >= 1; --i){
        while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
        if (!stk.empty()){
            int last = stk.top();
            rdp[i] = arr[i]*(last-i) + rdp[last];
        }else rdp[i] = arr[i]*(n-i+1);
        stk.push(i);
    }

    int id = 0;
    auto cnt = [&](int idx){return ldp[idx]+rdp[idx]-arr[idx];};

    for(int i = 1; i <= n; ++i)
        if (!id || (cnt(id) < cnt(i))) id = i;

    int tmp = id;

    int now = arr[id];
    while(id >= 1){
        if (arr[id] < now) now = arr[id];
        ans[id--] = now;
    }

    id = tmp;
    now = arr[id];
    while(id <= n){
        if (arr[id] < now) now = arr[id];
        ans[id++] = now;
    }

    for(int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];




    return 0;
}
