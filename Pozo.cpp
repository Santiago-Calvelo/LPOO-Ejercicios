#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void print_table(int table[10][10]) {
    // vacio la terminal
    system("cls");
    // imprimo el mapa con todas las posiciones
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

int check(int table[10][10], int zeros) {
    // suma un punto cada que se encuentra un 0, como cuenta los 0 más de una vez cuando llegue a 6 significara que encontro 3
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table[i][j] == 0) zeros++;
        }
    }
    return zeros;
}

void putzero(int table[10][10]) {
    // declaro la variable que contara cuantos 0 hay
    int zeros = 0;
    // agrego el 2(posicion del jugador) en el 00 
    table[0][0] = 2;

    // se ejecuta siempre que la cantidad de 0 sea menor a 3
    while (zeros != 6) {
        // agrego el 0 en posicion aleatoria
        table[rand() % 10][rand() % 10] = 0;
        // compruebo que la posicion 00 y 99 no sean 0
        if (table[0][0] == 0 || table[9][9]) {
            table[0][0] = 2;
            table[9][9] = 1;
        }
        // compruebo la cantidad de 0 que hay
        zeros = check(table, zeros);
    }
}

void game(int table[10][10]) {
    // declaro las variables que se usaran para las posiciones y para informar si perdio el usuario
    int i = 0;
    int j = 0;
    int lose = 0;

    while(1) {
        // le pregunto al jugador para donde se movera y lo almaceno en choice
        int choice;
        cout << "Para donde quieres moverte? Arriba(1), Abajo(2), Derecha(3), Izquierda(4)" << endl;
        cin >> choice;

        // reajusto la posicion del jugador en base a su eleccion
        switch (choice) {
            case 1:
                // compruebo si perdio, en caso de si lose es = 1 
                if (table[i-1][j] != 0) {
                    table[i-1][j] = 2;
                    table[i][j] = 1;
                    i -= 1;
                }
                else lose = 1;
                break;

            case 2:
                // compruebo si perdio, en caso de si lose es = 1 
                if (table[i+1][j] != 0) {
                    table[i+1][j] = 2;
                    table[i][j] = 1;
                    i += 1;
                }
                else lose = 1;
                break;
            case 3:
                // compruebo si perdio, en caso de si lose es = 1 
                if (table[i][j+1] != 0) {
                    table[i][j+1] = 2;
                    table[i][j] = 1;
                    j += 1;
                }
                else lose = 1;
                break;
            case 4:
                // compruebo si perdio, en caso de si lose es = 1 
                if (table[i][j-1] != 0) {
                    table[i][j-1] = 2;
                    table[i][j] = 1;
                    j -= 1;
                }
                else lose = 1;
                break;
        }

        // imprimo el nuevo mapa con posicion actualizada
        print_table(table);
        // si lose es verdadero aviso que perdio y salgo del while, sino compruebo si llego a la ultima posicion
        // si llego a la ultima posicion se le avisa que gano y sale del while
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
    // declaro el tablero y lo lleno de 1(espacios por donde el usuario se puede mover)
    int table[10][10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = 1;
        }
    }
    // agrego los pozos al mapa
    putzero(table);
    // imprimo el mapa
    print_table(table);
    // ejecuto el juego
    game(table);
}