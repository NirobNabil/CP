// CPP program to illustrate
// std :: inner_product
#include <iostream> // std::cout
#include <functional> // std::minus, std::divides
#include <numeric> // std::inner_product

// Driver code
int main()
{
	// The value which is added after
	// finding inner_product b/w elements
	int init = 100;
	int series1[] = { 10, 20, 30 };
	int series2[] = { 1, 2, 3 };
	int n = sizeof(series1) / sizeof(series1[0]);

	// Elements in series1
	std::cout << "First array contains :";
	for (int i = 0; i < n; i++)
		std::cout << " " << series1[i];
	std::cout << "\n";

	// Elements in series2
	std::cout << "Second array contains :";
	for (int i = 0; i < n; i++)
		std::cout << " " << series2[i];
	std::cout << "\n\n";

	std::cout << "Using functional operations: ";
	// std :: minus returns the difference b/w
	// each elements of both array
	// std :: divides return the quotient of
	// each elements of both array after performing
	// divide operation
	// The operations is performed b/w number of same index
	// of both array
	std::cout << std::inner_product(series1, series1 + 1, series2, init,
									std::minus<int>(), std::divides<int>());
	std::cout << '\n';

	return 0;
}
