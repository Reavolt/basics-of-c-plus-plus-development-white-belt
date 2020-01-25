#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iterator>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t count = 0;
	std::cin >> count;
	
	std::vector<int> arr(count);

	for (auto & number : arr)
	{
		std::cin >> number;
	}

	std::sort(arr.begin(), arr.end(), [](int lft, int rgh) { return std::abs(lft) < std::abs(rgh);});
	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

	return 0;
}
//-------------------------------------------------------------------------------------------------