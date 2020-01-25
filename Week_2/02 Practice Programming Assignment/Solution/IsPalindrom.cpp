//#include <iostream>
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
//int main()
//{
//	std::cout << IsPalindrom("madam") << std::endl;
//	std::cout << IsPalindrom("gentleman") << std::endl;
//	std::cout << IsPalindrom("X") << std::endl;
//	return 0;
//}
//-------------------------------------------------------------------------------------------------