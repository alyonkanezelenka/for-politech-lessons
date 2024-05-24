//Написать программу, сортирующую по возрастанию первый столбец двумерного массива целых чисел.Использовать быструю сортировку 
//Массив создать из случайных чисел, расположенных в интервале{ 5,61 }
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
void sortFirstColumn(int arr[], int rows, int cols) {
    int firstColumn[rows];
    // Создаем массив из первого столбца
    for (int i = 0; i < rows; i++) {
        firstColumn[i] = arr[i];
    }
    // Сортируем массив
    quickSort(firstColumn, 0, rows - 1);

    // Перезаписываем отсортированный массив в первый столбец
    for (int i = 0; i < rows; i++) {
        arr[i] = firstColumn[i];
    }
}
int main() {
    const int rows = 10;
    const int cols = 10;
    int arr[rows][cols];
    // Инициализируем массив случайными значениями в интервале {5, 61}
    srand(time(0)); // инициализируем генератор случайных чисел
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 57 + 5; // случайное значение от 5 до 61
        }
    }
    // Выводим исходный массив
    cout << "Исходный массив:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // Сортируем первый столбец
    sortFirstColumn(arr, rows, cols);
    // Выводим отсортированный массив
    cout << "Отсортированный массив:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}