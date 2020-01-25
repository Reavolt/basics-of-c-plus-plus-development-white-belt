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
int main() 
{
	//---------------------------------------- Part 2 ----------------------------------------

	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal)
		{
			std::cout << "4/6 != 2/3" << std::endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal)
		{
			std::cout << "2/3 + 4/3 != 2" << std::endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal)
		{
			std::cout << "5/7 - 2/9 != 31/63" << std::endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------