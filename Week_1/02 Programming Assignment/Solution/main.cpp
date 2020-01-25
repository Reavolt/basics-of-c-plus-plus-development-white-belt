#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
int main() 
{
	std::string a;
	std::cin >> a;

	std::string b;
	std::cin >> b;

	std::string c;
	std::cin >> c;
	
	std::vector<std::string> temp = {a, b ,c};
	std::sort(begin(temp), end(temp));

	std::cout << temp[0];

	return 0;
}
//-------------------------------------------------------------------------------------------------