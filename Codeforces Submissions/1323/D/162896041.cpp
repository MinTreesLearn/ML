#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int maxn = 1e7 + 5;
int n, a[maxn], ans, b[maxn];
void input() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
}
void work(int k) {
    int num = 1 << (k + 1), up = (1 << (k + 1)) - 1, down[2] = {1 << k, (1 << k) + (1 << (k + 1))};
    LL cnt = 0;
    for(int i = 0;i < n;i++) b[i] = a[i] % num;
    sort(b, b + n);
    for(int i = 0;i < n;i++) {
        cnt += upper_bound(b + i + 1, b + n, up - b[i]) - lower_bound(b + i + 1, b + n, down[0] - b[i]);
        cnt += (b + n) - lower_bound(b + i + 1, b + n, down[1] - b[i]);
    }
    if(cnt & 1) ans ^= (1 << k);
}
void solve() {
    for(int i = 0;i < 26;i++) work(i);
    printf("%d\n", ans);
}
int main() {
    input(), solve();
    return 0;
}
  	  	  		 	   	  	  			  		