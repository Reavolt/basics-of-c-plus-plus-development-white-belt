#include <iostream>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
int main() 
{
	int n = 0;
	std::cin >> n;

	std::vector<int> bits;

	while (n > 0)
	{
		bits.push_back(n % 2);
		n /= 2;
	}

	std::reverse(bits.begin(), bits.end());

	for (auto i : bits)
	{
		std::cout << i;
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------