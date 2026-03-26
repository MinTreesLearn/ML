// LUOGU_RID: 101887953
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int T;
long long a, m;

unsigned long long phi(unsigned long long x) {
  unsigned long long res = x;
  for(unsigned long long i = 2; i * i <= x; i += 1) {
    if(x % i == 0) {
      while(x % i == 0) { x /= i; }
      res = (__int128_t)res * (i - 1) / i;
    }
  }
  if(x != 1) res = (__int128_t)res * (x - 1) / x;
  return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> a >> m;
        cout << phi(m / __gcd(a, m)) << "\n" << flush;
    }
    return 0;
}