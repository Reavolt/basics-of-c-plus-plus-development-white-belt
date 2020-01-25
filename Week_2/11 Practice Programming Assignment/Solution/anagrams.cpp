#include <iostream>
#include <map>
#include <string>

//-------------------------------------------------------------------------------------------------
std::map<char, size_t> BuildCharCounters(std::string & str);
//-------------------------------------------------------------------------------------------------
int main()
{
	size_t count_word = 0;
	std::cin >> count_word;

	for (size_t i = 0; i < count_word; i++)
	{
		std::string first_word;
		std::cin >> first_word;

		std::string second_word;
		std::cin >> second_word;

		if (BuildCharCounters(first_word) == BuildCharCounters(second_word))
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------
std::map<char, size_t> BuildCharCounters(std::string & str)
{
	std::map<char, size_t> counters;

	for (auto & w : str)
	{
		++counters[w];
	}
	return counters;
}
//-------------------------------------------------------------------------------------------------