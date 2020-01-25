#include <iostream>
#include <exception>

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
		if (denominator == 0)
		{
			throw std::invalid_argument("Invalid argument");
		}
		
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
// Так как дроби уже сокращены, сравниваем числители и знаменатели
bool operator == (const Rational & lhs, const Rational & rhs)
{
	return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}
//----------------------------------------------------------------------------------------------------
// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational & lhs, const Rational & rhs)
{
	return { lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator() };
}
//----------------------------------------------------------------------------------------------------
// вычитание реализуется аналогично сложению 
Rational operator - (const Rational & lhs, const Rational & rhs)
{
	return { lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
		lhs.Denominator() * rhs.Denominator() };
}
//----------------------------------------------------------------------------------------------------
// реализация умножения
Rational operator * (const Rational & lhs, const Rational & rhs)
{
	return { lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator() };
}
//----------------------------------------------------------------------------------------------------
// деление можно реализовать через перевернутую дробь
Rational operator / (const Rational & lhs, const Rational & rhs)
{
	if (rhs.Numerator() == 0)
	{
		throw std::domain_error("Division by zero");
	}
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
//----------------------------------------------------------------------------------------------------
std::ostream & operator << (std::ostream & os, const Rational & rat)
{
	return os << rat.Numerator() << '/' << rat.Denominator();
}
//----------------------------------------------------------------------------------------------------
std::istream & operator >> (std::istream & is, Rational & rat)
{
	int p = 0;
	int q = 0;

	if (is >> p && is.ignore(1) && is >> q)
	{
		rat = Rational(p, q);
	}
	return is;
}
//----------------------------------------------------------------------------------------------------
// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational & lhs, const Rational & rhs)
{
	return (lhs - rhs).Numerator() < 0;
}
//----------------------------------------------------------------------------------------------------
int main()
{
	Rational rat_1;
	Rational rat_2;
	
	char operation;

	try
	{
		std::cin >> rat_1;
		std::cin >> operation; 
		std::cin >> rat_2;

		if (operation == '+') 
		{
			std::cout << rat_1 + rat_2 << std::endl;
		}
		else 
		if (operation == '-')
		{
			std::cout << rat_1 - rat_2 << std::endl;
		}
		else 
		if (operation == '*')
		{
			std::cout << rat_1 * rat_2 << std::endl;
		}
		else 
		if (operation == '/') 
		{
			try
			{
				std::cout << rat_1 / rat_2 << std::endl;
			}
			catch (std::domain_error& dom_err) 
			{
				std::cout << dom_err.what();
			}
		}
	}
	catch (const std::invalid_argument & inv_arg)
	{
		std::cout << inv_arg.what();
	}
	return 0;
}
//----------------------------------------------------------------------------------------------------