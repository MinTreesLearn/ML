#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<std::pair<i64, int>> v;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        v.emplace_back(a[i], 1);
    }
    
    auto cmp = [&](const auto &a, const auto &b) {
        return a.first * b.second >= b.first * a.second;
    };
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::queue<int> q;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            q.push(i);
        }
    }
    
    auto leader = [&](int i) {
        while (i != p[i]) i = p[i] = p[p[i]];
        return i;
    };
    
    while (!q.empty()) {
        int i = leader(q.front());
        q.pop();
        int j = i + v[i].second;
        if (j == n || !cmp(v[i], v[j])) continue;
        v[i].first += v[j].first;
        v[i].second += v[j].second;
        p[j] = i;
        if (i > 0 && cmp(v[leader(i - 1)], v[i])) {
            q.push(i - 1);
        }
        if (i + v[i].second < n && cmp(v[i], v[i + v[i].second])) {
            q.push(i);
        }
    }
    
    std::cout << std::fixed << std::setprecision(12);
    for (int i = 0; i < n; i += v[i].second) {
        for (int j = 0; j < v[i].second; j++) {
            std::cout << double(v[i].first) / v[i].second << "\n";
        }
    }
    
    return 0;
}
