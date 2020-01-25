#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//-------------------------------------------------------------------------------------------------
class SortedStrings 
{
public:
	void AddString(const std::string & str) 
	{
		// добавить строку str в набор
		vect.push_back(str);
	}

	std::vector<std::string> GetSortedStrings() 
	{
		// получить набор из всех добавленных строк в отсортированном порядке
		std::sort(vect.begin(), vect.end());
		return vect;
	}
private:
	// приватные поля
	std::vector<std::string> vect;
};
//-------------------------------------------------------------------------------------------------
void PrintSortedStrings(SortedStrings & strings);
//-------------------------------------------------------------------------------------------------
int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return 0;
}
//-------------------------------------------------------------------------------------------------
void PrintSortedStrings(SortedStrings& strings)
{
	for (const std::string & s : strings.GetSortedStrings())
	{
		std::cout << s << " ";
	}
	std::cout << std::endl;
}
//-------------------------------------------------------------------------------------------------