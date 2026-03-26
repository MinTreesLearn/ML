// LUOGU_RID: 100810478
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
namespace IO {
const int SIZ = 1 << 14;

inline char getc() {
    static char bf[SIZ], *begin = bf, *end = bf;
    if (begin == end) begin = bf, end = bf + fread(bf, 1, SIZ, stdin);
    if (begin == end) return EOF;
    return *begin++;
}
char wbf[SIZ], *wend = wbf, *weoo = wbf + SIZ;
inline void putc(char c) {
    *wend = c, ++wend;
    if (wend == weoo) fwrite(wbf, 1, SIZ, stdout), wend = wbf;
}
inline void do_flush() { fwrite(wbf, 1, wend - wbf, stdout); }
template <typename T>
inline void uread(T &ans) {
    static char tmp;
    tmp = getc(), ans = 0;
    while (!isdigit(tmp)) tmp = getc();
    while (isdigit(tmp)) ans = (ans << 1) + (ans << 3) + (tmp ^ 48), tmp = getc();
}
template <typename T>
inline void read(T &ans) {
    static char tmp2;
    static bool flag;
    tmp2 = getc(), ans = 0, flag = 0;
    while (!isdigit(tmp2)) {
        if (tmp2 == '-') flag = 1;
        tmp2 = getc();
    }
    while (isdigit(tmp2)) ans = (ans << 1) + (ans << 3) + (tmp2 ^ 48), tmp2 = getc();
    if (flag) ans = -ans;
}
template <typename T>
inline void uwrite(T x) {
    if (x > 9) uwrite(x / 10);
    putc(x % 10 + '0');
}
template <typename T>
inline void write(T x) {
    if (x < 0)
        putc('-'), uwrite(-x);
    else
        uwrite(x);
}
inline void putstr(const char str[]) {
    for (int i = 0; str[i]; i++) putc(str[i]);
}
inline void readalpha(char &x) {
    for (x = getc(); !isalpha(x); x = getc())
        ;
}
};  // namespace IO
using IO::read, IO::write, IO::do_flush, IO::putc, IO::uread, IO::uwrite;
template <typename T>
struct Table2D {
    vector<vector<T>> vec;
    int __n, __m;
    inline void init(int n, int m) {
        vec.resize(n), __n = n, __m = m;
        for (int i = 0; i < n; i++) vec[i].resize(m);
    }

    inline void read(int n, int m) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) ::read(vec[i][j]);
    }
    inline bool inrange(int x, int y) { return x >= 1 && x <= __n && y >= 1 && y <= __m; }
    inline T &at(int x, int y) { return vec[x - 1][y - 1]; }
};
template <typename T>
inline void fill(Table2D<T> &x, int k) {
    for (int i = 0; i < x.__n; i++)
        for (int j = 0; j < x.__m; j++)
            for (int l = 1; l <= k; l++) x.vec[i][j].insert(l);
}
int n, m, k;
// x:UD y:FB z:LR
Table2D<set<int>> vecD, vecB, vecL;
Table2D<set<int, greater<int>>> vecU, vecF, vecR;
Table2D<int> colU, colD, colF, colB, colL, colR;
Table2D<vector<bool>> used;
inline void make(int &a, int b) {
    if (a == -1)
        a = b;
    else if (a != b)
        a = 0;
}
inline int getcol(int x, int y, int z) {
    int col = -1;
    if (vecD.at(y, z).size() && *vecD.at(y, z).begin() == x) make(col, colD.at(y, z));  // cout << "readcolD" << colD.at(y, z) << endl ;
    if (vecU.at(y, z).size() && *vecU.at(y, z).begin() == x) make(col, colU.at(y, z));  // cout << "readcolU" << colU.at(y, z) << endl ;
    if (vecB.at(x, z).size() && *vecB.at(x, z).begin() == y) make(col, colB.at(x, z));  // cout << "readcolB" << colB.at(x, z) << endl ;
    if (vecF.at(x, z).size() && *vecF.at(x, z).begin() == y) make(col, colF.at(x, z));  // cout << "readcolF" << colF.at(x, z) << endl ;
    if (vecL.at(x, y).size() && *vecL.at(x, y).begin() == z) make(col, colL.at(x, y));  // cout << "readcolL" << colL.at(x, y) << endl ;
    if (vecR.at(x, y).size() && *vecR.at(x, y).begin() == z) make(col, colR.at(x, y));  // cout << "readcolR" << colR.at(x, y) << endl ;
    return col;
}
inline void check(int x, int y, int z) {
    if (x < 1 || x > n || y < 1 || y > m || z < 1 || z > k || !used.at(x, y)[z]) return;
    int p = getcol(x, y, z);
    if (!p) {
        // cout << "del:" << x << ' ' << y << ' ' << z << endl;
        used.at(x, y)[z] = 0;
        vecD.at(y, z).erase(x);
        vecU.at(y, z).erase(x);
        vecB.at(x, z).erase(y);
        vecF.at(x, z).erase(y);
        vecL.at(x, y).erase(z);
        vecR.at(x, y).erase(z);
        if (vecD.at(y, z).size() && *vecD.at(y, z).rbegin() > x) check(*vecD.at(y, z).upper_bound(x), y, z);
        if (vecU.at(y, z).size() && *vecU.at(y, z).rbegin() < x) check(*vecU.at(y, z).upper_bound(x), y, z);
        if (vecB.at(x, z).size() && *vecB.at(x, z).rbegin() > y) check(x, *vecB.at(x, z).upper_bound(y), z);
        if (vecF.at(x, z).size() && *vecF.at(x, z).rbegin() < y) check(x, *vecF.at(x, z).upper_bound(y), z);
        if (vecL.at(x, y).size() && *vecL.at(x, y).rbegin() > z) check(x, y, *vecL.at(x, y).upper_bound(z));
        if (vecR.at(x, y).size() && *vecR.at(x, y).rbegin() < z) check(x, y, *vecR.at(x, y).upper_bound(z));
    }
}
template <typename T>
inline bool cc(Table2D<T> &a, Table2D<int> &b) {
    for (int i = 1; i <= a.__n; i++)
        for (int j = 1; j <= a.__m; j++)
            if (b.at(i, j) && !a.at(i, j).size()) return 0;
    return 1;
}
int main() {
    cin >> n >> m >> k;
    vecU.init(m, k), vecD.init(m, k), vecF.init(n, k), vecB.init(n, k), vecL.init(n, m), vecR.init(n, m);
    fill(vecU, n), fill(vecD, n), fill(vecF, m), fill(vecB, m), fill(vecL, k), fill(vecR, k);
    colU.init(m, k), colD.init(m, k), colF.init(n, k), colB.init(n, k), colL.init(n, m), colR.init(n, m);
    colD.read(m, k), colU.read(m, k), colB.read(n, k), colF.read(n, k), colL.read(n, m), colR.read(n, m);
    used.init(n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            used.at(i, j).resize(k + 1);
            for (int l = 1; l <= k; l++) used.at(i, j)[l] = 1;
        }
    // cout << *vecR.at(1, 1).begin() << ' '<< *vecL<< endl;
    // cout << getcol(1, 1, 2) << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int l = 1; l <= k; l++) check(i, j, l);
    if (!cc(vecU, colU)) return puts("-1"), 0;
    if (!cc(vecD, colD)) return puts("-1"), 0;
    if (!cc(vecL, colL)) return puts("-1"), 0;
    if (!cc(vecR, colR)) return puts("-1"), 0;
    if (!cc(vecB, colB)) return puts("-1"), 0;
    if (!cc(vecF, colF)) return puts("-1"), 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= k; l++) {
                int tmp;
                if (!used.at(i, j)[l])
                    printf("%d ", 0);
                else if ((tmp = getcol(i, j, l)) == -1)
                    printf("%d ", 0);
                else
                    printf("%d ", tmp);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}