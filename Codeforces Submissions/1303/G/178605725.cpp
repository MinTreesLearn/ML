#include <bits/stdc++.h>
using namespace std;
// clang-format off
namespace { enum operand_type_enum : uint32_t { RAW = 0, COMPOSED = 1 << 1, REQUIRE_PARAM = 1 << 2, }; template <class T> concept has_operand_type = requires() { { T::operand_type } -> convertible_to<uint32_t>; }; template <class T> class operand_type { public: inline static constexpr uint32_t value() { if constexpr (has_operand_type<T>) return T::operand_type; else return operand_type_enum::RAW; } }; template <class T> constexpr uint32_t operand_type_v = operand_type<decay_t<T>>::value();
template <class T> concept is_raw = ((operand_type_v<T> & RAW) == RAW); template <class T> concept is_composed = ((operand_type_v<T> & COMPOSED) == COMPOSED); template <class T> concept require_param = ((operand_type_v<T> & REQUIRE_PARAM) == REQUIRE_PARAM); template <class T> concept require_no_param = !require_param<T>; template <class left_t, class right_t> class composed_operation_t { public: inline static constexpr uint32_t operand_type = COMPOSED | operand_type_v<right_t> | operand_type_v<left_t>;
left_t left; right_t right; }; template <class left_t, class right_t> requires(is_composed<left_t> && (!is_composed<right_t>)) auto operator|(left_t&& left, right_t&& right) { return left.left | (left.right | right); } template <class left_t, class right_t> requires(is_raw<left_t>&& require_param<right_t>) auto operator|(left_t&& left, right_t&& right) { return composed_operation_t<left_t, right_t>(left, right); } namespace array_binding_details { template <typename T> class array_binding_t_full { public:
inline static constexpr uint32_t operand_type = RAW; T* array; int l, r; T* begin() { return array + l; } T* end() { return array + r + 1; } void resize(const size_t sz) { r = l + sz - 1; } }; class array_binding_t_l_r { public: inline static constexpr uint32_t operand_type = RAW; template <typename T> friend array_binding_t_full<T> operator|(T* array, const array_binding_t_l_r& binding) { return array_binding_t_full<T>{array, binding.l, binding.r}; } int l, r; }; class array_binding_t_l { public:
inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l_r operator|(const int r) const { return array_binding_t_l_r{l, r}; } int l; }; class array_binding_t_empty { public: inline static constexpr uint32_t operand_type = REQUIRE_PARAM; array_binding_t_l operator|(const int l) const { return array_binding_t_l{l}; } }; static_assert(has_operand_type<array_binding_t_empty>); static_assert(require_param<array_binding_t_empty>); } enum general_operation_t { REVERSE, };
enum comparable_operation_t { SORT, UNIQUE, PREFIX_MIN, PREFIX_MAX, }; enum integer_operation_t { PREFIX_AND, PREFIX_OR, PREFIX_XOR, }; enum number_operation_t { PREFIX_SUM, PREFIX_PROD, }; enum single_input_operation_t { NEXT_INPUT, }; enum array_input_operation_t { ARRAY_INPUT, INDEX_1, }; enum array_output_operation_t { OUTPUT_1LINE, OUTPUT_1_PER_LINE, }; template <typename container_t> auto operator|(container_t&& a, const general_operation_t& op) { switch (op) {
case REVERSE: reverse(a.begin(), a.end()); break; default: assert(false); }; return a; } template <typename container_t> auto operator|(container_t&& a, const comparable_operation_t& op) { switch (op) { case SORT: { sort(a.begin(), a.end()); break; }; case UNIQUE: { sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin()); break; } case PREFIX_MIN: { auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = min(*begin, *(begin - 1)); begin++; } break; } case PREFIX_MAX: {
auto begin = a.begin(); ++begin; while (begin < a.end()) { (*begin) = max(*begin, *(begin - 1)); begin++; } break; } default: assert(false); } return a; } template <typename container_t> auto operator|(container_t&& a, const number_operation_t& op) { switch (op) { case PREFIX_SUM: { for (size_t i = 1; i < a.size(); i++) a[i] += a[i - 1]; break; } case PREFIX_PROD: { for (size_t i = 1; i < a.size(); i++) a[i] *= a[i - 1]; break; } default: assert(false); } return a; } template <typename container_t>
auto operator|(container_t&& a, const integer_operation_t& op) { switch (op) { case PREFIX_AND: { for (size_t i = 1; i < a.size(); i++) a[i] &= a[i - 1]; break; } case PREFIX_OR: { for (size_t i = 1; i < a.size(); i++) a[i] |= a[i - 1]; break; } case PREFIX_XOR: { for (size_t i = 1; i < a.size(); i++) a[i] ^= a[i - 1]; break; } default: break; } return a; } template <typename container_t> auto operator|(container_t&& a, const array_input_operation_t& op) { switch (op) { case ARRAY_INPUT: {
for (auto&& x : a) cin >> x; break; } default: assert(0); } return a; } template <typename container_t> auto operator|(container_t&& a, const array_output_operation_t& op) { switch (op) { case OUTPUT_1LINE: { for (auto&& x : a) cout << x << ' '; cout << '\n'; break; } case OUTPUT_1_PER_LINE: { for (auto&& x : a) cout << x << '\n'; cout << '\n'; break; } default: assert(0); } return a; } constexpr array_binding_details::array_binding_t_empty ARRAY; }
// clang-format on

// #define MULTI_TEST
// #define SKIP_ASSERT
#ifdef SKIP_ASSERT
#define assert(x) (x)
#endif
int n;
int a[150001];
vector<int> g[150001];
bool removed[150001];
int64_t ans = 0;

int turn;
int done[150001];
int sz[150001];
int tree_size;

void centroid_dfs(int u) {
    done[u] = turn;
    sz[u] = 1;
    for (auto&& v : g[u])
        if (!removed[v]) {
            if (done[v] == turn) continue;
            centroid_dfs(v);
            sz[u] += sz[v];
        }
}
const vector<tuple<int, int64_t, int64_t>> dummy;
vector<vector<tuple<int, int64_t, int64_t>>> update;
void dfs(int u, int64_t height = 1, int64_t weighted_sum = 0, int64_t sum = 0) {
    weighted_sum += height * a[u];
    sum += a[u];
    done[u] = turn;
    bool is_leaf = 1;
    for (auto&& v : g[u])
        if (!removed[v]) {
            if (done[v] == turn) continue;
            dfs(v, height + 1, weighted_sum, sum);
            is_leaf = 0;
        }
    if (is_leaf) {
        update.back().emplace_back(height, weighted_sum, sum);
    }
}

class line_segment_tree_t {
public:
    inline static vector<int64_t> query_point;

    line_segment_tree_t *left, *right;
    int64_t l, r, m;
    int64_t a, b;

    line_segment_tree_t(int l, int r) : l(query_point[l]), r(query_point[r]), m((l + r) / 2), a(0), b(-1e18) {
        // assert(r < query_point.size());
        // assert(l >= 0);
        if (l != r) {
            left = new line_segment_tree_t(l, m);
            right = new line_segment_tree_t(m + 1, r);
        } else {
            left = right = nullptr;
        }
        m = query_point[m];
    }

    ~line_segment_tree_t() {
        if (left) {
            delete left;
            delete right;
        }
    }

    void update(const int64_t& p, const int64_t& q) {
        // assert(l <= r);
        bool better_l = (p * l + q) >= (a * l + b);
        bool better_r = (p * r + q) >= (a * r + b);
        if (better_l && better_r) {
            a = p;
            b = q;
        } else if (better_l || better_r) {
            left->update(p, q);
            right->update(p, q);
        }
    }

    int64_t get(const int64_t& u) {
        if (l == r) {
            return a * u + b;
        }
        if (m >= u) return max(a * u + b, left->get(u));
        else return max(a * u + b, right->get(u));
    }
};

void centroid(int u) {
    turn++;
    centroid_dfs(u);
    tree_size = sz[u];
    {
    find_again:;
        for (auto&& v : g[u]) {
            if (done[v] != turn) continue;
            if ((sz[v] < sz[u]) && (sz[v] * 2 > tree_size)) {
                u = v;
                goto find_again;
            }
        }
    }
    // cerr << "found: " << u << '\n';

    turn++;
    // we need to pair [height, wsum, sum] with another [height, wsum, sum]
    // let this be [h1, w1, s1] and [h2, w2, s2]
    // then the answer if we go from leaf 1 to 2 is
    // w2 + s2 * (h1 + 1) + ((h1 + 1) * s1 - w1) + a[u] * (h1 + 1)
    // rewrite as w2 + (s2 + a[u]) * (h1 + 1) + ((h1 + 1) * s1 - w1)
    // this call for a dynamic CHT, which we will have to be able to look up with both range and slope
    // the range s2 + a[u] is too big for line segment tree, but we can store all the query first, which ultimately lead to an
    // easier implementation.
    update.clear();
    update.emplace_back(dummy);
    update.back().emplace_back(0, 0, 0);
    done[u] = turn;
    for (auto&& v : g[u]) {
        if ((!removed[v]) && (done[v] != turn)) {
            update.emplace_back(dummy);
            done[v] = turn;
            dfs(v);
        }
    }
    for (int direction = 0; direction <= 1; direction++) {
        line_segment_tree_t::query_point.clear();
        for (auto&& branch : update) {
            for (auto&& [h, w, s] : branch) {
                line_segment_tree_t::query_point.emplace_back(s + a[u]);
            }
        }
        line_segment_tree_t::query_point | UNIQUE;
        static line_segment_tree_t* tree = nullptr;
        if (tree) delete tree;
        tree = new line_segment_tree_t(0, line_segment_tree_t::query_point.size() - 1);
        for (auto&& branch : update) {
            for (auto&& [h, w, s] : branch) {
                // cerr << h << ' ' << w << ' ' << s << '\n';
                ans = max(ans, w + tree->get(s + a[u]));
            }
            for (auto&& [h, w, s] : branch) tree->update(h + 1, s * (h + 1) - w);
        }
        update | REVERSE;
    }

    removed[u] = 1;
    for (auto&& v : g[u])
        if (!removed[v]) centroid(v);
}

void solve() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    a | ARRAY | 1 | n | ARRAY_INPUT;
    centroid(1);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    while (t--) solve();
}