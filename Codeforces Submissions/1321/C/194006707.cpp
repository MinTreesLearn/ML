// konakarthik12
// cpp20
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int INF = (int)1e9;
using ll = long long;
using pii = pair<int, int>;
using pdd = pair<double, double>;
template <class T>
using pqueue = priority_queue<T>;
#define all(x) begin(x), end(x)
#define filla(x, v) memset(x, v, sizeof x);
template <class... Args>
void read(Args&... args) {
	(..., (cin >> args));
}
template <typename T>
void readN(int n, T c) {
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
}

template <class... Args>
void print(Args... args) {
	string delim = "";
	(..., (cout << delim << args, delim = " "));
}

template <class... Args>
void println(Args... args) {
	print(args...);
	cout << "\n";
}
template <class T>
#define f first
#define s second

const auto rng = std::default_random_engine{};

template <int MOD = MOD>
struct Modular {
	int value;
	static const int MOD_value = MOD;

	Modular(long long v = 0) {
		value = v % MOD;
		if (value < 0) {
			value += MOD;
		}
	}
	Modular(long long a, long long b)
		: value(0) {
		*this += a;
		*this /= b;
	}

	Modular& operator+=(Modular const& b) {
		value += b.value;
		if (value >= MOD) {
			value -= MOD;
		}
		return *this;
	}
	Modular& operator-=(Modular const& b) {
		value -= b.value;
		if (value < 0) {
			value += MOD;
		}
		return *this;
	}
	Modular& operator*=(Modular const& b) {
		value = (long long)value * b.value % MOD;
		return *this;
	}

	friend Modular mexp(Modular a, long long e) {
		Modular res = 1;
		while (e) {
			if (e & 1) {
				res *= a;
			}
			a *= a;
			e >>= 1;
		}
		return res;
	}
	friend Modular inverse(Modular a) {
		return mexp(a, MOD - 2);
	}

	Modular& operator/=(Modular const& b) {
		return *this *= inverse(b);
	}
	friend Modular operator+(Modular a, Modular const b) {
		return a += b;
	}
	friend Modular operator-(Modular a, Modular const b) {
		return a -= b;
	}
	friend Modular operator-(Modular const a) {
		return 0 - a;
	}
	friend Modular operator*(Modular a, Modular const b) {
		return a *= b;
	}
	friend Modular operator/(Modular a, Modular const b) {
		return a /= b;
	}
	friend std::ostream& operator<<(std::ostream& os, Modular const& a) {
		return os << a.value;
	}

	friend bool operator==(Modular const& a, Modular const& b) {
		return a.value == b.value;
	}
	friend bool operator!=(Modular const& a, Modular const& b) {
		return a.value != b.value;
	}
};
template <typename T>
int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
#ifndef ONLINE_JUDGE
#define deb(...) logger(__LINE__, #__VA_ARGS__, __VA_ARGS__)

template <typename T>
struct iterable {
	enum { value = false };
};
template <typename T>
struct iterable<vector<T>> {
	enum { value = true };
};

template <typename T, typename = typename enable_if<iterable<T>::value>::type>
ostream& operator<<(ostream& out, T const& c) {
	out << '[';
	bool first = true;
	for (auto& elem : c) {
		if (!first) {
			out << ", ";
		}
		out << elem;
		first = false;
	}
	out << ']';
	return out;
};
template <typename T, typename V>
ostream& operator<<(ostream& out, pair<T, V> const& p) {
	out << '(' << p.first << ", " << p.second << ')';
	return out;
}
double to_rad(double degrees) {
	return degrees * (M_PI / 180);
}

template <typename... Args>
void logger(int line, string vars, Args&&... values) {
	cerr << "\e[30;1m" << line << ": ";
	cerr << vars << " = ";
	string delim = "";
	(..., (cerr << delim << values, delim = ", "));
	cerr << "\e[0m\n";
}
#else
#define deb(...) 0
#endif
void solve();

int main() {
	cin.tie(0)->sync_with_stdio(false);
	cout << fixed << setprecision(15);

	solve();
	cout.flush();
	return 0;
}


void solve() {
	int n;
	string s;
	read(n, s);
	s = '3' + s + '3';
	int ans = 0;
	for (char c = 'z'; c >= 'a'; c--) {
		int index = 1;
		while (index < (int) s.length() - 1) {
			if (s[index] == c && (s[index - 1] == c - 1 || s[index + 1] == c - 1)) {
        deb(s, index);
				s.erase(s.begin() + index);
				ans++;
        if (index > 1) index--;
			} else {
				index++;
			}
		}
	}

	print(ans);
}
