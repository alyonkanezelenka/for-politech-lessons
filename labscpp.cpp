// 1 Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}. 
// Использовать сортировку выбором. 
#include <iostream>
#include <cstdlib>
#include <functional>
#include <ctime>
using namespace std;
void SelectSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int el = i;
        for (int j = i + i; j < n; j++)
        {
            if (arr[j] < arr[el])
                el = j;
        }
        if (el != i)
            swap(arr[i], arr[el]);
    }
}
int main() {
    srand(static_cast<unsigned int>(time(0))); // инициализируем генератор
    const int n = 10;
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 102 + 2; // генерируем случайное число в интервале {2,103}
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    SelectSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
