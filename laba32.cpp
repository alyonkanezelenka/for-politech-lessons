//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале{ 50,100 }.
//Использовать быструю сортировку
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int main() {
    const int size = 1000;
    int arr[size];
    // Инициализируем массив случайными значениями в интервале {50, 100}
    srand(time(0)); // инициализируем генератор случайных чисел
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 51 + 50; // случайное значение от 50 до 100
    }
    // Сортируем массив
    quickSort(arr, 0, size - 1);
    // Выводим отсортированный массив
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}