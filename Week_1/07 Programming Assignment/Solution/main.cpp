#include <iostream>
#include <string>

//-------------------------------------------------------------------------------------------------
int main() 
{
	std::string str;
	std::cin >> str;

	size_t count = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == 'f')
		{
			count++;
			if (count == 2)
			{
				std::cout << i;
				break;
			}
		}
	}

	if (count == 1)
	{
		std::cout << -1;
	}
	else
	if (count == 0)
	{
		std::cout << -2;
	}

	return 0;
}
//-------------------------------------------------------------------------------------------------