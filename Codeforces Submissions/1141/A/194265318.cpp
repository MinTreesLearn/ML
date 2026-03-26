#include<iostream>
#include<iterator>
#include<ranges>

void solve_test_case();

int main()
{
	unsigned t{ 1 };
	do
		solve_test_case();
	while (--t);
}

void solve_test_case()
{
	unsigned n, m;
	
	std::cin >> n >> m;
	if (m % n)
		std::cout << "-1" << std::endl;
	else {
		m /= n;

		unsigned c{};

		while (!(m & 1))
			++c,
			m >>= 1;
		while (!(m % 3))
			++c,
			m /= 3;
		if (m == 1)
			std::cout << c << std::endl;
		else
			std::cout << "-1" << std::endl;
	}
}