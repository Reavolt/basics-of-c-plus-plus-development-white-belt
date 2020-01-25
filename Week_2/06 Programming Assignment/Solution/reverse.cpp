//#include <iostream>
//#include <vector>

//-------------------------------------------------------------------------------------------------
//void Reverse(std::vector<int> & input);
//-------------------------------------------------------------------------------------------------
//int main()
//{
//	std::vector<int> numbers = { 1, 5, 3, 4, 2 };
//	
//	Reverse(numbers);
//
//	for(auto vec : numbers)
//	{
//		std::cout << vec << ' ';
//	}
//	std::cout << std::endl;
//  return 0; 
//}
//-------------------------------------------------------------------------------------------------
void Reverse(std::vector<int> & input)
{
	std::vector<int> temp;
	for (auto it = input.rbegin(); it != input.rend(); ++it)
	{
		temp.push_back(*it);
	}
	input = temp;
}
//-------------------------------------------------------------------------------------------------