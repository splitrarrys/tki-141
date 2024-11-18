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
    for (int i = 0; i < 3; ++i) {
        double number = input();

        if (number > 0) {
            printf("%lf\n", number * number);
        }
        else if (number < 0) {
            printf("%lf\n", pow(number, 4));
        }
        else {
            printf("input error\n");
        }
    }

    return 0;
}

double input(void) {
    double number = 0;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error\n");
        exit(EXIT_FAILURE);
    }
    return number;
}
