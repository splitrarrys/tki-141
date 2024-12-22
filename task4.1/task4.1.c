#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <errno.h>
#include <stdbool.h>


/**
@brief Выбор пользователя
@param APPROPRIATION_1 - заполнение массива случайными числами
@param APPROPRIATION_2 - заполнение массива своими руками
*/
typedef enum {
    APPROPRIATION_1 = 1,
    APPROPRIATION_2 = 2
} appropriation;

/**
@brief ввод массива в ручную
@param arr - массив
@param size - длинна массива
@param min_limit - минимальное допустимое значение элемента массива
@param max_limit - максимальное допустимое значение элемента массива
@return возвращает массив, заполненный элементами
*/
int* manual_input_arr(int* arr, const size_t size, const int min_limit, const int max_limit);

/**
@brief ввод массива случайными числами
@param arr - массив
@param size - длинна массива
@param min_limit - минимальное допустимое значение элемента массива
@param max_limit - максимальное допустимое значение элемента массива
@return возвращает массив, заполненный элементами
*/
int* rand_input_arr(int* arr, const size_t size, const int min_limit, const int max_limit);

/**
@brief выделяет память н массив
@param size - длинна массива
@return возвращает массив
*/
int* create_arr(const size_t size);


/**
@brief проверяет выделилась ли память на массив
@param array - массив
*/
void check_arr(const int* arr);

/**
@brief проверяет корректность введенного пользователем значения
@param min_limit - минимальное значение интервала
@param max_limit - максимальное значение интервала
*/
void check_interval(const int min_limit, const int max_limit);

/**
@brief ввод значение
@param message - вводимое сообщение
@return возвращает введенное значание если оно является числом
*/
int input(const char* message);

/**
@brief ввод размера массива
@return возвращает размер массива
*/
size_t input_size(void);

/**
@brief проверяет что первый элемент отличен от нуля
@param first_element - первый элемент
*/
void check_first_element(const int first_element);

/**
@brief считает сумму не четных элементов
@param arr - массив
@param size - длинна массива
@return возыращает сумму элементов
*/
int summ_of_elements(const int* arr, const size_t size);

/**
@brief считает количество элементов кратных пяти и больше заданного числа
@param arr - массив
@param size - длинна массива
@param number - число A
@return возвращает элементов удоволетворяющих условие
*/
int value_of_elements(const int* arr, const size_t size, const int number);

/**
@brief делит все четные элементы массива на первый элемент
@param arr - массив
@param size - длинна массива
@return возвращает массив
*/
double* division_of_elemenst(int* arr, const size_t size);

/**
@brief выводит массив
@param arr - массив
@param size - длинна массива
*/
void print_arr(const double* arr, const size_t size);

/**
@brief копирует массив
@param arr - массив
@param size - длинна массива
@return возвращает копию массива
*/
int* copy_arr(const int* arr, const size_t size);


/**
@brief выделяет память для массива типа double
@param size - длина массива
@return возвращает указатель на массив типа double
*/
double* create_array_double(const size_t size);
int main(void) {
    setlocale(LC_ALL, "Russian");
    size_t size = input_size();
    puts("Введите минимальное значение массива");
    int min_limit = input("");
    puts("Введите максимальое значение массива");
    int max_limit = input("");
    puts("Введите число A");
    int number = input("");
    int* arr = create_arr(size);
    puts("Введите выбор");
    printf_s("Заполнить массив случайными числами(%d)\n", APPROPRIATION_1);
    printf_s("Заполнить массив вручную(%d)\n", APPROPRIATION_2);
    appropriation user_choice = input("");
    switch (user_choice) {
    case APPROPRIATION_1: {
        rand_input_arr(arr, size, min_limit, max_limit);
        break;
    }
    case APPROPRIATION_2: {
        manual_input_arr(arr, size, min_limit, max_limit);
        break;
    }
    default: {
        printf("ERROR");
        free(arr);
        return 1;
    }
    }
    printf_s("Ответ на первое задание:(%d)\n", summ_of_elements(arr, size));
    printf_s("Ответ на второе задание:(%d)\n", value_of_elements(arr, size, number));
    int* arr1 = copy_arr(arr, size);
    check_first_element(arr[0]);
    puts("Ответ на третье задание:");
    print_arr(division_of_elemenst(arr1, size), size);
    free(arr);
    free(arr1);
    return 0;
}

int input(const char* message) {
    if (message != NULL) {
        printf("%s", message);
    }

    int number = 0;
    if (scanf_s("%d", &number) != 1) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return number;
}

size_t input_size(void) {
    int size = input("Введите длину массива\n");
    if (size <= 0) {
        printf("input error");
        exit(EXIT_FAILURE);
    }
    return (size_t)size;
}

void check_arr(const int* arr) {
    if (arr == NULL) {
        printf("memory error");
        exit(EXIT_FAILURE);
    }
}

void check_interval(const int min_limit, const int max_limit) {
    if (min_limit > max_limit) {
        printf("interval error");
        exit(EXIT_FAILURE);
    }
}

void check_first_element(const int first_element) {
    if (first_element == 0) {
        printf("first_element error");
        exit(EXIT_FAILURE);
    }
}

int* create_arr(const size_t size) {
    int* arr = (int*)malloc(size * sizeof(int));
    check_arr(arr);
    return arr;
}

int* manual_input_arr(int* arr, const size_t size, const int min_limit, const int max_limit) {
    check_arr(arr);
    for (size_t i = 0; i < size; ++i) {
        printf("input value of array element from (%d) till (%d)\t", min_limit, max_limit);
        int element = input("");
        if (element < min_limit || element > max_limit) {
            printf("input element error");
            exit(EXIT_FAILURE);
        }
        arr[i] = element;
    }
    return arr;
}

int* rand_input_arr(int* arr, const size_t size, const int min_limit, const int max_limit) {
    unsigned int ttime = time(NULL);
    srand(ttime);

    for (size_t i = 0; i < size; ++i) {
        arr[i] = min_limit + rand() % (max_limit - min_limit + 1);
    }
    for (size_t i = 0; i < size; ++i) {
        printf("element index:%2zu  %4d\n", i, arr[i]);
    }
    return arr;
}

int summ_of_elements(const int* arr, const size_t size) {
    int summ = 0;
    for (size_t i = 1; i < size; i += 2) {
        summ += arr[i];
    }
    return summ;
}

int value_of_elements(const int* arr, const size_t size, const int number) {
    int value = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] > number && arr[i] % 5 == 0) {
            value++;
        }
    }
    return value;
}

void print_arr(const double* arr, const size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("element %zu: \t%lf\n", i, arr[i]);
    }
}


int* copy_arr(const int* arr, const size_t size) {
    int* arr1 = create_arr(size);
    for (size_t i = 0; i < size; ++i) {
        arr1[i] = arr[i];
    }
    return arr1;
}
double* division_of_elemenst(int* arr, const size_t size) {
    double* arr2 = create_array_double(size);
    for (size_t i = 0; i < size; ++i) {
        if (i % 2 == 0) {
            arr2[i] = (double)arr[i] / arr[0];
        }
        else {
            arr2[i] = (double)arr[i];
        }
    }

    return arr2;
}

double* create_array_double(const size_t size) {
    double* arr = (double*)malloc(size * sizeof(double));
    check_arr(arr);
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    return arr;
}
