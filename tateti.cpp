#include <iostream>
#include <stdbool.h>
using namespace std;

void print_table(char table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "'" << table[i][j] << "'" << " ";
        }
        cout << endl; 
    }
}

bool check_win(char table[3][3], char c) {
    for (int i = 0; i < 3; i++) {
        if (table[i][0] == c && table[i][1] == c && table[i][2] == c) return true;
    }

    for (int j = 0; j < 3; j++) {
        if (table[0][j] == c && table[1][j] == c && table[2][j] == c) return true;
    }

    if (table[0][0] == c && table[1][1] == c && table[2][2] == c) return true;
    if (table[0][2] == c && table[1][1] == c && table[2][0] == c) return true;

    return false;
}

void game(char table[3][3]) {
    int i, j;
    char choice;
    int count = 0;
    
    while (count != 9) {
        print_table(table);
        cout << "Elija que va ingresar X o 0" << endl;
        cin >> choice;

        cout << "En que fila la va a ingresar? (0, 1, 2)" << endl;
        cin >> i;

        cout << "En que columna la va a ingresar? (0, 1, 2)" << endl;
        cin >> j;

        if (table[i][j] == ' ') {
            table[i][j] = choice;
            count++;
        } else cout << "La posicion ya esta ocupada" << endl;


        if (check_win(table, choice)) {
            cout << "Victoria para: " << choice << endl;
            break;
        }

        else if (count == 9) cout << "Empate";
    }
}

int main(void) {
    char table[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
        };
    game(table);
}