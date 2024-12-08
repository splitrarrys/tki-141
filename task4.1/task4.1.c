#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main() {
    int array[SIZE];
    int sum_odd_indices = 0;
    int count_greater_than_A = 0;
    int A;

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение массива случайными числами в интервале [-10; 20]
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 31 - 10; // Генерация числа от -10 до 20
    }

    // Вывод сгенерированного массива
    printf("The generated array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // 1. Найти сумму элементов, имеющих нечетные индексы
    for (int i = 1; i < SIZE; i += 2) {
        sum_odd_indices += array[i];
    }
    printf("The sum of the elements with odd indexes: %d\n", sum_odd_indices);

    // 2. Подсчитать количество элементов массива, значения которых больше заданного числа A и кратных 5
    printf("enter a: ");
    scanf_s("%d", &A);

    for (int i = 0; i < SIZE; i++) {
        if (array[i] > A && array[i] % 5 == 0) {
            count_greater_than_A++;
        }
    }
    printf("The number of elements is greater than %d and multiples 5: %d\n", A, count_greater_than_A);

    // 3. Разделить все элементы массива с четными номерами на первый элемент
    if (array[0] != 0) { // Проверка, что первый элемент не равен 0
        for (int i = 0; i < SIZE; i += 2) {
            array[i] /= array[0];
        }
        printf("An array after dividing elements with even indexes by the first element:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else {
        printf("The first element is 0, division is not possible.\n");
    }

    return 0;
}