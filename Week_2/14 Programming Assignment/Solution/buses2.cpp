#include <iostream>
#include <map>
#include <string>
#include <vector>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t q = 0;
	std::cin >> q;

	std::map<std::vector<std::string>, size_t> buses;

	for (size_t i = 0; i < q; i++)
	{
		size_t number = 0;
		std::cin >> number;

		std::vector<std::string> stops(number);

		for (auto & stop : stops)
		{
			std::cin >> stop;
		}

		if (buses.count(stops) == 0)
		{
			const int new_number = buses.size() + 1;
			buses[stops] = new_number;

			std::cout << "New bus " << new_number << std::endl;
		}
		else
		{
			std::cout << "Already exists for " << buses[stops] << std::endl;
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------