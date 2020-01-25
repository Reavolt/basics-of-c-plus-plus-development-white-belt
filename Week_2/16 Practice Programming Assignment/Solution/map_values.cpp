//#include <iostream>
//#include <set>
//#include <map>
//#include <string>

//-------------------------------------------------------------------------------------------------
//std::set<std::string> BuildMapValuesSet(std::map<int, std::string> & map);
//-------------------------------------------------------------------------------------------------
//int main()
//{
//	std::map<int, std::string> mp = 
//	{
//		{1, "odd"},
//		{2, "even"},
//		{3, "odd"},
//		{4, "even"},
//		{5, "odd"}
//	};
//
//	std::set<std::string> values = BuildMapValuesSet(mp);
//	
//	for (const std::string & value : values)
//	{
//		std::cout << value << std::endl;
//	}
//	return 0;
//}
//-------------------------------------------------------------------------------------------------
std::set<std::string> BuildMapValuesSet(const std::map<int, std::string> & map)
{
	std::set<std::string> values;

	for (auto & value : map)
	{
		values.insert(value.second);
	}
	return values;
}
//-------------------------------------------------------------------------------------------------