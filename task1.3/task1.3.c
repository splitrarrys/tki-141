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
double general_resistance(double first_resistance, double second_resistance, double third_resistance);

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
	double first_resistance = input();
	printf("Print resistance of the second resistor\t");
	double second_resistance = input();
	printf("Print resistance of the third resistor\t");
	double third_resistance = input();
	printf("General resistance:\t%lf", general_resistance(first_resistance, second_resistance, third_resistance));
	return 0;

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

double general_resistance(double first_resistance, double second_resistance, double third_resistance) {
	return 1 / ((1 / first_resistance) + (1 / second_resistance) + (1 / second_resistance));
}