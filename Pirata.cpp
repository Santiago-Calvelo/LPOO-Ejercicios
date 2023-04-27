#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void dibujarTablero(int n, int** mapa) {
    system("cls");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

void buscarTesoro(int n, int** mapa, int tx, int ty) {
    int count = 0, r = 0, s = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mapa[i][j] == 3) {
                r = i;
                s = j;
            }
        }
    }
    int lose = 0;
    while (count < 50) {
        char choice;
        cout << "Para donde quieres moverte? Norte(N), Sur(S), Este(E), Oeste(O)" << endl;
        cin >> choice;

        if (choice == 'N' || choice == 'n') {
            if (mapa[r-1][s] != 2) {
                mapa[r-1][s] = 3;
                mapa[r][s] = 1;
                r -= 1;
            } else lose = 1;
        }
        else if (choice == 'S' || choice == 's') {
            if (mapa[r+1][s] != 2) {
                mapa[r+1][s] = 3;
                mapa[r][s] = 1;
                r += 1;
            } else lose = 1;
        }
        else if (choice == 'E' || choice == 'e') {
            if (mapa[r][s+1] != 2) {
                mapa[r][s+1] = 3;
                mapa[r][s] = 1;
                s += 1;
            } else lose = 1;
        }
        else if (choice == 'O' || choice == 'o') {
            if (mapa[r][s-1] != 2) {
                mapa[r][s-1] = 3;
                mapa[r][s] = 1;
                s -= 1;
            } else lose = 1;
        }
        count++;
        dibujarTablero(n,mapa);

        if (r == tx && s == ty) {
            cout << "Ganaste!" << endl;
            break;
        }
        if (lose) {
            cout << "Perdiste" << endl;
            break;
        }
    }
    if (count == 50) cout << "Perdiste" << endl;
}

void inicializarTablero(int n, int** mapa, int &tx, int &ty) {
    for (int i = 0; i < n; i++) {
        mapa[0][i] = 2;
        mapa[n-1][i] = 2;
        mapa[i][0] = 2;
        mapa[i][n-1] = 2;
    }

    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            mapa[i][j] = 1;
        }
    }
    tx = rand() % (n-2) + 1;
    ty = rand() % (n-2) + 1;
    while (1) {
        int r = rand() % (n-2) + 1;
        int s = rand() % (n-2) + 1;

        if (tx != r || ty != s) {
            mapa[r][s] = 3;
            break;
        }
    }
}

int main(void) {
    int n;
    int tx = 0;
    int ty = 0;
    srand(time(NULL));

    cout << "Ingrese la medida de su tablero teniendo en cuenta que sera cuadrado" << endl;
    cin >> n;

    int** mapa = new int*[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new int[n];
    }

    inicializarTablero(n,mapa,tx,ty);
    dibujarTablero(n,mapa);
    buscarTesoro(n,mapa,tx,ty);
}