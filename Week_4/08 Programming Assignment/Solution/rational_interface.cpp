#include <iostream>

//----------------------------------------------------------------------------------------------------
class Rational 
{
public:
	Rational() : p(0), q(1)
	{
		// Реализуйте конструктор по умолчанию
	}

	Rational(int numerator, int denominator)
	{
		// Реализуйте конструктор
		const int gcd_result = gcd(numerator, denominator);

		p = numerator / gcd_result;
		q = denominator / gcd_result;

		if (q < 0) 
		{
			p = -p;
			q = -q;
		}
	}

	int Numerator() const 
	{
		// Реализуйте этот метод
		return p;
	}

	int Denominator() const 
	{
		// Реализуйте этот метод
		return q;
	}

	// Сокращение дроби
	int gcd(int a, int b) 
	{
		if (b == 0)
		{
			return a;
		}
		else
		{
			return gcd(b, a % b);
		}
	}
private:
	// Добавьте поля
	int p;
	int q;
};
//----------------------------------------------------------------------------------------------------
int main() 
{
	//---------------------------------------- Part 1 ----------------------------------------

	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) 
		{
			std::cout << "Rational(3, 10) != 3/10" << std::endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) 
		{
			std::cout << "Rational(8, 12) != 2/3" << std::endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) 
		{
			std::cout << "Rational(-4, 6) != -2/3" << std::endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3)
		{
			std::cout << "Rational(4, -6) != -2/3" << std::endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) 
		{
			std::cout << "Rational(0, 15) != 0/1" << std::endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) 
		{
			std::cout << "Rational() != 0/1" << std::endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------