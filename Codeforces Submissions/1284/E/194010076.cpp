#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define N 2501

complex<double> points[N];

double Pi = arg(complex<double>(-1, 0));

int nC2(int n){
    return (n * (n - 1)) / 2;
}

bool cmp(pair<double, complex<double>> a, pair<double, complex<double>> b){
    return a.first < b.first;
}


int solve(int idx, int n){
    vector<pair<double, complex<double>>> Circle;
    for (int i = 0; i < n; i++){
        if (i != idx) Circle.push_back({arg(points[i] - points[idx]), points[i] - points[idx]});
    }
    sort(Circle.begin(), Circle.end(), cmp);
    int j = 0;
    int nm = Circle.size();
    int ans = 0;
    // for (auto f : Circle){
    //     cout << '(' << f.real() << ',' << f.imag() << ") ";
    // }
    // cout << endl;
    // cout << arg(Circle[0] * conj(Circle[2])) << endl;
    for (int i = 0; i < nm; i++){
        if (j == i){
            j = (j + 1) % nm;
        }
        complex<double> tmp = conj(Circle[i].second);
        while (j != i){
            if ((Circle[j].second * tmp).imag() >= 0){
                j++;
                j %= nm;
            }
            else break;
        }
        // cout << i << ' ' << j << endl;
        int len = (j >= i + 1 ? j - i - 1 : j - i - 1 + nm);
        ans += nC2(len);
    }
    // cout << ans << endl;
    ans = (nm * (nm - 1) * (nm - 2)) / 6 - ans;
    
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        points[i] = complex<double>(x, y);
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int tmp = ans;
        ans += solve(i, n);
        // cout << i << ' ' << ans - tmp << endl;
    }
    // ans += solve(0, n);
    ans *= n - 4;
    ans /= 2;
    
    cout << ans << endl;
    

}