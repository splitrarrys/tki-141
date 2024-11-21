#include <stdio.h>
#include <math.h>

/**
@brief функция для вычисления значения а.
@param x Значение переменной x.
@param y Значение переменной y.
@param z Значение переменной z.
@return Результат вычислени а.
*/
double getA (const double x, const double y, const double z);

/**
@brief функция для вычисления значения b.
@param x Значение переменной x.
@param y Значение переменной y.
@param z Значение переменной z.
@return Результат вычислени b.
*/
double getB (const double x, const double y, const double z);

/**
@brief Точка входа в программу.
@return Возвращает в случае успеха.
*/
int main() 
{
	const double x = 1.825;
	const double y = 18.225;
	const double z = -3.298;
	printf("a = %f\nb = %f", getA(x, y, z), getB(x, y, z));

	return 0;
}
double getA(const double x, const double y, const double z)
{
	return pow(x, y / x) - pow(y / x, 1 / 3);
}
double getB(const double x, const double y, const double z)
{
	return (x - y) + ((y - z )/ (y - x)) / (3 + (pow(z, 2) / 5));
}
