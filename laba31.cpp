//Задана последовательность из 1000 целых чисел.
//Переставить элементы последовательности таким образом, чтобы они располагались в порядке возрастания.
#include <iostream>
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
    // Инициализируем массив случайными значениями
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // случайное значение от 0 до 999
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