#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
double input(void);

/**
@brief Функция для нахождения площади трапеции
@param upper_base Параметр верхнее основание трапеции
@param lower_base Параметр нижнее основание трапеции
@param height Параметр высота трапеции
@return Возвращает значение площади трапеции
*/
double func_for_y(const double a, const double x);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void)
{
	const double a = input();
    const double x = input();
    printf("func for y:\t%lf",func_for_y(a,x));
    return 0;
}

double func_for_y(const double a, const double x) {
    if (x < 1.2);
        return a * pow(x, 2) + 4;
    else (x >= 1.2);
        return  (a + 4 * x) * sqrt(pow(x,2 * a));
}

double input(void)
{
    double number = 0.0;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}
