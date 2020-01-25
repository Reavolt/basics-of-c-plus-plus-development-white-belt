#include <iostream>

//----------------------------------------------------------------------------------------------------
void EnsureEqual(const std::string & left, const std::string & right)
{
	if (left != right)
	{
		throw std::runtime_error(left + " != " + right);
	}
}
//----------------------------------------------------------------------------------------------------
int main()
{
	try 
	{
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	}
	catch (std::runtime_error & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------