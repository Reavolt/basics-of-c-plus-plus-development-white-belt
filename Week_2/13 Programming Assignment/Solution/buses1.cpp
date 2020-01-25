#include <iostream>
#include <map>
#include <string>
#include <vector>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t q = 0;
	std::cin >> q;

	std::map<std::string, std::vector<std::string>> buses_to_stops;
	std::map<std::string, std::vector<std::string>> stops_to_buses;

	for (size_t i = 0; i < q; i++)
	{
		std::string operation;
		std::cin >> operation;

		if (operation == "NEW_BUS")
		{
			std::string bus;
			std::cin >> bus;

			size_t stop_count = 0;
			std::cin >> stop_count;

			std::vector<std::string> & stops = buses_to_stops[bus];
			stops.resize(stop_count);

			for (auto & stop : stops)
			{
				std::cin >> stop;
				stops_to_buses[stop].push_back(bus);
			}
		}
		else
		if (operation == "BUSES_FOR_STOP")
		{
			std::string stop_name;
			std::cin >> stop_name;

			if (stops_to_buses.count(stop_name) == 0)
			{
				std::cout << "No stop" << std::endl;
			}
			else
			{
				for (const auto bus : stops_to_buses[stop_name])
				{
					std::cout << bus << " ";
				}
				std::cout << std::endl;
			}
		}
		else
		if (operation == "STOPS_FOR_BUS")
		{
			std::string bus_name;
			std::cin >> bus_name;

			if (buses_to_stops.count(bus_name) == 0)
			{
				std::cout << "No bus" << std::endl;
			}
			else
			{
				for (const auto & stop : buses_to_stops[bus_name])
				{
					std::cout << "Stop " << stop << ": ";

					if (stops_to_buses[stop].size() == 1)
					{
						std::cout << "no interchange" << std::endl;
					}
					else
					{
						for (const auto & other_bus : stops_to_buses[stop])
						{
							if (bus_name != other_bus)
							{
								std::cout << other_bus << " ";
							}
						}
						std::cout << std::endl;
					}
				}
			}
		}
		else
		if (operation == "ALL_BUSES")
		{
			if (buses_to_stops.empty())
			{
				std::cout << "No buses" << std::endl;
			}
			else
			{
				for (const auto & bus_item : buses_to_stops)
				{
					std::cout << "Bus " << bus_item.first << ": ";

					for (const auto & stop : bus_item.second)
					{
						std::cout << stop << " ";
					}
					std::cout << std::endl;
				}
			}
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------