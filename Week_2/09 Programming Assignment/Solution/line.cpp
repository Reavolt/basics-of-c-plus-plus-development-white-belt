#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
int main()
{
	size_t count_oper = 0;
	std::cin >> count_oper;

	std::vector<bool> queue;
	for (size_t i = 0; i < count_oper; i++)
	{
		std::string operation;
		std::cin >> operation;

		if (operation == "COME")
		{
			size_t count = 0;
			std::cin >> count;

			queue.resize(queue.size() + count, false);
		}
		else
		if (operation == "WORRY" || operation == "QUIET")
		{
			size_t count = 0;
			std::cin >> count;
			
			queue[count] = (operation == "WORRY");
		}
		else
		if (operation == "WORRY_COUNT")
		{
			std::cout << std::count(begin(queue), end(queue), true) << std::endl;
		}
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------