

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
const int maxTareas = 20;

typedef char textoCadena [501];

typedef enum prioridad {Alta, Media, Baja};


typedef struct Tarea{
  textoCadena descripcion;
  int duracion;
  prioridad prio;
  bool completado;
};

typedef Tarea nTareas[maxTareas];

typedef struct Gestion{
 nTareas tareas;

 void HorasPendientesAltaPrioridad();
 void TareasPendientes(prioridad p);
 void MostrarNoCompletadas();

};



void Gestion::HorasPendientesAltaPrioridad(){
      for (int i = 0; i < maxTareas; i++){
          if (tareas[i].prio == Alta && tareas[i].completado == false){
              printf("Numero de horas para la tarea %d: horas:%d descripcion:%s\n\n\n", i, tareas[i].duracion, tareas[i].descripcion);
          }
      }
  }


void Gestion::TareasPendientes(prioridad p){
  int contador = 0;
      for (int i = 0; i < maxTareas; i++){
          if (tareas[i].prio == p){
           contador = contador + 1;
          }
      }
      printf("Numero de tareas de prioridad alta: %d \n\n\n", contador);
  }


void Gestion::MostrarNoCompletadas(){
    for (int i = 0; i < maxTareas; i++){
        if( tareas[i].completado == false){
          printf("Tareas no completadas: \n Descripcion: %s, duracion: %d, ", tareas[i].descripcion, tareas[i].duracion);
              if (tareas[i].prio == 0){
               printf("Prioridad: Alta\n\n");
              }else if (tareas[i].prio == 1){
                  printf("Prioridad: Media\n\n");
              }else{ printf("Prioridad: Baja\n\n");
              }
        }
    }
  }





int main() {
Gestion g;

for (int i = 0; i < maxTareas; i++) {
    g.tareas[i].completado = true;
    g.tareas[i].prio = Baja;
}




strcpy(g.tareas[0].descripcion, "Descripcion tarea 0");
g.tareas[0].duracion = 2;
g.tareas[0].prio = Alta;
g.tareas[0].completado = false;


strcpy(g.tareas[5].descripcion, "Descripcion tarea 5");
g.tareas[5].duracion = 5;
g.tareas[5].prio = Alta;
g.tareas[5].completado = false;


strcpy(g.tareas[6].descripcion, "Descripcion tarea 6");
g.tareas[6].duracion = 6;
g.tareas[6].prio = Media;
g.tareas[6].completado = false;


strcpy(g.tareas[1].descripcion, "Descripcion tarea 1");
g.tareas[1].duracion = 1;
g.tareas[1].prio = Media;
g.tareas[1].completado = false;


g.HorasPendientesAltaPrioridad();
g.TareasPendientes(Alta);
g.MostrarNoCompletadas();

}
