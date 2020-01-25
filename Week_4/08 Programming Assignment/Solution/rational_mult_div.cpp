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
// Так как дроби уже сокращены, сравниваем числители и знаменатели
bool operator == (const Rational & lhs,const Rational & rhs)
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
	return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
//----------------------------------------------------------------------------------------------------

int main() 
{
	//---------------------------------------- Part 3 ----------------------------------------

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal)
		{
			std::cout << "2/3 * 4/3 != 8/9" << std::endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal)
		{
			std::cout << "5/4 / 15/8 != 2/3" << std::endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------