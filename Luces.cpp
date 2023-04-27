#include <iostream>
using namespace std;

void end(int calles[5][15], int maxcalle[5], int lucesEncendidas[5]) {
    // declaro la variable que contara la cantidad de calles sin luces
    int callesOscuras = 0;
    for (int i = 0; i < 5; i++) {
        // cuento la cantidad de luces apagadas
        int lucesApagadas = 0;
        for (int j = 0; j < 15; j++) {
            if (calles[i][j] == 0) lucesApagadas++;
        }
        // compruebo y digo que tan iluminada se encuentra una calle dependiendo del caso
        if (lucesApagadas == 15) {
            cout << "Calle " << i+1 << ":"<< "A oscuras" << endl;
            callesOscuras++;
        }
        else if (lucesEncendidas[i] == maxcalle[i] && lucesEncendidas[i] > lucesApagadas) 
            cout << "Calle " << i+1 << ":"<< "Muy luminosa" << endl;
        else if (lucesEncendidas[i] == maxcalle[i] && lucesApagadas >= lucesEncendidas[i])
            cout << "Calle " << i+1 << ":" << "Luminosa" << endl;
        else 
            cout << "Calle " << i+1 << ":" << "Tenebrosa" << endl;
    }
    cout << "La cantidad de calles con todas las luces apagadas es: " << callesOscuras << endl;
}

void printCalles(int calles[5][15]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            cout << calles[i][j] << " ";
        }
        cout << endl;
    }
}

void prenderLuces(int calles[5][15], int maxcalle[5]) {
    // declaro los indices que usare y el array para guardar la cantidad de luces encendidas
    int i, j;
    int luces[5] = {0};
    while (1) {
        // le solicito al usuario la fila y columna donde quiere encender la luz para almacenarlo en los indices 
        cout << "En que fila quiere prender la luz?" << endl;
        cin >> i;
        cout << "En que columna quiere prender la luz?" << endl;
        cin >> j;

        // comparo que la cantidad de luces sea menor al maximo permitido
        if (luces[i-1] < maxcalle[i-1]) {
            // si no lo es enciendo la luz y sumo a la cantidad de luces encendidas
            calles[i-1][j-1] = 1;
            luces[i-1]++;
            // llamo a la funcion para imprimir las calles con los cambios
            printCalles(calles);
        }
        // si ya es mayor/igual al maximo le digo al usuario que alcanzo el maximo de luces
        else cout << "Esta calle tiene el numero maximo de luces" << endl;

        // le pregunto al usuario si quiere seguir encendiendo luces y almaceno su respuesta en choice
        char choice;
        cout << "Desea seguir encendiendo luces? s/n" << endl;
        cin >> choice;
        // en caso de que no quiera seguir salgo del while
        if (choice == 'n') break;
    }
    // imprimo las calles con todos los cambios
    printCalles(calles);
    // llamo a la funcion que nos informara que tan iluminada se encuentra la calle
    end(calles, maxcalle, luces);
}

int main(void) {
    // declaro las variables que se usaran
    int calles[5][15] = {0};
    int maxcalle[5];
    int n;

    // le pido al usuario un numero maximo de luces y lo almaceno en n para luego almacenarlo en el array
    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el maximo de luces que pueden encenderse en la calle " << i+1 << ":" << endl;
        cin >> n;
        maxcalle[i] = n;
    }

    // llamo a la funcion para imprimir la tabla de las luces
    printCalles(calles);
    // llamo a la funcion para encender las luces
    prenderLuces(calles,maxcalle);
}