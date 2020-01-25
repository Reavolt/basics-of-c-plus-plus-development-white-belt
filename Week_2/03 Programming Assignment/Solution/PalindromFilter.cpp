//#include <iostream>
//#include <vector>
//#include <string>

//-------------------------------------------------------------------------------------------------
bool IsPalindrom(std::string str)
{
	std::string conversely(str.rbegin(), str.rend());

	if (str == conversely)
	{
		return true;
	}
	return false;
}
//-------------------------------------------------------------------------------------------------
std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength)
{
	std::vector<std::string> result;
	for (auto & str : words)
	{
		if (IsPalindrom(str) && str.size() >= minLength)
		{
			result.push_back(str);
		}
	}
	return result;
}
//-------------------------------------------------------------------------------------------------
//int main()
//{
//	std::vector<std::string> test1 = { "abacaba", "aba" };
//	std::vector<std::string> test2 = { "abacaba", "aba" };
//	std::vector<std::string> test3 = { "weew", "bro", "code" };
//
//	std::vector<std::string> result = PalindromFilter(test1, 5);
//	for (auto t : result)
//	{
//		std::cout << t << " ";
//	}
//	std::cout << std::endl;
//
//	result = PalindromFilter(test2, 2);
//	for (auto t : result)
//	{
//		std::cout << t << " ";
//	}
//	std::cout << std::endl;
//
//	result = PalindromFilter(test3, 4);
//	for (auto t : result)
//	{
//		std::cout << t << " ";
//	}
//	std::cout << std::endl;
//	return 0;
//}
//-------------------------------------------------------------------------------------------------