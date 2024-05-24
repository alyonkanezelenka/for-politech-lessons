//Дано натуральное число n.Выведите все числа от 1 до n.
#include <iostream>
using namespace std;
void printNumbers(int n) {
    if (n > 0) {
        printNumbers(n - 1);
        cout << n << endl;
    }
}
int main() {
    int n;
    cout << "Enter a natural number:";
    cin >> n;
    printNumbers(n);
    return 0;
}