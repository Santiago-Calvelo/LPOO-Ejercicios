#include <iostream>
using namespace std;

void end(int calles[5][15], int maxcalle[5], int lucesEncendidas[5]) {
    for (int i = 0; i < 5; i++) {
        int lucesApagadas = 0;
        for (int j = 0; j < 15; j++) {
            if (calles[i][j] == 0) lucesApagadas++;
        }
        if (lucesApagadas == 15) 
            cout << "Calle " << i+1 << ":"<< "A oscuras" << endl;
        else if (lucesEncendidas[i] == maxcalle[i] && lucesEncendidas[i] > lucesApagadas) 
            cout << "Calle " << i+1 << ":"<< "Muy luminosa" << endl;
        else if (lucesEncendidas[i] == maxcalle[i] && lucesApagadas >= lucesEncendidas[i])
            cout << "Calle " << i+1 << ":" << "Luminosa" << endl;
        else 
            cout << "Calle " << i+1 << ":" << "Tenebrosa" << endl;
    }
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
    int i, j;
    int luces[5] = {0};
    while (1) {
        cout << "En que fila quiere prender la luz?" << endl;
        cin >> i;
        cout << "En que columna quiere prender la luz?" << endl;
        cin >> j;

        if (luces[i-1] < maxcalle[i-1]) {
            calles[i-1][j-1] = 1;
            luces[i-1]++;
            printCalles(calles);
        }
        else cout << "Esta calle tiene el numero maximo de luces" << endl;

        char choice;
        cout << "Desea seguir encendiendo luces? s/n" << endl;
        cin >> choice;

        if (choice == 'n') break;
    }
    printCalles(calles);
    end(calles, maxcalle, luces);
}

int main(void) {
    int calles[5][15] = {0};
    int maxcalle[5];
    int n;

    for (int i = 0; i < 5; i++) {
        cout << "Ingrese el maximo de luces que pueden encenderse en la calle " << i+1 << ":" << endl;
        cin >> n;
        maxcalle[i] = n;
    }

    printCalles(calles);
    prenderLuces(calles,maxcalle);
}