//Написать программу, сортирующую список телефонов по возрастанию и использующую  
//сортировку выбором.Телефон задан в виде строки.Например, 23 - 45 - 67.
#include <iostream>
#include <string>
using namespace std;
// Функция сравнения телефонов
bool comparePhones(const string& phone1, const string& phone2) {
    // Удаляем тире из телефонов
    string phone1WithoutDashes = phone1;
    string phone2WithoutDashes = phone2;
    for (char& c : phone1WithoutDashes) {
        if (c == '-') {
            c = ' ';
        }
    }
    for (char& c : phone2WithoutDashes) {
        if (c == '-') {
            c = ' ';
        }
    }
    // Сравниваем телефоны
    return stoi(phone1WithoutDashes) < stoi(phone2WithoutDashes);
}
// Функция сортировки выбором
void selectionSort(string phones[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (comparePhones(phones[j], phones[minIndex])) {
                minIndex = j;
            }
        }
        swap(phones[i], phones[minIndex]);
    }
}
// Функция вывода списка телефонов
void printPhones(const string phones[], int n) {
    for (int i = 0; i < n; i++) {
        cout << phones[i] << endl;
    }
}
int main() {
    const int n = 5;
    string phones[n] = { "23-45-67", "12-34-56", "45-67-89", "01-23-45", "56-78-90" };
    cout << "Before sorting:" << endl;
    printPhones(phones, n);
    selectionSort(phones, n);
    cout << "After sorting:" << endl;
    printPhones(phones, n);
    return 0;
}