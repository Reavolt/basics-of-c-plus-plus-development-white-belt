#include <iostream>
#include <string>
#include <map>

//-------------------------------------------------------------------------------------------------
class Person 
{
public:
	void ChangeFirstName(int year, const std::string & first_name)
	{
		// добавить факт изменения имени на first_name в год year
		first_names[year] = first_name;
	}
	
	void ChangeLastName(int year, const std::string & last_name) 
	{
		// добавить факт изменения фамилии на last_name в год year
		last_names[year] = last_name;
	}
	
	std::string GetFullName(int year) 
	{
		// получить имя и фамилию по состоянию на конец года year
		const std::string first_name = GetFirstName(year, first_names);
		const std::string last_name = GetLastName(year, last_names);
		std::string full_name = first_name + " " + last_name;

		if (first_name.size() == 0 && last_name.size() == 0)
		{
			full_name = "Incognito";
			return full_name;
		}
		else
		if (first_name.size() == 0)
		{
			full_name = last_name + " with unknown first name";
			return full_name;
		}
		else
		if (last_name.size() == 0)
		{
			full_name = first_name + " with unknown last name";
			return full_name;
		}
		return full_name;
	}
private:
	// приватные поля
	std::string GetFirstName(int year, std::map<int, std::string> & firstname)
	{
		while (firstname.count(year) == 0 && year > 0)
		{
			--year;
		}
		std::string first = firstname[year];
		return first;
	}
	
	std::string GetLastName(int year, std::map<int, std::string> & lastname)
	{
		while (lastname.count(year) == 0 && year > 0)
		{
			--year;
		}
		std::string last = lastname[year];
		return last;
	}

	std::map<int, std::string> first_names;
	std::map<int, std::string> last_names;
};
//-------------------------------------------------------------------------------------------------
int main()
{
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) 
	{
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970})
	{
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) 
	{
		std::cout << person.GetFullName(year) << std::endl;
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------