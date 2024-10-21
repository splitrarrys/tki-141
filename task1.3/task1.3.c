#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/**
@brief Функция для нахождения общего паралельного сопротивления цепи
@param Параметр resistance_of_the_first_resistor сопротивление первого резистора
@param Параметр resistance_of_the_second_resistor сопротивление второго резистора
@param Параметр resistance_of_the_third_resistor сопротивление третьего резистора
@return Возвращает значение общего параллельного сопротивления цепи
*/
double func_for_finding_general_resistance_of_paralel_resistors(double resistance_of_the_first_resistor, double resistance_of_the_second_resistor, double resistance_of_the_third_resistor);

/**
@brief проверяет вводимое значение, является ли оно числом
@return Возвращает введённое значение, если оно является числом
*/
double input(void);

/**
@brief Точка входа в программу
@return Возвращает в случае успеха
*/
int main(void)
{
	printf("Print resistance of the first resistor\t");
	double resistance_of_the_first_resistor = input();
	printf("Print resistance of the second resistor\t");
	double resistance_of_the_second_resistor = input();
	printf("Print resistance of the third resistor\t");
	double resistance_of_the_third_resistor = input();
	printf("General resistance:\t%lf", func_for_finding_general_resistance_of_paralel_resistors(resistance_of_the_first_resistor, resistance_of_the_second_resistor, resistance_of_the_third_resistor));

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

double func_for_finding_general_resistance_of_paralel_resistors(double r1, double r2, double r3) {
	return 1 / ((1 / r1) + (1 / r2) + (1 / r3));
}