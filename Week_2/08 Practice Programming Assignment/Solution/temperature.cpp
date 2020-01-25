#include <iostream>
#include <vector>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t size = 0;
	std::cin >> size;

	int sum = 0;
	std::vector<int> temperatures(size);
	for (auto & temperature : temperatures)
	{
		std::cin >> temperature;
		sum += temperature;
	}

	int avg = sum / size;
	std::vector<int> result;
	for (size_t i = 0; i < size; i++)
	{
		if (temperatures[i] > avg)
		{
			result.push_back(i);
		}
	}

	std::cout << result.size() << std::endl;

	for (const auto result_index : result)
	{
		std::cout << result_index << " ";
	}
	std::cout << std::endl;
	return 0;
}
//-------------------------------------------------------------------------------------------------