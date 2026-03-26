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
	unsigned number_of_hours;

	std::cin >> number_of_hours;

	unsigned ones_at_beginning{};

	for (unsigned type;

		std::cin >> type, 
		type;

		++ones_at_beginning);

	unsigned 
		length_of_ones_segment{},
		answer{};

	for (number_of_hours -= ones_at_beginning;

		--number_of_hours;) {

		unsigned type;

		std::cin >> type;

		if (type)

			++length_of_ones_segment;

		else {

			answer += (length_of_ones_segment > answer) * (length_of_ones_segment - answer);
			length_of_ones_segment = 0;
		}
	}

	length_of_ones_segment += ones_at_beginning;
	std::cout
		<< (answer += (length_of_ones_segment > answer) * (length_of_ones_segment - answer))
		<< std::endl;
}