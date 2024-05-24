//Дано натуральное число N.Вычислите сумму его цифр.
//При решении этой задачи нельзя использовать строки, списки, массивы(ну и циклы, разумеется).
#include <iostream>
using namespace std;
int sumDigits(int n, int sum = 0) {
    if (n == 0) {
        return sum;
    }
    else {
        int digit = n % 10;
        return sumDigits(n / 10, sum + digit);
    }
}
int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    cout << "Sum of digits: " << sumDigits(n) << endl;
    return 0;
}