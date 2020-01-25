//#include <iostream>
//#include <vector>

//-------------------------------------------------------------------------------------------------
//std::vector<int> Reversed(const std::vector<int> & input);
//-------------------------------------------------------------------------------------------------
//int main()
//{
//	std::vector<int> numbers = { 1, 5, 3, 4, 2 };
//	std::vector<int> revers = Reversed(numbers);
//
//	for(auto vec : revers)
//	{
//		std::cout << vec << ' ';
//	}
//	std::cout << std::endl;
//  return 0; 
//}
//-------------------------------------------------------------------------------------------------
std::vector<int> Reversed(const std::vector<int> & input)
{
	std::vector<int> temp;
	for (auto it = input.rbegin(); it != input.rend(); ++it)
	{
		temp.push_back(*it);
	}
	return temp;
}
//-------------------------------------------------------------------------------------------------