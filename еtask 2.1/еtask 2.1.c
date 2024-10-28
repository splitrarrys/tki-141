#define _USE_MATH_DEFINES

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

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
double area_of_a_trapezoid(const double upper_base, const double lower_base, const double height);

/**
@brief Функция для нахождения площади круга
@param  radius Параметр радиус
@return Возвращает значение площади трапеции
*/
double area_of_circle(const double radius);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void)
{
    printf("Trapezoid:\nPrint upper base\t");
    const double upper_base = input();
    printf("Print lower base\t");
    const double lower_base = input();
    printf("Print height\t");
    const double height = input();

    printf("Circle:\nPrint radius\t");
    const double radius = input();


    printf("Area of a trapezoid:\t%lf\nArea of a circle :\t%lf", area_of_a_trapezoid(upper_base, lower_base, height),23area_of_circle(radius));
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

double area_of_a_trapezoid(const double a, const double b, const double h)
{
    return (a + b) * h / 2;
}

double area_of_circle(const double radius)
{
    return pow(radius, 2) * M_PI;
}
