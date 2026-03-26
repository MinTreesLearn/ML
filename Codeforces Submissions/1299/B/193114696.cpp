/**
 *      Author:  Richw818
 *      Created: 02.10.2023 15:06:35
**/

#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Point2D{
    using P2 = Point2D;
    T x, y;
    Point2D(T _x = 0, T _y = 0){ x = _x, y = _y; }
    bool operator<(P2 p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P2 p) const { return tie(x, y) == tie(p.x, p.y); }
    bool operator!=(P2 p) const { return !(tie(x, y) == tie(p.x, p.y)); }
    P2 operator+(P2 p) const { return P2(x + p.x, y + p.y); }
    P2 operator-(P2 p) const { return P2(x - p.x, y - p.y); }
    P2 operator*(T d) const { return P2(x * d, y * d); }
    P2 operator/(T d) const { return P2(x / d, y / d); }
    T cross(P2 p) const { return x * p.y - y * p.x; }
    T cross(P2 a, P2 b) const { return (a - *this).cross(b - *this); }
    T dot(P2 p) const { return x * p.x + y * p.y; }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt(dist2()); }
    P2 unit() const { return *this / dist(); }
    P2 perp() const { return P2(-y, x); }
    P2 normal() const { return perp().unit(); }
    P2 rotate(double a) const {
        return P2(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P2 p){
        return os << "(" << p.x << ", " << p.y << ")\n";
    }
    friend istream& operator>>(istream& is, P2& p){
        return is >> p.x >> p.y;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    using P2 = Point2D<int>;
    int n; cin >> n;
    if(n & 1){
        cout << "NO\n";
        return 0;
    }
    vector<P2> points(n); for(auto& P : points) cin >> P;
    P2 check = points[0] + points[n / 2];
    for(int i = 1; i < n / 2; i++){
        if(points[i] + points[i + n / 2] != check){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}