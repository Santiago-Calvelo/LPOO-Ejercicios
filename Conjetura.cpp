#include <iostream>
using namespace std;

int main(void) {
    int n;
    cout << "Ingrese su numero: ";
    cin >> n;

    if (n == 1) cout << n;

    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else            n = (n*3) + 1;
        cout << n << " ";
    }
    cout << endl;
}