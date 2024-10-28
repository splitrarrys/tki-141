#define _USE_MATH_DEFINES // for C
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
@brief функция для вычесления объёма шара
@param R значение радиуса шара
@return возвращает значение объёма шара
*/
double get_volume(const double radius);

/**
@brief функция для вычесления площади поверхноси шара
@param R значение радиуса шара
@return возвращает значение площади повехности шара
*/
double get_surface(const double R);

/**
* @brief проверяет вводимое значение (является ли числом)
* @return возвращает введённое значение если оно является числом
*/
double input(void);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void) {
    printf("Enter R:\t");
    double R = input();
    printf("Volume of a ball:%f\nLateral surface area of a ball:%f", get_volume(R), get_surface(R));
    return 0;
}

double get_volume(const double R) {
    return R * R * R * 4 / 3 * M_PI;
}

double get_surface(const double R) {
    float S = 4 * R * R * M_PI;
    return S;
}

double input(void) {
    double number = 0;
    if (scanf_s("%lf", &number) != 1) {
        printf("Input error");
        exit(EXIT_FAILURE);
    }
    return number;
}