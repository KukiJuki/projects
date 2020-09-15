#include <iostream>
#include <cmath>
#include <iomanip>
//constexpr double Pi = acos(-1.);

int main()
{

//	std::cout << "Всем привет!" << std::endl;
//	std::cout << "А сейчас мы будем находить длину окружности и"
//			"площадь круга." << std::endl;
//
//	std::cout << "Введите радиус окружности: ";
//	double radius;
//	std::cin >> radius;
//
//	double
//		length = 2 * Pi * radius,
//		area = Pi * radius * radius;
//
//	std::cout <<
//			std::fixed <<
//			"Длина окружности = " <<
//			 std::setw(9) << std::setprecision(3) << length << std::endl <<
//			"Площадь круга    = " <<
//			 std::setw(9) << std::setprecision(3) << area << std::endl;
//	return 0;
	std::cout << "Сейчас будем табулировать синус!" << std::endl;
	double start, end, step;
	std::cout << "Введите начало промежутка: ";
	std::cin >> start;
	std::cout << "Введите конец промежутка: ";
	std::cin >> end;
	std::cout << "Введите шаг: ";
	std::cin >> step;

	std::cout <<
			"     x    |  sin(x) \n"
			"--------------------\n";

	std::cout << std::fixed;

	for(double x = start; x <= end; x+=step) {// выводим числа с фиксированной точкой
		double y = sin(x);
		int w = int( 2. + (y+1.)*20. );

		std::cout <<
				std::setw(9) <<
				std::setprecision(3) <<
				x << " | " <<
				std::setw(8) <<
				std::setprecision(5) <<
				y <<
				std::setw(w) << '*' <<
				std::endl;
	}

	return 0;
}


