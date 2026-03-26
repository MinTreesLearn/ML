#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
    point(long long x, long long y) : x(x), y(y) {}
    point() : x(0), y(0) {}
    void show() {
        cerr << x << "       " << y << "\n";
    }
};
long long dist(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    long long x1, y1, a, b, c, d;
    cin >> x1 >> y1 >> a >> b >> c >> d;
    long long x0, y0, n;
    cin >> x0 >> y0 >> n;
    vector<point> vec;
    vec.push_back(point(x0, y0));

    while (x1 <= (long long)2e16 && y1 <= (long long)2e16) {
        vec.push_back(point(x1, y1));
        x1 = a * x1 + c;
        y1 = b * y1 + d;
    }

    /*
    vector<long long> sum((int)vec.size());
    for (int i = 2; i < (int)vec.size(); i++) {
        sum[i] = sum[i - 1] + dist(vec[i], vec[i - 1]);
    }
    */

    /*
    for (int i = 1; i <= 10; i++) {
        cerr << vec[i].x << " " << vec[i].y << "\n";
    }
    */
    int cnt = 0;
    for (int i = 1; i < (int)vec.size(); i++) { // 先到i
        long long temp = n;
        long long td = dist(vec[0], vec[i]);
        int tc = 0;
        if (td <= temp) {
            temp -= td;
            tc++;
            int bc = tc;
            long long bt = temp;
            for (int j = i; j >= 1; j--) { // 再到j
                tc = bc;
                temp = bt;
                for (int k = i - 1; k >= j; k--) { // 途经k
                    td = dist(vec[k + 1], vec[k]);
                    if (td <= temp) {
                        tc++;
                        temp -= td;
                    }
                    else {
                        temp = -1;
                        break;
                    }
                }
                // if (i == 2 && j == 1) cerr << tc << " " << temp << "d\n";
                if (i != (int)vec.size() - 1 && temp > 0) {
                    td = dist(vec[j], vec[i + 1]);
                    if (td <= temp) {
                        tc++;
                        temp -= td;
                        int p = i + 1;
                        for ( ; p + 1 < (int)vec.size() && dist(vec[p], vec[p + 1]) <= temp; p++) {
                            temp -= dist(vec[p], vec[p + 1]);
                            tc++;
                        }
                        // if (i == 2 && j == 1) cerr << p << "y\n";
                        
                    }
                }
                // if (tc == 6) cerr << i << " " << j << "\n";
                cnt = max(tc, cnt);
            }

        }
    }

    cout << cnt << "\n";

    return 0;
}