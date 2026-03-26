#include <bits/stdc++.h>
using namespace std;

const int mx = 6e5 + 5;

int n, m, ans[mx], A[mx], prv[mx], bit[mx];

void upd(int i, int val){
for (; i <= mx; i += i & (-i)) bit[i] += val;
}
int qry(int i){
int ret = 0;
for (; i > 0; i -= i & (-i)) ret += bit[i];
return ret;
}

int main(){
cin >> n >> m;
for (int i = 1, X; i <= n + m; i++){
if (i <= n) X = n - i + 1;
else cin >> X;

upd(i, 1);
if (prv[X]){
ans[X] = max(ans[X], qry(i) - qry(prv[X]));
upd(prv[X], -1);
}
prv[X] = i;
}
for (int i = 1; i <= n; i++)
cout<<(prv[i] <= n ? i : 1)<<" "<<max(ans[i], qry(n + m) - qry(prv[i] - 1))<<"\n";
}