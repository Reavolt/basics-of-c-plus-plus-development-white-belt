#include <iostream>
#include <map>
#include <string>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t q = 0;
	std::cin >> q;

	std::map<std::string, std::string> country_to_capital;

	for (size_t i = 0; i < q; i++)
	{
		std::string operation;
		std::cin >> operation;

		if (operation == "CHANGE_CAPITAL")
		{
			std::string country;
			std::cin >> country;

			std::string new_capital;
			std::cin >> new_capital;

			if (country_to_capital.count(country) == 0)
			{
				std::cout << "Introduce new country " << country;
				std::cout << " with capital " << new_capital;
				std::cout << std::endl;
			}
			else
			{
				const std::string & old_capital = country_to_capital[country];

				if (old_capital == new_capital)
				{
					std::cout << "Country " << country;
					std::cout << " hasn't changed its capital";
					std::cout << std::endl;
				}
				else
				{
					std::cout << "Country " << country;
					std::cout << " has changed its capital from ";
					std::cout << old_capital << " to " << new_capital;
					std::cout << std::endl;
				}
			}
			country_to_capital[country] = new_capital;
		}
		else
		if (operation == "RENAME")
		{
			std::string old_country_name;
			std::cin >> old_country_name;

			std::string new_country_name;
			std::cin >> new_country_name;

			if (old_country_name == new_country_name ||
				country_to_capital.count(old_country_name) == 0 ||
				country_to_capital.count(new_country_name) == 1)
			{
				std::cout << "Incorrect rename, skip" << std::endl;
			}
			else
			{
				std::cout << "Country " << old_country_name << " with capital ";
				std::cout << country_to_capital[old_country_name];
				std::cout << " has been renamed to " << new_country_name;
				std::cout << std::endl;

				country_to_capital[new_country_name] = country_to_capital[old_country_name];
				country_to_capital.erase(old_country_name);
			}
		}
		else
		if (operation == "ABOUT")
		{
			std::string country;
			std::cin >> country;

			if (country_to_capital.count(country) == 0) 
			{
				std::cout << "Country " << country << " doesn't exist" << std::endl;
			}
			else 
			{
				std::cout << "Country " << country << " has capital ";
				std::cout << country_to_capital[country] << std::endl;
			}
		}
		else
		if(operation == "DUMP")
		{
			if (country_to_capital.empty())
			{
				std::cout << "There are no countries in the world" << std::endl;
			}
			else
			{
				for (auto & cntry : country_to_capital)
				{
					std::cout << cntry.first << "/" << cntry.second << " ";
				}
				std::cout << std::endl;
			}
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------