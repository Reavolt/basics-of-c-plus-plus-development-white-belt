#include <iostream>
#include <cmath>

//-------------------------------------------------------------------------------------------------
int main() 
{
	double a = 0;
	std::cin >> a;

	double b = 0;
	std::cin >> b;

	double c = 0;
	std::cin >> c;

	double D = pow(b, 2) - 4 * a * c;

	if (a == 0)
	{
		if (b != 0) 
		{
			std::cout << -c / b << std::endl;
		}
	}
	else
	if (D == 0)
	{
		std::cout << -b / (2 * a) << std::endl;
	}
	else
	if (D > 0)
	{
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);
		std::cout << x1 << " " << x2;
	}
	return 0;
}
//-------------------------------------------------------------------------------------------------