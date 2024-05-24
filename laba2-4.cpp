//Дано натуральное число n > 1. Выведите все простые делители этого числа в порядке возрастания.
#include <iostream>
using namespace std;
bool isPrime(int x, int i = 2) {
    if (x <= 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    if (i * i > x) {
        return true;
    }
    if (x % i == 0) {
        return false;
    }
    return isPrime(x, i + 2);
}
void printDivisors(int n, int i = 2) {
    if (i * i > n) {
        return;
    }
    if (n % i == 0 && isPrime(i)) {
        cout << i << endl;
    }
    printDivisors(n, i + 1);
}
int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;
    printDivisors(n);
    return 0;
}