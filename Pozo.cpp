#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void print_table(int table[10][10]) {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int check(int table[10][10], int zeros) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table[i][j] == 0) zeros++;
        }
    }
    return zeros;
}

void putzero(int table[10][10]) {
    int zeros = 0;
    table[0][0] = 2;
    while (zeros != 6) {
        table[rand() % 10][rand() % 10] = 0;
        if (table[0][0] == 0 || table[9][9]) {
            table[0][0] = 2;
            table[9][9] = 1;
        }
        zeros = check(table, zeros);
    }
}

void game(int table[10][10]) {
    int i = 0;
    int j = 0;
    int lose = 0;

    while(1) {
        int choice;
        cout << "Para donde quieres moverte? Arriba(1), Abajo(2), Derecha(3), Izquierda(4)" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                if (table[i-1][j] != 0) {
                    table[i-1][j] = 2;
                    table[i][j] = 1;
                    i -= 1;
                    print_table(table);
                }
                else lose = 1;
                break;

            case 2:
                if (table[i+1][j] != 0) {
                    table[i+1][j] = 2;
                    table[i][j] = 1;
                    i += 1;
                    print_table(table);
                }
                else lose = 1;
                break;
            case 3:
                if (table[i][j+1] != 0) {
                    table[i][j+1] = 2;
                    table[i][j] = 1;
                    j += 1;
                    print_table(table);
                }
                else lose = 1;
                break;
            case 4:
                if (table[i][j-1] != 0) {
                    table[i][j-1] = 2;
                    table[i][j] = 1;
                    j -= 1;
                    print_table(table);
                }
                else lose = 1;
                break;
        }
        if (lose) {
            cout << "Perdiste" << endl;
            break;
        } else if (i == 9 && j == 9) {
            cout << "YOU WIN!" << endl;
            break;
        }
    }
}

int main (void) {
    int table[10][10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = 1;
        }
    }

    putzero(table);
    print_table(table);
    game(table);
}