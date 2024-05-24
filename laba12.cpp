//Написать программу,сортирующую по убыванию 
//одномерный массив случайных целых чисел, 
//находящихся в интервале{ 0,100 }
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void SelectSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}
int main() {
    const int SIZE = 10;
    int arr[SIZE];
    // Инициализируем генератор случайных чисел
    srand(static_cast<unsigned int>(time(0)));
    // Генерируем массив случайных целых чисел
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % 101; 
    }
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Сортируем массив в порядке убывания с помощью сортировки выбором
    SelectSort(arr, SIZE);
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}