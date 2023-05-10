#include <iostream>
#include <string>
using namespace std;

const int MAX_NOTAS = 1000; // Máximo número de notas a ingresar 

// Estructura para almacenar una nota
struct Nota {
  string materia;
  int legajo;
  double nota;
};

void ingresarNotas(Nota notas[MAX_NOTAS], int &cantNotas) {
  while (1) {
    string materia;
    int legajo;
    double nota;

    cout << "Ingrese materia (XXX para finalizar): ";
    cin >> materia;
    if (materia == "XXX") break;


    while (1) {
      cout << "Ingrese legajo (0 para finalizar): ";
      cin >> legajo;
      if (legajo == 0) break;
  
      cout << "Ingrese nota: ";
      cin >> nota;

      Nota nuevaNota = {materia, legajo, nota};
      notas[cantNotas] = nuevaNota;
      cantNotas++;
    }
  }
}

void imprimirNotas(Nota notas[MAX_NOTAS], int cantNotas) {
  string materiaTemp;
  // Recorrer todas las materias
  for (int i = 0; i < cantNotas; i++) {
    string materiaActual = notas[i].materia;
    int legajoActual = notas[i].legajo;
    double sumNotas = 0.0;
    int cantNotasAlumno = 0;
    double promedioAlumno = 0.0;
    int max = 0;

    if (materiaActual != materiaTemp) cout << materiaActual << endl;

    // Recorrer todas las notas para la materia actual y el alumno actual
    for (int j = i; j < cantNotas; j++) {
      if (notas[j].materia == materiaActual && notas[j].legajo == legajoActual) {
        sumNotas += notas[j].nota;
        cantNotasAlumno++;
      } else {
        // Ya no hay más notas para el alumno actual en la materia actual
        promedioAlumno = sumNotas / cantNotasAlumno;
        cout << "\tLegajo: " << legajoActual << "\tPromedio: " << promedioAlumno << endl;

        // Avanzar el índice i para la siguiente materia
        i = j - 1;

        // Salir del ciclo interno
        break;
      }
    }

    // Imprimir la última nota del último alumno
    if (i == cantNotas - 1) {
      promedioAlumno = sumNotas / cantNotasAlumno;
      cout << "\tLegajo: " << legajoActual << "\tPromedio: " << promedioAlumno << endl;
    }
    materiaTemp = materiaActual;
  }
}

int main(void) {
  Nota notas[MAX_NOTAS];
  int cantNotas = 0;

  // pido al usuario que ingrese los datos
  ingresarNotas(notas,cantNotas);
  imprimirNotas(notas,cantNotas);
}

