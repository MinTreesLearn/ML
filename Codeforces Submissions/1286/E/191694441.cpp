// LUOGU_RID: 101230917
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse2,sse3,sse4,mmx,arch=cannonlake,tune=cannonlake")
#define query(pos) (a[*lower_bound(stk + 1, stk + 1 + r, (pos))])

#define endl '\n'

using std::cin;
using std::cout;
using std::lower_bound;
using std::map;
using std::string;
using std::upper_bound;

constexpr long long N = 6e5 + 514;
constexpr long long mask = (1 << 30) - 1;
long long nxt[N], anc[N];
string s;
long long a[N];    // 串和 w 数组
long long stk[N];  // 单调栈
long long r;       // 栈顶
__int128 ans, sum;
long long tmp1, tmp2;  // tmp for output
long long n;
char c;
map<long long, long long> cnt;

void output(__int128 out) {
    std::ios::sync_with_stdio(false);
    cout.tie(nullptr);
    constexpr long long P = 1e18;
    if (out < P) {
        cout << (long long)out << endl;
    } else {
        tmp1 = out / P, tmp2 = out % P;
        cout << tmp1 << std::setw(18) << std::setfill('0') << tmp2 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    s.reserve(N);
    cin >> n;
    cin >> c >> a[0];
    s += c;      // 第一次加字符不需要加密
    ans = a[0];  // 第一次加数字同理
    stk[++r] = 0;
    cout << a[0] << endl;  // 因此直接输出就行了

    for (long long i = 1, j = 0; i < n; ++i) {
        cin >> c >> a[i];
        c = (c - 'a' + ans % 26) % 26 + 'a';
        s += c;                      // 字符加密
        a[i] = a[i] ^ (ans & mask);  // 数字加密

        /* KMP */
        while (j && c != s[j]) {
            j = nxt[j];
        }
        if (s[j] == c) {
            ++j;
        }
        nxt[i + 1] = j;

        if (c == s[nxt[i]]) {
            anc[i] = anc[nxt[i]];
        } else {
            anc[i] = nxt[i];
        }

        for (long long k = i; k > 0;) {
            if (s[k] == c) {
                k = anc[k];
            } else {
                long long v = query(i - k);
                --cnt[v];
                sum -= v;
                if (cnt[v] == 0) {
                    cnt.erase(v);
                }
                k = nxt[k];
            }
        }
        if (s[0] == c) {
            ++cnt[a[i]];
            sum += a[i];
        }

        /* 单调栈 */
        while (r && a[i] <= a[stk[r]]) {
            --r;
        }
        stk[++r] = i;

        long long ncnt = 0;  // 当前长度 border 的数量（大概
        for (auto it = cnt.upper_bound(a[i]);;) {
            if (it == cnt.end()) break;
            sum -= (it->first - a[i]) * it->second;
            ncnt += it->second;
            auto j = std::next(it);
            cnt.erase(it);
            it = j;
        }
        cnt[a[i]] += ncnt;
        ans += a[stk[1]] + sum;
        output(ans);
    }

    return 0;
}