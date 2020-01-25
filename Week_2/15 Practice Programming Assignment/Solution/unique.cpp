#include <iostream>
#include <set>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t n = 0;
	std::cin >> n;

	std::set<std::string> strings;

	for (size_t i = 0; i < n; i++)
	{
		std::string word;
		std::cin >> word;

		strings.insert(word);
	}
	std::cout << strings.size();

	return 0;
}
//-------------------------------------------------------------------------------------------------