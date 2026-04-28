

/**************************************
* NOMBRE: #Jesus#
* PRIMER APELLIDO: #Lopez#
* SEGUNDO APELLIDO: #Perez#
* EMAIL: #jlopez6646@alumno.uned.es#
***************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


const int maxViviendas = 10;
typedef char tipoCadena[20];


/*
typedef int numViviendas [maxViviendas];
typedef int numHabitaciones[maxViviendas];
typedef float precio[maxViviendas];
typedef bool disponibilidad[maxViviendas];
typedef tipoCadena direccion[maxViviendas];

Esto se puede pero es mala practica, mejor usar struct ((TADS))
*/

typedef struct Vivienda{
  tipoCadena direccion;
  int habitaciones;
  void mostrar();
  void agregarCasa();
};


typedef Vivienda nCasas[maxViviendas];


void Vivienda::mostrar(){
      printf("%s, %d habitaciones\n", direccion, habitaciones);
}

void Vivienda::agregarCasa(){
  strcpy(direccion, "Plaza de españa");
  habitaciones = 55;
}


int main() {
    nCasas casas;

    casas[0].agregarCasa();
    casas[0].mostrar();

    printf("Mostrar casa %s", casas[0].direccion);

}
