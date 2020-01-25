#include <iostream>
#include <string>
#include <vector>

//----------------------------------------------------------------------------------------------------
struct student
{
	std::string firstname;
	std::string lastname;

	int day;
	int month;
	int year_of_birth;

	student(const std::string & f_name, const std::string & l_name, 
			const int new_day, const int new_month, const int new_year) :
		firstname(f_name), lastname(l_name), 
		day(new_day), month(new_month), year_of_birth(new_year) {}
};
//----------------------------------------------------------------------------------------------------
int main() 
{
	size_t size_add = 0;
	std::cin >> size_add;

	std::vector<student> vec_stud;

	for (size_t i = 0; i < size_add; i++)
	{
		std::string f_name;
		std::cin >> f_name;

		std::string l_name;
		std::cin >> l_name;

		int day = 0;
		std::cin >> day;

		int month = 0;
		std::cin >> month;

		int year_of_birth = 0;
		std::cin >> year_of_birth;

		vec_stud.push_back({ f_name, l_name, day, month, year_of_birth });
	}

	size_t size_get = 0;
	std::cin >> size_get;

	for (size_t i = 0; i < size_get; i++)
	{
		std::string query;
		std::cin >> query;
		
		size_t student_number = 0;
		std::cin >> student_number;
		--student_number;

		if (query == "name" && student_number >= 0 && student_number < vec_stud.size())
		{
			std::cout << vec_stud[student_number].firstname << " ";
			std::cout << vec_stud[student_number].lastname << std::endl;
		}
		else
		if (query == "date" && student_number >= 0 && student_number < vec_stud.size())
		{
			std::cout << vec_stud[student_number].day << ".";
			std::cout << vec_stud[student_number].month << ".";
			std::cout << vec_stud[student_number].year_of_birth << std::endl;
		}
		else
		{
			std::cout << "bad request" << std::endl;
		}
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------