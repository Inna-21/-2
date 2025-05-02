#include <stdio.h>
#include <stdlib.h>

// Функция для подсчета суммы цифр числа
int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Функция для проверки, является ли число числом Армстронга
int is_armstrong(int num) {
    int original = num, sum = 0, digits = 0;

    // Подсчет количества цифр
    while (original > 0) {
        original /= 10;
        digits++;
    }

    original = num;

    // Подсчет суммы цифр в степени количества цифр
    while (original > 0) {
        int digit = original % 10;
        sum += pow(digit, digits);
        original /= 10;
    }

    return sum == num;
}

// Функция для обработки массива
void process_array(int **arr, int *size, int n) {
    int new_size = 0;
    
    // Временный массив для хранения новых значений
    int *temp = malloc((*size) * 2 * sizeof(int)); // Достаточно места для дублирования

    for (int i = 0; i < *size; i++) {
        if (sum_of_digits((*arr)[i]) > n) {
            temp[new_size++] = (*arr)[i]; // Добавляем число в новый массив
            if (is_armstrong((*arr)[i])) {
                temp[new_size++] = (*arr)[i]; // Дублируем число Армстронга
            }
        }
    }

    // Изменяем размер исходного массива
    *arr = realloc(temp, new_size * sizeof(int));
    *size = new_size;
}

// Функция для ввода массива
void input_array(int **arr, int *size) {
    printf("Введите количество элементов массива: ");
    scanf("%d", size);
    
    *arr = malloc(*size * sizeof(int));
    printf("Введите элементы массива:\n");
    for (int i = 0; i < *size; i++) {
        scanf("%d", &(*arr)[i]);
    }
}

// Функция для вывода массива
void output_array(int *arr, int size) {
    printf("Результат обработки массива:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0;
    int n;

    input_array(&arr, &size);
    
    printf("Введите число n: ");
    scanf("%d", &n);

    process_array(&arr, &size, n);
    output_array(arr, size);

    free(arr); // Освобождаем память
    return 0;
}
