//Даны два целых числа A и В(каждое в отдельной строке).
//Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае
#include <iostream>
using namespace std;
void printNumbers(int a, int b) {
    if (a == b) {
        cout << a << endl;
    }
    else if (a < b) {
        cout << a << endl;
        printNumbers(a + 1, b);
    }
    else {
        cout << a << endl;
        printNumbers(a - 1, b);
    }
}
int main() {
    int a, b;
    cout << "Enter A: ";
    cin >> a;
    cout << "Enter B: ";
    cin >> b;
    printNumbers(a, b);
    return 0;
}