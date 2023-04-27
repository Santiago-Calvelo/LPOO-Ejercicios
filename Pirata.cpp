#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void dibujarTablero(int n, int** mapa) {
    // vacio la terminal
    system("cls");
    // imprimo el mapa con todas las posiciones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

void buscarTesoro(int n, int** mapa, int tx, int ty) {
    // declaro todas las variables que se usaran durante el codigo
    int count = 0, r = 0, s = 0;

    // encuentro al jugador y guardo sus coordenadas en r y s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mapa[i][j] == 3) {
                r = i;
                s = j;
            }
        }
    }
    // declaro la variable que comprobara si perdio
    int lose = 0;
    // count contara cuantas veces se ejecuta el ciclo, si a las 50 el jugador no encuentra el tesoro perdio
    while (count < 50) {
        // le pregunto al jugador para donde desea moverse y lo almaceno en choice
        char choice;
        cout << "Para donde quieres moverte? Norte(N), Sur(S), Este(E), Oeste(O)" << endl;
        cin >> choice;

        // en base a su eleccion reajusto la posicion del jugador
        if (choice == 'N' || choice == 'n') {
            // compruebo si cayó al agua, si lo hizo lose = 1
            if (mapa[r-1][s] != 2) {
                mapa[r-1][s] = 3;
                mapa[r][s] = 1;
                r -= 1;
            } else lose = 1;
        }
        else if (choice == 'S' || choice == 's') {
            // compruebo si cayó al agua, si lo hizo lose = 1
            if (mapa[r+1][s] != 2) {
                mapa[r+1][s] = 3;
                mapa[r][s] = 1;
                r += 1;
            } else lose = 1;
        }
        else if (choice == 'E' || choice == 'e') {
            // compruebo si cayó al agua, si lo hizo lose = 1
            if (mapa[r][s+1] != 2) {
                mapa[r][s+1] = 3;
                mapa[r][s] = 1;
                s += 1;
            } else lose = 1;
        }
        else if (choice == 'O' || choice == 'o') {
            // compruebo si cayó al agua, si lo hizo lose = 1
            if (mapa[r][s-1] != 2) {
                mapa[r][s-1] = 3;
                mapa[r][s] = 1;
                s -= 1;
            } else lose = 1;
        }
        // sumo al contador de ejecuciones
        count++;
        // imprimo el mapa con las nuevas posiciones
        dibujarTablero(n,mapa);

        // si las coordenadas del jugador son las mismas que las del tesoro se le informa que ganó y se sale del while
        if (r == tx && s == ty) {
            cout << "Ganaste!" << endl;
            break;
        }
        // si lose = 1 se le avisa al jugador que perdió y se sale del while
        if (lose) {
            cout << "Perdiste" << endl;
            break;
        }
    }
    // si el jugador no encontro el tesoro en los 50 intentos se le informa que perdio
    if (count == 50) cout << "Perdiste" << endl;
}

// declaro tx y ty como un acceso a la direccion de memoria para poder editar sus valores
void inicializarTablero(int n, int** mapa, int &tx, int &ty) {
    // lleno los bordes con agua(2)
    for (int i = 0; i < n; i++) {
        mapa[0][i] = 2;
        mapa[n-1][i] = 2;
        mapa[i][0] = 2;
        mapa[i][n-1] = 2;
    }
    // lleno el mapa con espacios por donde el jugador se podra mover(1)
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            mapa[i][j] = 1;
        }
    }

    // le doy un valor aleatorio entre los espacios sin agua a las coordenadas del tesoro 
    tx = rand() % (n-2) + 1;
    ty = rand() % (n-2) + 1;
    while (1) {
        // declaro la posicion del jugador y repito el bucle para asegurarme que no sea igual a la posicion del tesoro
        int r = rand() % (n-2) + 1;
        int s = rand() % (n-2) + 1;

        if (tx != r || ty != s) {
            // coloco al jugador(3) en el mapa
            mapa[r][s] = 3;
            break;
        }
    }
}

int main(void) {
    // declaro las variables que se usaran, n almacena la dimension del tablero, tx y ty almacenan la posicion del tesoro
    int n;
    int tx = 0;
    int ty = 0;
    srand(time(NULL));

    // le pido al jugador la dimension del tablero
    cout << "Ingrese la medida de su tablero teniendo en cuenta que sera cuadrado" << endl;
    cin >> n;

    // declaro el mapa como punter(Sin esto no funcionaba el codigo y tenia que usar globlales, me enseñaron a no usarlas)
    int** mapa = new int*[n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new int[n];
    }

    // lleno el tablero con todas las posiciones
    inicializarTablero(n,mapa,tx,ty);
    // imprimo el tablero
    dibujarTablero(n,mapa);
    // inicio el juego
    buscarTesoro(n,mapa,tx,ty);
}