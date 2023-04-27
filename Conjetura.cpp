#include <iostream>
using namespace std;

int main(void) {
    // declaro la variable que se usara para almacenar el numero
    int n;

    // le solicito al usuario que ingrese su numero y lo almaceno en n
    cout << "Ingrese su numero: ";
    cin >> n;

    // si ya es 1 lo imprimo
    if (n == 1) cout << n;

    // si no lo es aplico la conjetura
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else            n = (n*3) + 1;
        cout << n << " ";
    }
    cout << endl;
}