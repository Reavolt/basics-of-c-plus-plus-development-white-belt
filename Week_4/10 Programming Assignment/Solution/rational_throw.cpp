#include <iostream>
#include <exception>
#include <sstream>
#include <map>
#include <set>
#include <vector>

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
			throw std::invalid_argument("denominator == 0");
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
		throw std::domain_error("rhs.Denominator() == 0");
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

	//---------------------------------------- Part 5 ----------------------------------------

	{
		const std::set<Rational> rs = { {1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2} };
		if (rs.size() != 3)
		{
			std::cout << "Wrong amount of items in the set" << std::endl;
			return 1;
		}

		std::vector<Rational> v;
		for (auto x : rs)
		{
			v.push_back(x);
		}
		if (v != std::vector<Rational>{ {1, 25}, { 1, 2 }, { 3, 4 }})
		{
			std::cout << "Rationals comparison works incorrectly" << std::endl;
			return 2;
		}
	}

	{
		std::map<Rational, int> count;
		++count[{1, 2}];
		++count[{1, 2}];

		++count[{2, 3}];

		if (count.size() != 2)
		{
			std::cout << "Wrong amount of items in the map" << std::endl;
			return 3;
		}
	}

	//---------------------------------------- Part 6 ----------------------------------------

	try
	{
		Rational r(1, 0);
		std::cout << "Doesn't throw in case of zero denominator" << std::endl;
		return 1;
	}
	catch (std::invalid_argument & inv_arg)
	{

	}

	try
	{
		auto x = Rational(1, 2) / Rational(0, 1);
		std::cout << "Doesn't throw in case of division by zero" << std::endl;
		return 2;
	}
	catch (std::domain_error & dom_err)
	{

	}

	std::cout << "OK" << std::endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------