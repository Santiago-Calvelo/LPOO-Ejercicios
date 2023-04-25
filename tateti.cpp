#include <iostream>

using namespace std;

void print_table(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl; 
    }
}

int main(void) {
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
        };
    int i, j;
    char choice;
    while (1) {
        print_table(table);
        cout << "Elija que va ingresar X o 0" << endl;
        cin >> choice;

        cout << "En que fila la va a ingresar? (0, 1, 2)" << endl;
        cin >> i;

        cout << "En que columna la va a ingresar? (0, 1, 2)" << endl;
        cin >> j;

        if (table[i][j] == ' ') table[i][j] = choice;
        else                    cout << "La posicion ya esta ocupada" << endl;
    }
}