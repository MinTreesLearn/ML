#include <bits/stdc++.h>
using namespace std;
int main() {
int t;
cin >> t;
for (int i = 0; i < t; i++) {
int n;
cin >> n;
int b[n];
for (int j = 0; j < 2; j++) {
for (int i=0; i<n; i++) cin>>b[i];
sort(b, b + n);
for (int k = 0; k < n; k++) cout<<b[k]<<" ";
printf("\n");
}
}
return 0;
}

