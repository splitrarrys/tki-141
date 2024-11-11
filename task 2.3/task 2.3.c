#include <stdio.h>
#include <math.h>
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
    double result1 = 0, result2 = 0, result3 = 0;

    for (int i = 0; i < 3; ++i) {
        double number = input();
        if (number > 0) {
            if (i == 0) result1 = number * number;
            else if (i == 1) result2 = number * number;
            else if (i == 2) result3 = number * number;
        }
        else if (number < 0) {
            if (i == 0) result1 = pow(number, 4);
            else if (i == 1) result2 = pow(number, 4);
            else if (i == 2) result3 = pow(number, 4);
        }
        else {
            if (i == 0) result1 = 0;
            else if (i == 1) result2 = 0;
            else if (i == 2) result3 = 0;
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (i == 0) {
            if ((result1 == 0)) printf("input error");
            else printf("%lfn", result1);
        }
        else if (i == 1) {
            if ((result2 == 0)) printf("input error");
            else printf("%lfn", result2);
        }
        else if (i == 2) {
            if ((result3 == 0)) printf("input error");
            else printf("%lfn", result3);
        }
    }

    return 0;
}

double input(void) {
    double number = 0;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}