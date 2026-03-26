#define FAST_ALLOCATOR_MEMORY 3e8
#include <bits/stdc++.h>
//#include <optimization.h>
#pragma GCC optimize("O3")
#define chervyak 6
#define sasha chervyak
#define y1 jhgfds
#define prev maAslo
#define ll long long
#define int long long
#define ull uint64_t
#define ld long double
#define pb push_back
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//cout << clock()*1000/CLOCKS_PER_SEC << '\n';
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Point{
    int x, y;
    Point(int x_ = 0, int y_ = 0): x{x_}, y{y_} {}
};

bool sleva(const Point& a, const Point& b, const Point& c){
    if(a.x == c.x && a.y == c.y) return true;
    int coeff_a = b.y - a.y;
    int coeff_b = a.x - b.x;
    int coeff_c = a.y*b.x - a.x*b.y;
    return c.x * coeff_a + c.y * coeff_b + coeff_c >= 0;
}

Point p;
int vec(int x1, int y1, int x2, int y2){
    return x1 * y2 - x2 * y1;
}

bool cmp(const Point& a, const Point& b){
    int x1 = a.x - p.x, y1 = a.y - p.y;
    int x2 = b.x - p.x, y2 = b.y - p.y;

    int f1 = y1 > 0 || (y1 == 0 && x1 > 0);
    int f2 = y2 > 0 || (y2 == 0 && x2 > 0);

    if (f1 != f2){
        return f1 < f2;
    }else{
        return vec(x1, y1, x2, y2) > 0;
    }
}

vector<Point> a0;

int cnk4(int n){
    return n * (n-1) * (n-2) * (n-3) / 24;
}

int cnk3(int n){
    return n * (n-1) * (n-2) / 6;
}


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        a0.eb(x, y);
    }
    int res = 0;
    rep(_, n){
        p = a0[_];
        auto a = a0;
        a.erase(a.begin() + _);
        res += cnk4(n-1);
        sort(all(a), cmp);
        int j = 1;
        int sz = n-1;
        for(int i = 0; i < sz; i++){
            a.pb(a[i]);
            j = max(j, i+1);
            while(j < a.size() - 1){
                if(!sleva(a[i], p, a[j])) break;
                j++;
            }
            res -= cnk3(j - i - 1);
        }
    }
    cout << res << '\n';
}








