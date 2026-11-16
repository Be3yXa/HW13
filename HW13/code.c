#define _CRT_SECURE_NO_WARNINGS
#define MAX_SIZE 100 // Максимально допустимый размер массива
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_CTYPE, "RUS");
    int arr[MAX_SIZE];
    int n;
    printf("Введите количество элементов массива (от 1 до %d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("Введите %d целых чисел (положительных или отрицательных):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min_idx = 0;
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[min_idx]) {
            min_idx = i;
        }
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    int start = (min_idx < max_idx) ? min_idx : max_idx;
    int end = (min_idx > max_idx) ? min_idx : max_idx;
    long long sum = 0;
    int count = 0;
    for (int i = start + 1; i < end; i++) {
        sum += arr[i];
        count++;
    }
    printf("\nМинимальный элемент: %d (индекс %d)\n", arr[min_idx], min_idx);
    printf("Максимальный элемент: %d (индекс %d)\n", arr[max_idx], max_idx);
    if (count > 0) {
        double average = (double)sum / count;
        printf("Количество элементов между ними: %d\n", count);
        printf("Среднее арифметическое: %.2f\n", average);
    }
    else {
        printf("Между минимальным и максимальным элементами нет других элементов.\n");
    }
    return 0;
}