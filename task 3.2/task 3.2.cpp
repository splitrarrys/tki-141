﻿#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
* @brief вычисляет сумму первых n членов последовательности (k = 1, 2, 3 ..., n).
* @param n значение последнего члена последовательности
* @return возвращает сумму первых n членов последовательности (k = 1, 2, 3 ..., n)
*/
double func_for_summ_1(const int n);

/**
* @brief вычисляет сумму всех членов последовательности, не меньших заданного числа e
* @param e значение параметра e
* @return возвращает сумму всех членов последовательности, не меньших заданного числа e
*/
double func_for_summ_2(const double e);

/**
* @brief вычисляет рекуррентное соотношение относительно данного значения элемента последовательности
* @param k значение данного элемента последовательности
* @return возвращает полученное значение
*/
double recurrent(const int k);

/**
@brief проверяет вводимое значение, является ли оно числом и больше ли нуля
@return Возвращает введённое значение, если оно является числом и больше нуля
*/
double input(void);

/**
@brief проверяет параметр e, больше ли нуля, и вводит его
@return возвращает значение e если оно больше нуля
*/
double true_e(void);

/**
@brief проверяет параметр n, больше ли нуля, и вводит его
@return возвращает значение n если оно больше нуля
*/
int true_n(void);

/**
 * @brief Точка входа в программу.
 * @return Возвращает в случае успеха.
*/
int main(void) {

    printf("enter value n:\t");
    int n = true_n();
    printf("enter value e:\t");
    double e = true_e();

    printf("%lf\n%lf", func_for_summ_1(n), func_for_summ_2(e));

    return 0;
}

double func_for_summ_1(const int n) {
    double current = 1;
    double summ = current;

    for (int k = 0; k < n; k++) {
        current *= recurrent(k);
        summ += current;
    }
    return summ;
}

double func_for_summ_2(const double e) {

    double current = 1;
    double summ = 0;

    for (int k = 0; fabs(current) > e - DBL_EPSILON; k++) {
        summ += current;
        current *= recurrent(k);
    }
    return summ;
}

double recurrent(const int k) {
    return 1/(k+1);
}

double input(void) {
    double number = 0;
    if (scanf_s("%lf", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}

double true_e(void) {
    double e = input();
    if (e <= DBL_EPSILON) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return e;
}

int true_n(void) {
    int n = input();
    if (n < 0) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return n;
}
