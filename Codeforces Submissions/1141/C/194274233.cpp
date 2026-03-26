#include<iostream>
#include<iterator>
#include<ranges>
#include<vector>
#include<algorithm>

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
	unsigned length_of_permutation;

	std::cin >> length_of_permutation;

	std::vector<int> increments_of_permutation(length_of_permutation - 1);
	int minimal_element_of_integral{ (int)length_of_permutation }; /* 1 - p0  or  1*/

	for (int previous{};

		auto & increment : increments_of_permutation) {

		std::cin >> increment;
		previous = increment += previous;
		if (previous > (int)length_of_permutation) {
			std::cout
				<< "-1"
				<< std::endl;
			return;
		}
		minimal_element_of_integral -= (increment < minimal_element_of_integral) * (minimal_element_of_integral - increment);
	}

	std::vector<bool> sorted_permutation(length_of_permutation);

	if (-minimal_element_of_integral >= (int)length_of_permutation) {

		std::cout
			<< "-1"
			<< std::endl;
	}
	else {

		if (minimal_element_of_integral == 1)

			sorted_permutation[0] = true;

		else

			sorted_permutation[-minimal_element_of_integral] = true;

		for (auto& increment : increments_of_permutation)

			if (unsigned(increment -= minimal_element_of_integral - (minimal_element_of_integral == 1)) >= length_of_permutation)

				break;

			else

				sorted_permutation[increment] = true;

		if (std::ranges::find(sorted_permutation, false) != sorted_permutation.end()) {

			std::cout
				<< "-1"
				<< std::endl;
		}
		else {

			std::cout << -minimal_element_of_integral + (minimal_element_of_integral == 1) + 1;

			for (auto increment : increments_of_permutation) {

				std::cout
					<< ' '
					<< increment + 1;
			}

			std::cout << std::endl;
		}
	}
}