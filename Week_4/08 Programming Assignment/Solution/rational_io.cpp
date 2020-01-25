#include <iostream>
#include <sstream>

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
std::ostream & operator << ( std::ostream & os, const Rational & rat)
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
int main() 
{
	//---------------------------------------- Part 4 ----------------------------------------

	{
		std::ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4")
		{
			std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
			return 1;
		}
	}

	{
		std::istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal)
		{
			std::cout << "5/7 is incorrectly read as " << r << std::endl;
			return 2;
		}
	}

	{
		std::istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct)
		{
			std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------