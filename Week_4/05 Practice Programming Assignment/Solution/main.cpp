#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//----------------------------------------------------------------------------------------------------
int main() 
{
	std::ifstream input("input.txt");

	double num = 0.0;

	std::cout << std::setprecision(3) << std::fixed;

	if (input.is_open()) 
	{
		while (input >> num) 
		{
			std::cout << num << std::endl;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------