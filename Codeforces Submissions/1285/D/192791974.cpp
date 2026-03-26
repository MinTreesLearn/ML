#include <bits/stdc++.h>
using namespace std;

int rec(vector<int> V, int b){
if (b < 0) return 0;
vector<int> A, B;
for (int i : V) (i & (1 << b)) ? A.push_back(i) : B.push_back(i);

if (A.empty() or B.empty()) return rec(V, b - 1);
return (1 << b) + min(rec(A, b - 1), rec(B, b - 1));
}

int main(){
int n; cin >> n; vector<int> A(n);
for (int &i : A) cin >> i;
cout<<rec(A, 30)<<"\n";
}