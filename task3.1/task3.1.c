
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
double input(void);


/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main() {
    const double x_start = input();
    const double x_end = input();
    const double delta_x = input();

    if (x_start < x_end && x_start >= 0) {
        printf("x\t|\ty\n");
        for (double x = x_start; x < (x_end + delta_x); x += delta_x) {
            // Проверка области определения функции
            if (x >= -DBL_EPSILON) {
                const double y = x + sqrt(x) + cbrt(x) - 2.5;
                printf("%lf|%lf\n", x, y);
            }
            else {
                printf("x = %lf: function not defined\n", x);
            }
        }
    }
    else {
        return 1;
    }

    return 0;
}
double input(void)
{
    double number = 0;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}
void check_x(const double x) {
    if (x <= DBL_EPSILON) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
}