#include <iostream>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <bit>
#include <sstream>
#include <list>
#include <stack>
#include <queue>
#include <cmath>

typedef long long integerType;
typedef integerType z;
typedef std::vector<integerType> v;
typedef std::vector<v> V;
typedef std::set<integerType> s;
typedef std::multiset<integerType> S;
typedef std::string r;
typedef std::vector<r> R;
typedef std::vector<bool> b;


struct RHEXAOCrocks {
	RHEXAOCrocks() { std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); }
	template<class T>
	operator T() const { T n; std::cin >> n; return n; }
	std::string operator()() { std::string s; std::cin >> s; return s; }
	v operator()(integerType n) { v vec(n); for (auto& n : vec) std::cin >> n; return vec; }
	R operator()(integerType n, char del) {
		R vec(n); char ch; std::cin >> ch; vec[0].push_back(ch); int c;
		for (integerType i{}; i < n;++i)
			while ((c = std::cin.get()) != del)
				vec[i].push_back(c);
		return vec;
	}
	V operator()(integerType r, integerType c) { V tab(r, v(c)); for (auto& e : tab) for (auto& n : e) std::cin >> n; return tab; }
	template<class T> RHEXAOCrocks& operator[](const T& t) { std::cout << t; return *this; }
	RHEXAOCrocks& operator[](const R& a) { for (auto& e : a) std::cout << e << '\n'; return *this; }
	template<class Ty, template<typename T, typename A = std::allocator<T>> class C> RHEXAOCrocks& operator[](const C<Ty>& c) {
		for (auto Cc{ c.begin() }; Cc != c.end(); std::cout << *Cc << " \n"[++Cc == c.end()]); return *this;
	}
	template<class Ty, template<typename T, typename A = std::allocator<T>> class C> RHEXAOCrocks& operator[](const std::vector<C<Ty>>& c) {
		for (auto& e : c) for (auto E{ e.begin() }; E != e.end(); )std::cout << *E << " \n"[++E == e.end()]; return *this;
	}
}o;

#define i(b,e, ...) for(integerType i : std::views::iota(b,e) __VA_ARGS__)
#define _i(b,e, ...) for(integerType i : std::views::iota(b,e) | std::views::reverse __VA_ARGS__)
#define j(b,e, ...) for(integerType j : std::views::iota(b,e) __VA_ARGS__)
#define _j(b,e, ...) for(integerType j : std::views::iota(b,e) | std::views::reverse __VA_ARGS__)
#define k(b,e, ...) for(integerType k : std::views::iota(b,e) __VA_ARGS__)
#define _k(b,e, ...) for(integerType k : std::views::iota(b,e) | std::views::reverse __VA_ARGS__)
#define l(b,e, ...) for(integerType l : std::views::iota(b,e) __VA_ARGS__)
#define _l(b,e, ...) for(integerType l : std::views::iota(b,e) | std::views::reverse __VA_ARGS__)

#define Aa for(auto A{ a.begin() }, a_end{ a.end() }; A != a_end; ++A)
#define Bb for(auto B{ b.begin() }, b_end{ b.end() }; B != b_end; ++B)
#define Cc for(auto C{ c.begin() }, c_end{ c.end() }; C != c_end; ++C)
#define Dd for(auto D{ d.begin() }, d_end{ d.end() }; D != d_end; ++D)

#define z(a) (integerType)((a).size())

#define ff(...) auto f = [&](__VA_ARGS__, const auto& f)
#define f(...) f(__VA_ARGS__, f)
#define gg(...) auto g = [&](__VA_ARGS__, const auto& g)
#define g(...) g(__VA_ARGS__, g)
#define hh(...) auto h = [&](__VA_ARGS__, const auto& h)
#define h(...) h(__VA_ARGS__, h)

using namespace std;
namespace ra = ranges;

inline void nwmn(integerType nw, integerType& mn) { mn -= ((nw) < mn) * (mn - (nw)); }
inline void nwmx(integerType nw, integerType& mx) { mx += ((nw) > mx) * ((nw)-mx); }
z power(z a, z b, z M) { z r{ 1 }; do { if (b & 1) (r *= a) %= M; (a *= a) %= M; } while (b >>= 1); return r; }

#define w(...) if(__VA_ARGS__)
#define _ else
#define W(...) while(__VA_ARGS__)
#define A(...) for(auto __VA_ARGS__)
#define O while(true)


void solve_test_case()
{
	z n{ o }, x{}, y{}, mn{ n + 1 }, mnI, mnP;
	map<pair<z, z>, z> mp;
	mp[{0, 0}] = -1;
	i(0, n) {
		switch ((char)o) {
		case'L':--x;break;
		case'R':++x;break;
		case'U':++y;break;
		case'D':--y;
		}
		w(auto p{ mp.find({x, y}) }; p != mp.end()) {
			z nw{ i - p->second };
			if (nw < mn) {
				mn = nw;
				mnP = p->second;
				mnI = i;
			}
		}
		mp[{x, y}] = i;
	}
	w(mn <= n)
		o[mnP + 1 + 1][' '][mnI + 1]['\n'];
	_
		o["-1\n"];
}

int main()
{
	z t{ o };
	while (t--)
		solve_test_case();
}