//#include <iostream>
//#include <string>
//#include <vector>

//-------------------------------------------------------------------------------------------------
//void MoveStrings(std::vector<std::string> & source, std::vector<std::string> & destination);
//-------------------------------------------------------------------------------------------------
//int main()
//{
//	std::vector<std::string> source = { "a", "b", "c" };
//	std::vector<std::string> destination = { "z" };
//
//	MoveStrings(source, destination);
//
//	for(auto vec : destination)
//	{
//		std::cout << vec << ' ';
//	}
//	std::cout << std::endl;
//
//	std::cout << source.size() << std::endl;
//	std::cout << destination.size() << std::endl;
//
//    return 0; 
//}
//-------------------------------------------------------------------------------------------------
void MoveStrings(std::vector<std::string> & source, std::vector<std::string> & destination)
{
	destination.insert(destination.end(), source.begin(), source.end());
	source.clear();
}
//-------------------------------------------------------------------------------------------------