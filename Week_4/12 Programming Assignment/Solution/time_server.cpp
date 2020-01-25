#include <iostream>
#include <string>
#include <exception>

//----------------------------------------------------------------------------------------------------
std::string AskTimeServer()
{
	/* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
	   * нормальный возврат строкового значения
	   * выброс исключения system_error
	   * выброс другого исключения с сообщением.
	*/
	throw std::system_error(std::error_code());
	//throw std::runtime_error("fail");
	return "16:08:55";
}
//----------------------------------------------------------------------------------------------------
class TimeServer 
{
public:
	std::string GetCurrentTime()
	{
		/* Реализуйте этот метод:
			* если AskTimeServer() вернула значение, запишите его в LastFetchedTime и верните
			* если AskTimeServer() бросила исключение system_error, верните текущее значение
			поля LastFetchedTime
			* если AskTimeServer() бросила другое исключение, пробросьте его дальше.
		*/

		// поместим вызов функции AskTimeServer в try-catch блок
		try 
		{
			LastFetchedTime = AskTimeServer();
		}
		catch (const std::system_error & sys_err) 
		{  
			// ловим только system_error
			std::cout << sys_err.what();
		}
		// возвращаем значение поля — либо обновлённое, либо нет
		return LastFetchedTime;
	}
private:
	std::string LastFetchedTime = "00:00:00";
};
//----------------------------------------------------------------------------------------------------
int main()
{
	// Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
	TimeServer ts;
	try
	{
		std::cout << ts.GetCurrentTime() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception got: " << e.what() << std::endl;
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------