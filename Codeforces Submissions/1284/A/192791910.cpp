#include <iostream>
using namespace std;
int main(){
int n,m;
cin >> n >> m;
string a[n],b[m];
for(int i = 0; i < n; i++)
cin >> a[i];
for(int i = 0; i < m; i++)
cin >> b[i];
int q,t;
cin >> q;
while(q--){
cin >> t;
t--;
cout << a[t % n] + b[t % m] << endl;
}
}