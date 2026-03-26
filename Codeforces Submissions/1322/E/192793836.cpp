#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, a[N], l, r, mid, Max, ans[N];
multiset<int> le, ge;
multiset<int>::iterator it;
void ins(int x, int y){
if(x < mid) le.insert(x), le.insert(y), ge.insert(mid), mid = *le.rbegin(), le.erase(--le.end());
else ge.insert(x), ge.insert(y), le.insert(mid), mid = *ge.begin(), ge.erase(ge.begin());
}
bool del(int x){
it = le.find(x);
if(it != le.end()){
le.erase(it);
return false;
}else{
ge.erase(ge.find(x));
return true;
}
}
int main(){
scanf("%d", &n);
for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
l = r = 1;
ans[1] = a[1], mid = a[1];
for(int i = 2; i <= n; i++){
if(l == r) l = i, r = i, mid = a[i];
else{
le.insert(mid);
bool f = del(a[l++]);
if(f) ge.insert(*le.rbegin()), le.erase(--le.end());
f = del(a[l++]);
if(f) mid = *le.rbegin(), le.erase(--le.end());
else mid = *ge.begin(), ge.erase(ge.begin());
}
bool flag = (a[i] > a[i - 1]) ^ ((i - l) & 1);
while(l > 1 && r < n){
if(flag && (a[l - 1] >= mid || a[r + 1] >= mid)) break;
else if(!flag && (a[l - 1] <= mid || a[r + 1] <= mid)) break;
ins(a[--l], a[++r]);
flag ^= 1;
}
ans[i] = mid;
Max = max(Max, i - l);
}
printf("%d\n", Max);
for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
printf("\n");
return 0;
}
