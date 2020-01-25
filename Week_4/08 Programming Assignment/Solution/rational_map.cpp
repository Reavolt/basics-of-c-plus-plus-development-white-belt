#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

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
// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational & lhs, const Rational & rhs) 
{
	return (lhs - rhs).Numerator() < 0;
}
//----------------------------------------------------------------------------------------------------
int main() 
{
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

	cout << "OK" << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------