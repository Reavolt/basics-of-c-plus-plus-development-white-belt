#include <iostream>
#include <exception>

using namespace std;

class Rational 
{
	// Вставьте сюда реализацию класса Rational
};

// Вставьте сюда реализацию operator / для класса Rational

int main() 
{
	try 
	{
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument&) 
	{

	}

	try 
	{
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error&) 
	{

	}

	cout << "OK" << endl;
	return 0;
}