#include <iostream>
#include <string>
#include <set>
#include <map>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t q = 0;
	std::cin >> q;

	std::map<std::string, std::set<std::string>> words;

	for (size_t i = 0; i < q; i++)
	{
		std::string operation;
		std::cin >> operation;

		if (operation == "ADD")
		{
			std::string word_1;
			std::cin >> word_1;

			std::string word_2;
			std::cin >> word_2;

			words[word_1].insert(word_2);
			words[word_2].insert(word_1);
		}
		else
		if (operation == "COUNT")
		{
			std::string word;
			std::cin >> word;

			std::cout << words[word].size() << std::endl;
		}
		else
		if (operation == "CHECK")
		{
			std::string word_1;
			std::cin >> word_1;

			std::string word_2;
			std::cin >> word_2;

			if (words[word_1].count(word_2) > 0)
			{
				std::cout << "YES" << std::endl;
			}
			else
			{
				std::cout << "NO" << std::endl;
			}
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------