#include "bits/stdc++.h"

signed main() {
  using namespace std;

  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

#ifdef DEBUG
  freopen("Input.txt", "r", stdin);
#endif

  static int n;
  std::cin >> n;

  static std::vector<std::vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  static std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  static constexpr int64_t Inf = int64_t(1) << 60;
  static constexpr int64_t MaxVal = int64_t(1) << 40;

  struct line_t {
    int64_t a, b;
    int64_t f(int64_t x) {
      return a * x + b;
    }
  };

  struct node_t {
    line_t line{0, -Inf};
    node_t *left = nullptr, *right = nullptr;
  };

  static std::vector<bool> deleted(n);
  static std::vector<int> siz(n);

  static std::vector<int64_t> pref(n);

  static int current_size, current_centroid;

  static node_t *root;

  static int64_t res = 0;

  struct function {
    static void update(node_t *&ptr, int64_t l, int64_t r, line_t line) {
      if (ptr == nullptr) {
        ptr = new node_t{line};
        return;
      }
      int64_t m = (l + r) >> 1;
      bool left = line.f(l) < ptr -> line.f(l);
      bool mid = line.f(m) < ptr -> line.f(m);
      if (!mid) {
        std::swap(ptr -> line, line);
      }
      if (l + 1 == r) {
        return;
      }
      if (left ^ mid) {
        update(ptr -> left, l, m, line);
      }
      else {
        update(ptr -> right, m, r, line);
      }
    }

    static int64_t query(node_t *ptr, int64_t l, int64_t r, int64_t x) {
      if (ptr == nullptr) {
        return -Inf;
      }
      if (l + 1 == r) {
        return ptr -> line.f(x);
      }
      int64_t m = (l + r) >> 1;
      if (x < m) {
        return std::max(ptr -> line.f(x), query(ptr -> left, l, m, x));
      }
      else {
        return std::max(ptr -> line.f(x), query(ptr -> right, m, r, x));
      }
    }

    static void clear(node_t *ptr) {
      if (ptr -> left != nullptr) {
        clear(ptr -> left);
      }
      if (ptr -> right != nullptr) {
        clear(ptr -> right);
      }
      delete(ptr);
    }

    static void prepare(int u, int p) {
      siz[u] = 1;
      for (int v : g[u]) {
        if (!deleted[v] and v != p) {
          prepare(v, u);
          siz[u] += siz[v];
        }
      }
    }

    static int find_centroid(int u, int p) {
      for (int v : g[u]) {
        if (!deleted[v] and v != p and siz[v] > current_size / 2) {
          return find_centroid(v, u);
        }
      }
      return u;
    }

    static void dfs(int u, int p, int64_t sum) {
      pref[u] += a[u];
      res = std::max(res, (sum += pref[u]));
      for (int v : g[u]) {
        if (!deleted[v] and v != p) {
          pref[v] = pref[u];
          dfs(v, u, sum);
        }
      }
    }

    static void modify(int u, int p, int64_t sum, int h) {
      update(root, 0, MaxVal, line_t{h, sum});
      for (int v : g[u]) {
        if (!deleted[v] and v != p) {
          modify(v, u, sum + pref[v] - a[current_centroid], h + 1);
        }
      }
    }

    static void set_result(int u, int p, int64_t sum, int h) {
      res = std::max(res, sum + query(root, 0, MaxVal, pref[u]));
      for (int v : g[u]) {
        if (!deleted[v] and v != p) {
          set_result(v, u, sum + int64_t(h + 2) * a[v], h + 1);
        }
      }
    }

    static void decomposite(int u) {
      prepare(u, -1), current_size = siz[u];
      current_centroid = u = find_centroid(u, -1);
      pref[u] = 0, dfs(u, -1, 0);

      root = new node_t{line_t{0, 0}};

      for (int v : g[u]) {
        if (!deleted[v]) {
          set_result(v, u, a[u] + a[v] * 2, 1);
          modify(v, u, a[v], 1);
        }
      }

      std::reverse(g[u].begin(), g[u].end());

      clear(root), root = new node_t{line_t{0, 0}};

      for (int v : g[u]) {
        if (!deleted[v]) {
          set_result(v, u, a[u] + a[v] * 2, 1);
          modify(v, u, a[v], 1);
        }
      }

      clear(root);

      deleted[u] = true;

      for (int v : g[u]) {
        if (!deleted[v]) {
          decomposite(v);
        }
      }
    }
  };

  function::decomposite(0);

  std::cout << res << "\n";

  return 0;
}