#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
using LL = long long;
using point_t = long long; //全局数据类型，可修改为 long long 等

const point_t eps = 1e-8;
const long double PI = acosl(-1);

// 点与向量
template <typename T>
struct point{
    T x, y;

    bool operator==(const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
    bool operator<(const point &a) const{
        if (abs(x - a.x) <= eps)
            return y < a.y - eps;
        return x < a.x - eps;
    }
    bool operator>(const point &a) const { return !(*this < a || *this == a); }
    point operator+(const point &a) const { return {x + a.x, y + a.y}; }
    point operator-(const point &a) const { return {x - a.x, y - a.y}; }
    point operator-() const { return {-x, -y}; }
    point operator*(const T k) const { return {k * x, k * y}; }
    point operator/(const T k) const { return {x / k, y / k}; }
    T operator*(const point &a) const { return x * a.x + y * a.y; } // 点积
    T operator^(const point &a) const { return x * a.y - y * a.x; } // 叉积，注意优先级
    int toleft(const point &a) const
    {
        const auto t = (*this) ^ a;
        return (t > eps) - (t < -eps);
    }                                                             // to-left 测试
    T len2() const { return (*this) * (*this); }                  // 向量长度的平方
    T dis2(const point &a) const { return (a - (*this)).len2(); } // 两点距离的平方

    // 涉及浮点数
    long double len() const { return sqrtl(len2()); }                                                                      // 向量长度
    long double dis(const point &a) const { return sqrtl(dis2(a)); }                                                       // 两点距离
    long double ang(const point &a) const { return acosl(max(-1.0l, min(1.0l, ((*this) * a) / (len() * a.len())))); }      // 向量夹角
    point rot(const long double rad) const { return {x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad)}; }          // 逆时针旋转（给定角度）
    point rot(const long double cosr, const long double sinr) const { return {x * cosr - y * sinr, x * sinr + y * cosr}; } // 逆时针旋转（给定角度的正弦与余弦）
};

using Point = point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a, const Point &b) const
    {
        const auto quad = [](const Point &a)
        {
            if (a.y < -eps)
                return 1;
            if (a.y > eps)
                return 4;
            if (a.x < -eps)
                return 5;
            if (a.x > eps)
                return 3;
            return 2;
        };
        const int qa = quad(a), qb = quad(b);
        if (qa != qb)
            return qa < qb;
        const auto t = a ^ b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t > eps;
    }
};

const int maxn = 5005;
Point p[maxn], v[maxn];

int main(){

#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    LL C5 = 1;
    for(int i = 1; i <= 5; i++)
        C5 = C5 * (n - i + 1) / i;

    auto C3 = [](int x){
        return 1LL * x * (x - 1) * (x - 2) / 6;
    };

    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    LL cnt = 0;
    for(int i = 1; i <= n; i++){
        int tot = 0;
        for(int j = 1; j <= n; j++){
            if (i == j) continue;
            v[++tot] = p[j] - p[i];
        }
        sort(v + 1, v + tot + 1, argcmp());
        for(int j = 1; j <= tot; j++) v[j + tot] = v[j];
        for(int j = 1, k = 2; j <= tot; j++){
            while(k < j + tot && (v[j] ^ v[k]) >= 0) k++;
            int c1 = k - j - 1;
            int c2 = tot - c1 - 1;
            cnt += C3(c1) + C3(c2);
        }
    }
    cout << C5 * 5 - cnt / 2 << '\n';

}