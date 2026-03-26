#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#else
#include "headers.h"
#endif

namespace IO {
	std::ostream& fmtbase(std::ostream& out, const char* format) {
		for (; *format; format++) {
			if (*format == '{' && *(format + 1) == '}') {
				throw std::invalid_argument("Error Number of Parameters!");
			}
			
			out << *format;
		}
		
		return out;
	}
	
	template <class Fst, class... Nxt>
	std::ostream& fmtbase(std::ostream& out, const char* format, const Fst& value, const Nxt&... nxt) {
		for (; *format; format++) {
			if (*format == '{' && *(format + 1) == '}') {
				out << value;
				return fmtbase(out, format + 2, nxt...);
			} 
			
			out << *format;
		}
		
		throw std::invalid_argument("Error Number of Parameters!");
	}
	
	template <class... Ps>
	std::ostream& fmtout(const char* format, const Ps&... ps) {
		return fmtbase(std::cout, format, ps...);
	}
	
	template <class... Ps>
	std::ostream& fmterr(const char* format, const Ps&... ps) {
		return fmtbase(std::cerr, format, ps...);
	}
	
	std::istream& allin() {
		return std::cin;
	}
	
	template <class Fst, class ... Nxt>
	std::istream& allin(Fst& fst, Nxt&... nxt) {
		std::cin >> fst;
		return allin(nxt...);
	}
	
	template <class Iter>
	std::istream& rangin(Iter begin, Iter end) {
		while (begin != end) {
			std::cin >> *begin;
			begin++;
		}
		
		return std::cin;
	}
	
	namespace Fast {
		bool sync = false;
		
		char buf[1 << 23];
		char *p1 = buf, *p2 = buf;
		
		void sync_with_ios(bool s) {
			sync = s;
		}
		
		char getchar() {
			if (sync) {
				return std::cin.get();
			}
			else {
				if (p1 == p2) {
					p1 = buf;
					p2 = p1 + fread(buf, 1, 1 << 22, stdin);
				}
				
				if (p1 == p2) {
					return EOF;
				}
				else {
					char res = *p1;
					p1++;
					return res;
				}
			}
		}
		
		void read() { }
		
		template <class T, class... U>
		void read(T& x, U&... us) {
			x = 0;
			T pos = 1;
			
			char c = getchar();
			while (!isdigit(c)) {
				if (c == '-') {
					pos = -1;
				}
				
				c = getchar();
			}
			
			while (isdigit(c)) {
				x = 10 * x + c - '0';
				c = getchar();
			}
			
			x *= pos;
			read(us...);
		}
		
		template <class T>
		void write(const T& t) {
			if (t > 10) {
				write(t / 10);
			}
			
			std::cout << (int) (t % 10);
		}
	}
}

namespace Solve {
	#define int long long
	
	using namespace IO;
	
	using Long = long long;
	using Double = long double;
	
	int const Shabby = 0;
	int const INF = std::numeric_limits<int>::max();
	int const NINF = std::numeric_limits<int>::min();
	Long const LINF = std::numeric_limits<Long>::max();
	Long const LNINF = std::numeric_limits<Long>::min();
	Double const EPS = 1e-6;

	template <int M>
	struct ModInt {
		// Promise: MOD is a prime; 2 * MOD < INT_MAX
		
		static int const MOD = M;
		
		int val;
		
		ModInt() : val(0) { }
		
		ModInt(long long v) {
			if (-MOD <= v && v < 2 * MOD) {
				if (v > MOD) {
					v -= MOD;
				}
				else if (v < 0) {
					v += MOD;
				}
			}
			else {
				v %= MOD;
				if (v < 0) {
					v += MOD;
				}
			}
			
			val = v;
		}
			
		ModInt operator++(signed) {
			auto t = *this;
			operator+=(1);
			return t;
		}
		
		ModInt& operator++() {
			operator+=(1);
			return *this;
		}
		
		ModInt operator--(signed) {
			auto t = *this;
			operator-=(1);
			return t;
		}
		
		ModInt& operator--() {
			operator-=(1);
			return *this;
		}
		
		ModInt& operator+=(const ModInt& rhs) {
			val = val + rhs.val >= MOD ? val + rhs.val - MOD : val + rhs.val;
			return *this;
		}
		
		friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
			ModInt res = lhs;
			res += rhs;
			
			return res;
		}
		
		ModInt& operator-=(const ModInt& rhs) {
			val = val - rhs.val < 0 ? val - rhs.val + MOD : val - rhs.val;
			return *this;
		}
		
		friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
			ModInt res = lhs;
			res -= rhs;
			
			return res;
		}
		
		ModInt& operator*=(const ModInt& rhs) {
			val = 1ll * val * rhs.val % MOD;
			return *this;
		}
		
		friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
			ModInt res = lhs;
			res *= rhs;
			
			return res;
		}
		
		ModInt fpow(long long p) const {		
			if (p < 0) {
				return fpow(-p).inv();
			}
			else if (!p) {
				return 1;
			}
			else if (p == 1) {
				return *this;
			}
			else if (p == 2) {
				return *this * *this;
			}
			else {
				return fpow(p / 2).fpow(2) * fpow(p % 2);
			}
		}
		
		friend bool operator==(const ModInt& a, const ModInt& b) {
			return a.val == b.val;
		}
		
		friend bool operator!=(const ModInt& a, const ModInt& b) {
			return a.val != b.val;
		}
		
		friend ModInt operator-(const ModInt& a) {
			ModInt res;
			if (a.val == 0) {
				return 0;
			}
			
			res.val = MOD - a.val;
			return res;
		}
		
		ModInt inv() const {
			return fpow(MOD - 2);
		}
		
		ModInt operator/=(const ModInt& rhs) {
			// O(log MOD)
			return operator*=(rhs.inv());
		}
		
		friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
			ModInt res = lhs;
			res /= rhs;
			
			return res;
		}
		
		bool is_square() const {
			return val == 0 || fpow((MOD - 1) / 2).val == 1;
		}
		
		ModInt sqrt() const {
			static std::mt19937 mt(42334435);
			static ModInt isq;
			
			assert(is_square());
			
			struct Complex {
				ModInt a, b;
				
				Complex operator*(const Complex& rhs) const {
					return { a * rhs.a + isq * b * rhs.b, a * rhs.b + b * rhs.a };
				}
				
				Complex fpow(int n) {
					if (!n) {
						return { 1, 0 };
					}
					else if (n == 1) {
						return *this;
					}
					else if (n == 2) {
						return operator*(*this);
					}
					else {
						return fpow(n / 2).fpow(2) * fpow(n % 2);
					}
				}
			};
			
			if (val == 0) {
				return 0;
			}
			
			ModInt b;
			while (true) {
				b = mt() % MOD;
				if (!(b * b - *this).is_square()) {
					break;
				}
			}
			
			isq = b * b - *this;
			
			Complex c = { b, 1 };
			auto res = c.fpow((MOD + 1) / 2).a;
			return std::min(res.val, MOD - res.val);
		}
	};
	
	template <int MOD>
	std::istream& operator>>(std::istream& in, ModInt<MOD>& mint) {
		long long v;
		in >> v;
		mint.val = v % MOD;
		
		return in;
	}
	
	template <int MOD>
	std::ostream& operator<<(std::ostream& out, const ModInt<MOD>& mint) {
		return out << mint.val;
	}
	
	template <class T, int B>
	struct FastPow {
		T baby[B + 1];
		T gaint[B + 1];
		
		FastPow(T b) {
			baby[0] = 1;
			for (int i = 1; i <= B; i++) {
				baby[i] = baby[i - 1] * b;
			}
			
			gaint[0] = 1;
			for (int i = 1; i <= B; i++) {
				gaint[i] = gaint[i - 1] * baby[B];
			}
		}
		
		T get(int n) {
			return gaint[n / B] * baby[n % B];
		}
	};
	
	int const MOD = 998244353;
	
	template <int M>
	const int ModInt<M>::MOD;
	
	using Mint = ModInt<MOD>;

	struct Point {
		int x, y;
	};

	int const N = 6;

	Point ps[N + 1];
	int n, m;
	Mint f[33][23][23][23][23][2][2];
	bool vis[33][23][23][23][23][2][2];

	Mint dfs(int i, int xn, int xp, int yn, int yp, int xc, int yc) {
		// fmterr("{} {} {} {} {} {} {}\n", i, xn, xp, yn, yp, xc, yc);
		auto& tf = f[i][xn][xp][yn][yp][xc][yc];
		if (vis[i][xn][xp][yn][yp][xc][yc]) {
			return tf;
		}

		if (i >= 31) {
			// fmterr("{} {} {} {} {} {} {} {}\n", i, xn, xp, yn, yp, xc, yc, xn == 0 && xp == 0 && yn == 0 && yp == 0 && xc == 0 && yc == 0);
			return xn == 0 && xp == 0 && yn == 0 && yp == 0 && xc == 0 && yc == 0;
		}

		vis[i][xn][xp][yn][yp][xc][yc] = 1;

		for (int s = 0; s < (1 << n); s++) {
			int txn = xn;
			int txp = xp;
			int tyn = yn;
			int typ = yp;
			int txc = xc;
			int tyc = yc;
			int cxn = 0;
			int cxp = 0;
			int cyn = 0;
			int cyp = 0;
			for (int i = 0; i < n; i++) {
				if ((s >> i) & 1) {
					if (ps[i].x < 0) {
						txn += -ps[i].x;
					}
					else {
						txp += ps[i].x;
					}

					if (ps[i].y < 0) {
						tyn += -ps[i].y;
					}
					else {
						typ += ps[i].y;
					}
				}
			}

			cxn = txn & 1;
			txn >>= 1;
			cxp = txp & 1;
			txp >>= 1;
			cyn = tyn & 1;
			tyn >>= 1;
			cyp = typ & 1;
			typ >>= 1;
			int cm = (m >> i) & 1;

			if (cxn == cxp && cyn == cyp) {
				// fmterr("? {}\n", i);
				tf += dfs(i + 1, txn, txp, tyn, typ, (cxn > cm) || (cxn == cm && xc), (cyn > cm) || (cyn == cm && yc));
			}
		}

		// fmterr("{} {} {} {} {} {} {} {}\n", i, xn, xp, yn, yp, xc, yc, tf);
		return tf;
	}

	void main() {
		allin(n, m);
		for (int i = 0; i < n; i++) {
			allin(ps[i].x, ps[i].y);
		}

		fmtout("{}\n", dfs(0, 0, 0, 0, 0, 0, 0) - 1);
	}

	void init() {
		
	}
	
	void clear() {
		
	}
}

signed main() {
#ifndef ONLINE_JUDGE
		// freopen("d.in", "r", stdin);
//		freopen("mine.out", "w", stdout);
		// freopen("data/3594/6.in", "r", stdin);
		// freopen("d.out", "w", stdout);
#endif
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int t = 1;
//	std::cin >> t;
	
	Solve::init();
	
	for (; t; t--) {
		Solve::main();
		Solve::clear();
	}
	
	return 0;
}