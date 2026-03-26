#include <iostream>
using namespace std;
int main() {
int n;
string s, res = "";
cin >> n >> s;
char c = 'a', d = 'a';
for (int i = 0; i < n; i++) {
if (s[i] >= c) {
res += "0";
c = s[i];
}
else if (s[i] >= d) {
res += "1";
d = s[i];
}
else {
cout << "NO";
return 0;
}
}
cout << "YES" << endl << res;
}
