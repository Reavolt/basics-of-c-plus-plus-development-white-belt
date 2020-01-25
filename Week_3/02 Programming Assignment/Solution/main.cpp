#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <cctype>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t count = 0;
	std::cin >> count;
		
	std::vector<std::string> words(count);

	for (auto & word : words)
	{
		std::cin >> word;
	}

	auto compare_char = [](const char c_lft, const char c_rgh)
	{ 
		return std::tolower(c_lft) < std::tolower(c_rgh);
	};
	
	auto compare = [compare_char](const std::string & lft, const std::string & rgh)
	{ 
		return std::lexicographical_compare(begin(lft), end(lft), begin(rgh), end(rgh), compare_char);
	};
	
	std::sort(words.begin(), words.end(), compare);
	std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
	return 0;
}
//-------------------------------------------------------------------------------------------------