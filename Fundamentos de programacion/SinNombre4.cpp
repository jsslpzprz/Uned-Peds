

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


const int maxAsignaturas = 15;
const int maxProfesores = 20;

typedef char textoCadena [51];
typedef enum diaSemana {lunes, martes, miercoles, jueves, viernes};
typedef int idProfesor [maxProfesores];



typedef struct Clase{
  textoCadena nombreAsig;
  idProfesor profesor;
  diaSemana dia;
  int horaInicio;
  bool disponibilidad;

  void agregarClase (textoCadena texto, diaSemana dia, int inicio);
  void listarHorarioProfesor();
  void imprimirTodosLosHorarios();

};

typedef Clase nClases [maxAsignaturas];


void Clase::agregarClase(textoCadena texto , diaSemana dia1, int inicio){
    strcpy(nombreAsig, texto);
    dia = dia1;
    horaInicio = inicio;


}





int main(){
  nClases clases;
textoCadena textaco = "Holaaaa";
  int pos = 0;

  clases[pos].agregarClase(textaco, lunes, 1);


  printf("%s",clases[test].nombreAsig);
}
