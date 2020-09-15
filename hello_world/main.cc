#include <iostream>
#include <cmath>
#include <iomanip>
constexpr double Pi = acos(-1.);

int main()
{

	std::cout << "Всем привет!" << std::endl;
	std::cout << "А сейчас мы будем находить длину окружности и"
			"площадь круга." << std::endl;

	std::cout << "Введите радиус окружности: ";
	double radius;
	std::cin >> radius;

	double
		length = 2 * Pi * radius,
		area = Pi * radius * radius;

	std::cout <<
			std::fixed <<
			"Длина окружности = " <<
			 std::setw(9) << std::setprecision(3) << length << std::endl <<
			"Площадь круга = " <<
			 std::setw(9) << std::setprecision(3) << area << std::endl;
	return 0;

}


