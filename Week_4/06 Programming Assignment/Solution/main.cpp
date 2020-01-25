#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

//----------------------------------------------------------------------------------------------------
int main() 
{
	std::ifstream input("input.txt");
	
	size_t row = 0;
	size_t col = 0;

	if (input.is_open())
	{
		input >> row;
		input >> col;
		input.ignore(1);

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j <= (col * 2 - 1); j++)
			{
				int number = 0;
				std::cout << std::setw(10) << std::fixed;
				if (j % 2 == 0 && j < (col * 2 - 2))
				{
					input >> number;
					std::cout << number << " ";
				} 
				else 
				if (j % 2 == 0 && j == (col *2 - 2))
				{
					input >> number;
					std::cout << number;
				} 
				else 
				{
					input.ignore(1);
				}
			}
			std::cout << std::endl;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------