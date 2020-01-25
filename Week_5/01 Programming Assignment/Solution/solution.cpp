#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>

//----------------------------------------------------------------------------------------------------
class Date
{
public:
	Date() : year(1900), month(01), day(01) { }

	Date(int new_year, int new_month, int new_day)
	{
		if (new_month > 12 || new_month < 1)
		{
			std::string error = "Month value is invalid: " + std::to_string(new_month);
			throw std::logic_error(error);
		}
		else
		{
			month = new_month;
		}
		
		if (new_day > 31 || new_day < 1)
		{
			std::string error = "Day value is invalid: " + std::to_string(new_day);
			throw std::logic_error(error);
		}
		else
		{
			day = new_day;
		}
		year = new_year;
	}

	int GetYear() const
	{
		return year;
	}

	int GetMonth() const
	{
		return month;
	}

	int GetDay() const
	{
		return day;
	}
private:
	int year;
	int month;
	int day;
};
//----------------------------------------------------------------------------------------------------
std::istream & operator >> (std::istream & is, Date & date)
{
	std::string str_date;
	is >> str_date;

	std::stringstream str_stream_date(str_date);

	int year = -1;
	str_stream_date >> year;

	if (str_stream_date.fail() || str_stream_date.peek() != '-')
	{
		throw std::logic_error("Wrong date format: " + str_date);
	}
	str_stream_date.ignore();

	int month = -1;
	str_stream_date >> month;

	if (str_stream_date.fail() || str_stream_date.peek() != '-' )
	{
		throw std::logic_error("Wrong date format: " + str_date);
	}
	str_stream_date.ignore();

	int day = -1;
	str_stream_date >> day;

	if (str_stream_date.fail() || !str_stream_date.eof())
	{
		throw std::logic_error("Wrong date format: " + str_date);
	}
	date = Date(year, month, day);
	return is;
}
//----------------------------------------------------------------------------------------------------
bool operator < (const Date & lhs, const Date & rhs)
{
	if (lhs.GetYear() == rhs.GetYear()) 
	{
		if (lhs.GetMonth() == rhs.GetMonth()) 
		{
			return lhs.GetDay() < rhs.GetDay();
		}
		return lhs.GetMonth() < rhs.GetMonth();
	}
	return lhs.GetYear() < rhs.GetYear();
}
//----------------------------------------------------------------------------------------------------
class Database
{
public:
	void AddEvent(const Date & date, const std::string & event)
	{
		db[date].insert(event);
	}
	
	bool DeleteEvent(const Date & date, const std::string & event)
	{
		if (db.count(date) != 0 && db[date].count(event) != 0)
		{
			db[date].erase(event);
			return true;
		}
		return false;
	}

	int DeleteDate(const Date & date)
	{
		const int count = db[date].size();
		if (count != 0)
		{
			db.erase(date);
		}
		return count;
	}

	std::set<std::string> Find(const Date & date) const
	{
		if (db.count(date) != 0)
		{
			return db.at(date);
		}
		return {};
	}

	void Print() const
	{
		for (const auto & pair : db)
		{
			for (const auto & event : pair.second)
			{
				std::cout << std::setw(4) << std::setfill('0') << pair.first.GetYear() << '-';
				std::cout << std::setw(2) << std::setfill('0') << pair.first.GetMonth() << '-';
				std::cout << std::setw(2) << std::setfill('0') << pair.first.GetDay();
				std::cout << " " << event << std::endl;
			}
		}
	}
private:
	std::map<Date, std::set<std::string>> db;
};
//----------------------------------------------------------------------------------------------------
int main()
{
	try
	{
		Database db;

		std::string command;
		while (getline(std::cin, command))
		{
			// Считайте команды с потока ввода и обработайте каждую
			std::stringstream str_stream_cmd(command);
			std::string operation;
			str_stream_cmd >> operation;

			if (operation == "Add")
			{
				Date date_str;
				str_stream_cmd >> date_str;

				std::string event_str;
				str_stream_cmd >> event_str;
				
				db.AddEvent(date_str, event_str);
			}
			else
			if (operation == "Del")
			{
				Date date_str;
				str_stream_cmd >> date_str;

				if (!str_stream_cmd.eof())
				{
					std::string event_str;
					str_stream_cmd >> event_str;
					
					if (db.DeleteEvent(date_str, event_str)) 
					{
						std::cout << "Deleted successfully" << std::endl;
					}
					else 
					{
						std::cout << "Event not found" << std::endl;
					}
				}
				else
				{
					const int count = db.DeleteDate(date_str);
					std::cout << "Deleted " << count << " events" << std::endl;
				}
			}
			else
			if (operation == "Find")
			{
				Date date_str;
				str_stream_cmd >> date_str;

				for (const auto & event : db.Find(date_str))
				{
					std::cout << event << std::endl;
				}
			}
			else
			if (operation == "Print")
			{
				db.Print();
			}
			else
			if (operation.empty())
			{

			}
			else
			{
				throw std::logic_error("Unknown command: " + operation);
			}
		}
	}
	catch (const std::exception & exc)
	{
		std::cout << exc.what();
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------