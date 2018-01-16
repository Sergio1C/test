#include <iostream>
#include <conio.h>
#include <math.h>
#include <algorithm>    // std::max
#include <cassert>
#include <limits.h>     //std::numeric_limits

double TriangleSpace(const double a, const double b, const double c)
{
	//1.1 Проверим корректность переданных параметров (строго больше 0)
	if (a <= 0 || b <= 0 || c <= 0)
		return 0;

	//1.2 Проверим, что переданные параметры состовляют стороны прямоугольника по аксиоме:
	//"Любая сторона треугольника меньше суммы двух других сторон и больше их разности"

	if ((a > (b + c) || b > (a + c) || c > (a + b)) || (a < abs(b - c) || b < abs(a - c) || c < abs(a - b)))
		return 0;
		
	//2.1.Найдем максимальный параметр из переданных, это - гипотенуза, а остальные - катеты.

	double max = std::max(std::max(a, b), c);
	double katet1 = 0;
	double katet2 = 0;

	if (b < max && c < max) //если max = a
	{
		katet1 = b;
		katet2 = c;
	}	
	if (a < max && c < max) //если max = b
	{
		katet1 = a;
		katet2 = c;
	}
	else //иначе max = c
	{
		katet1 = a;
		katet2 = b;
	}

	//Проверка на ограниченние типа double (infinity) при дальнейших вычислениях
	if (katet1*katet1 == std::numeric_limits<double>::infinity() || katet2*katet2 == std::numeric_limits<double>::infinity())
		return 0;

	//2.2 Теорема Пифагора. В прямоугольном треугольнике квадрат гипотенузы равен сумме квадратов катетов:

	if (max*max == katet1*katet1 + katet2*katet2)
	{ 
		//треугольник прямоугольный, считаем площадь и возвращаем в результат
		return (katet1 * katet2) / 2;
	}

	return 0;
}

int main()
{
	assert(TriangleSpace(3, 4, 5) == 6); //прямоугольный треугольник
	assert(TriangleSpace(3, 4, 6) == 0);  //простой треугольник ( ноль, потому что он не прямоугольный)
	assert(TriangleSpace(-3, 4, 8) == 0); //не треугольник
	assert(TriangleSpace(std::numeric_limits<double>::max(), std::numeric_limits<double>::max() / 1.2, std::numeric_limits<double>::max() / 1.5) == 0); //очень большой треугольник
	
	std::cout << "all test is completed!" << std::endl;

	_getch();
	return 0;
}
