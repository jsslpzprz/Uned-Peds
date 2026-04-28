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

/* Constantes */
const int TotalElectrolineras = 10;
const int TotalPuntoCarga = 20;


/* Tipos structs */
typedef struct PuntoCarga{
  bool usada;
  int idcarga;
  char corriente;
  int potencia;
  int rodajaMin;
  int hora;
  int min;
  int dia;
  int mes;
  int anio;
  int duracion;
  bool reservada;
};

typedef struct Electrolinera{
  bool usada;
  int id;
  char nombre[21];
  int rapidos;
  int medios;
  int lentos;
  char tipo[7];
  float latitud;
  float longitud;
  PuntoCarga puntos[20];
};



/*Tipos typedef */
typedef Electrolinera Electrolineras[10];
typedef PuntoCarga PuntosCargas[20];
typedef int ocupacion[32];

Electrolineras electrolineras;

/* Variables */
char Letra;
char Salir;
char confirmar;
char txt;


/*Inicio funcion apartado 1 =================================================================================================== 1*/

void EditarElectrolinera(){
    Electrolinera e;
    int pos;
      printf("Editar electrolinera:\n\n");
        printf("\tIdentificador (numero entre 1 y 10)?");
        scanf("%2d", &e.id);
        pos = e.id - 1;

        printf("\tNombre (entre 1 y 20 caracteres)?");
        scanf("%20s", &e.nombre);

      /*If anidados para el calculo de 20 electrolineras maximo*/
        printf("\tNum. de puntos de carga RAPIDOS-NIVEL 3?");
        scanf("%2d", &e.rapidos);
          if (e.rapidos == 20){
            e.medios = 0;
            e.lentos = 0;
            printf("\tTipo Estacion (Urbana, Ruta, Mixta)?");
            scanf("%6s", &e.tipo);
            printf("\tLatitud (WGS84)?");
            scanf("%6f", &e.latitud);
            printf("\tLongitud (WGS84)?");
            scanf("%6f", &e.longitud);
            printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.\nSon correctos los nuevos datos (S/N)?");
            scanf("%1s", &confirmar);

              if (confirmar == 'S' || confirmar == 's') {
                electrolineras[pos] = e;
                electrolineras[pos].usada = true;
                printf("\nElectrolinera guardada correctamente.\n");
              } else {
                printf("\nOperacion cancelada.\n");
              }
              return;

          }else if (e.rapidos < 20){
              printf("\tNum. de puntos de carga SEMI-RAPIDOS-Nivel 2?");
              scanf("%2d", &e.medios);
              if ((e.medios+e.rapidos) > 20){
                printf("Numero de puntos de carga por encima de lo esperado maximo 20");
                return;

              }else if((e.medios+e.rapidos) == 20){
                e.lentos = 0;
                printf("\tTipo Estacion (Urbana, Ruta, Mixta)?");
                scanf("%6s", &e.tipo);
                printf("\tLatitud (WGS84)?");
                scanf("%6f", &e.latitud);
                printf("\tLongitud (WGS84)?");
                scanf("%6f", &e.longitud);
                printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.\nSon correctos los nuevos datos (S/N)?");
                scanf("%1s", &confirmar);

                  if (confirmar == 'S' || confirmar == 's') {
                    electrolineras[pos] = e;
                    electrolineras[pos].usada = true;
                    printf("\nElectrolinera guardada correctamente.\n");
                  } else {
                    printf("\nOperacion cancelada.\n");
                  }
                return;

              }else if ((e.medios+e.rapidos) < 20){
                printf("\tNum. de puntos de carga LENTOS-Nivel 1?");
                scanf("%2d", &e.lentos);

                if ((e.lentos + e.medios + e.rapidos)<= 20){
                      printf("\tTipo Estacion (Urbana, Ruta, Mixta)?");
                      scanf("%6s", &e.tipo);
                      printf("\tLatitud (WGS84)?");
                      scanf("%6f", &e.latitud);
                      printf("\tLongitud (WGS84)?");
                      scanf("%6f", &e.longitud);
                      printf("\n\nIMPORTANTE: Esta opcion borra los datos anteriores.\nSon correctos los nuevos datos (S/N)?");
                      scanf("%1s", &confirmar);

                        if (confirmar == 'S' || confirmar == 's') {
                          electrolineras[pos] = e;
                          electrolineras[pos].usada = true;
                          printf("\nElectrolinera guardada correctamente.\n");
                        } else {
                          printf("\nOperacion cancelada.\n");
                        }
                return;

                }else{
                  printf("Numero de puntos de carga por encima de lo esperado maximo 20");
                return;
                  }
                }
              }
          else {
          printf("Numero de puntos de carga por encima de lo esperado maximo 20");
          return;
          }

}

/*Fin funcion apartado 1 */





/*Inicio funcion apartado 2 =================================================================================================== 2*/

void EditarPuntoRecarga(){
    int id, pos, numPunto, nivel;
    PuntoCarga p;

    printf("Editar punto de carga:\n\n");
    printf("\tIdentificador electrolinera (1-10)? ");
    scanf("%d",&id);

    if(id<1 || id>10 || !electrolineras[id-1].usada){
        printf("\nElectrolinera no valida.\n");
        return;
    }

    pos = id - 1;
    printf("\tIdentificador punto de carga (1-20)? ");
    scanf("%d",&numPunto);

    if(numPunto < 1 || numPunto > electrolineras[pos].rapidos + electrolineras[pos].medios + electrolineras[pos].lentos){
        printf("\nPunto no existente.\n");
        return;
    }

    /* Determinar nivel Alto 3 Medio 2 Bajo 1*/
    if (numPunto <= electrolineras[pos].rapidos){
        nivel = 3;
    }else if (numPunto <= electrolineras[pos].rapidos + electrolineras[pos].medios){
        nivel = 2;
    }else{
        nivel = 1;
    }

    if (nivel == 3 ){
          printf("\tTipo de corriente (AC/DC)? ");
          p.corriente = 'D';
          printf("DC\n");
          printf("\tPotencia (kW)? ");
          scanf("%d",&p.potencia);

              if (p.potencia < 50 || p.potencia > 300){
                printf("Valor no valido, introduzca valor entre 50 y 300 kW\n");
                return;
              }else {
                  printf("\tRodaja minima (minutos)? ");
                  scanf("%d",&p.rodajaMin);

                  printf("\nSon correctos los nuevos datos (S/N)? ");
                  scanf(" %c",&confirmar);

                      if(confirmar=='S' || confirmar=='s'){
                          p.usada = true;
                          p.idcarga = numPunto;
                          p.reservada = false;

                          electrolineras[pos].puntos[numPunto-1] = p;

                          printf("\n\tConfiguracion correcta: Electrolinera %d. Punto %d. Nivel %d\n",id,numPunto,nivel);
                      }
              }

      }else if (nivel == 2){
            printf("\tTipo de corriente (AC/DC)? ");
            p.corriente = 'A';
            printf("AC\n");

            printf("\tPotencia (kW)? ");
            scanf("%d",&p.potencia);
                  if (p.potencia < 11 || p.potencia > 22){
                    printf("Valor no valido, introduzca valor entre 11 y 22 kW\n");
                    return;
                  }else {
                          printf("\tRodaja minima (minutos)? ");
                          scanf("%d",&p.rodajaMin);

                          printf("\nSon correctos los nuevos datos (S/N)? ");
                          scanf(" %c",&confirmar);

                          if(confirmar=='S' || confirmar=='s'){
                              p.usada = true;
                              p.idcarga = numPunto;
                              p.reservada = false;

                              electrolineras[pos].puntos[numPunto-1] = p;

                              printf("\n\tConfiguracion correcta: Electrolinera %d. Punto %d. Nivel %d\n",id,numPunto,nivel);
                          }
                  }

      }else {
            printf("\tTipo de corriente (AC/DC)? ");
            p.corriente = 'A';
            printf("AC\n");

            printf("\tPotencia (kW)? ");
            scanf("%d",&p.potencia);
                  if (p.potencia < 2 || p.potencia > 4){
                    printf("Valor no valido, introduzca valor entre 2 y 4 kW\n");
                    return;
                  }else {
                      printf("\tRodaja minima (minutos)? ");
                      scanf("%d",&p.rodajaMin);

                      printf("\nSon correctos los nuevos datos (S/N)? ");
                      scanf(" %c",&confirmar);

                            if(confirmar=='S' || confirmar=='s'){
                                p.usada = true;
                                p.idcarga = numPunto;
                                p.reservada = false;

                                electrolineras[pos].puntos[numPunto-1] = p;

                                printf("\n\tConfiguracion correcta: Electrolinera %d. Punto %d. Nivel %d\n",id,numPunto,nivel);
                            }
                  }
        }
}


/*Fin funcion apartado 2 */



/*Inicio funcion apartado 3 =================================================================================================== 3*/

void ReservarPuntoRecarga() {

    int id, pos, nivel;
    int d, m, a, h, min, dur;
    int i, inicio, fin;
    int rodaja, durFinal;
    int encontrado = -1;

    printf("Reservar punto de recarga:\n\n");

    printf("\tIdentificador electrolinera? ");
    scanf("%d", &id);

    if (id < 1 || id > 10 || !electrolineras[id-1].usada) {
        printf("\nElectrolinera no valida.\n");
        return;
    }

    pos = id - 1;

    printf("\tTipo de punto de recarga (1/2/3)? ");
    scanf("%d", &nivel);

    printf("\tDatos reserva: Dia? ");
    scanf("%d", &d);
    printf("\tMes? ");
    scanf("%d", &m);
    printf("\tAnio? ");
    scanf("%d", &a);
    printf("\tHora? ");
    scanf("%d", &h);
    printf("\tMinuto? ");
    scanf("%d", &min);
    printf("\tDuracion (min)? ");
    scanf("%d", &dur);

        /* Determinando rango de puntos segun nivel */
        if (nivel == 3) {
            inicio = 0;
            fin = electrolineras[pos].rapidos;
        } else if (nivel == 2) {
            inicio = electrolineras[pos].rapidos;
            fin = inicio + electrolineras[pos].medios;
        } else {
            inicio = electrolineras[pos].rapidos + electrolineras[pos].medios;
            fin = inicio + electrolineras[pos].lentos;
        }

    /* Buscar punto libre */
    for (int i = inicio; i < fin; i++) {
        if (!electrolineras[pos].puntos[i].reservada) {
            encontrado = i;
        }
    }


        if (encontrado == -1) {
            printf("\nFecha/hora elegida completa-La reserva no se puede realizar\n");
            return;
        }

    /* Ajuste duracion a rodajas */
    rodaja = electrolineras[pos].puntos[encontrado].rodajaMin;
    durFinal = ((dur + rodaja - 1) / rodaja) * rodaja;

    printf("\n\t\tDatos de la reserva:\n\n");
    printf("\tE/S:\n",electrolineras[pos].nombre);
    printf("\tFecha: %d-%d-%d\n", d, m, a);
    printf("\tHora: %02d:%02d\n", h, min);
    printf("\tDuracion: %d minutos\n", durFinal);

    printf("\nSon correctos los datos (S/N)? ");
    scanf(" %c", &confirmar);

    if (confirmar == 'S' || confirmar == 's') {
        electrolineras[pos].puntos[encontrado].reservada = true;
        electrolineras[pos].puntos[encontrado].dia = d;
        electrolineras[pos].puntos[encontrado].mes = m;
        electrolineras[pos].puntos[encontrado].anio = a;
        electrolineras[pos].puntos[encontrado].hora = h;
        electrolineras[pos].puntos[encontrado].min = min;
        electrolineras[pos].puntos[encontrado].duracion = durFinal;

        printf("\n\tReserva correcta.\n");
        printf("\t\tIdentificador: N%d-%002d-%02d-%04d\n", nivel, encontrado+1, m, a);
        printf("\t\tFecha y hora: %d-%d-%d ", d, m, a);
        printf("%02d:%02d\n", h, min);
        printf("\t\tTiempo %d minutos\n", durFinal);
    }
}


/*Fin funcion apartado 3 */


/*Inicio funcion apartado 4 =================================================================================================== 4*/

/*Funcion*/
void ListarReservas() {

    int id, mes, anio;
    int pos;
    bool hayReservas = false;
    PuntoCarga p;

    printf("Listar reservas de electrolinera:\n\n");
    printf("\tIdentificador de la electrolinera? ");
    scanf("%d", &id);

    printf("\tMes Reservas? ");
    scanf("%d", &mes);

    printf("\tAnio Reservas? ");
    scanf("%d", &anio);

    if (id < 1 || id > 10 || !electrolineras[id-1].usada) {
        printf("\nElectrolinera no valida.\n");
        return;
    }

    pos = id - 1;

    printf("\nLa electrolinera \"%s\" tiene las siguientes reservas para el mes %d del anio %d:\n\n",
           electrolineras[pos].nombre, mes, anio);

    /* NIVEL 1 */
    printf("\tNivel 1.\n");
    for (int i = electrolineras[pos].rapidos + electrolineras[pos].medios;
         i < electrolineras[pos].rapidos + electrolineras[pos].medios + electrolineras[pos].lentos; i++) {

        p = electrolineras[pos].puntos[i];

        if (p.reservada && p.mes == mes && p.anio == anio) {
            hayReservas = true;
            printf("\t\tPunto de recarga %d-%04d-%02d-%04d ", p.idcarga, i+1, mes, anio);
            printf("Fecha: %d/%d/%d Hora: %02d:%02d Duracion: %d min.\n", p.dia, p.mes, p.anio, p.hora, p.min, p.duracion);
        }
    }

    /* NIVEL 2 */
    printf("\n\tNivel 2.\n");
    for (int i = electrolineras[pos].rapidos; i < electrolineras[pos].rapidos + electrolineras[pos].medios; i++) {

        p = electrolineras[pos].puntos[i];

        if (p.reservada && p.mes == mes && p.anio == anio) {
            hayReservas = true;
            printf("\t\tPunto de recarga %d-%04d-%02d-%04d ", p.idcarga, i+1, mes, anio);
            printf("Fecha: %d/%d/%d Hora: %02d:%02d Duracion: %d min.\n", p.dia, p.mes, p.anio, p.hora, p.min, p.duracion);
        }
    }

    /* NIVEL 3 */
    printf("\n\tNivel 3.\n");
    for (int i = 0; i < electrolineras[pos].rapidos; i++) {

        p = electrolineras[pos].puntos[i];

        if (p.reservada && p.mes == mes && p.anio == anio) {
            hayReservas = true;
            printf("\t\tPunto de recarga %d-%04d-%02d-%04d ", p.idcarga, i+1, mes, anio);
            printf("Fecha: %d/%d/%d Hora: %02d:%02d Duracion: %d min.\n", p.dia, p.mes, p.anio, p.hora, p.min, p.duracion);
        }
    }

    if (!hayReservas) {
        printf("\nLa electrolinera \"%s\" no tiene reservas para el mes %d del anio %d.\n", electrolineras[pos].nombre, mes, anio);
    }
}

/*Fin funcion apartado 4*/


/*Funcion para el calculo de dias por mes y año */

int diasMes(int mes, int anio) {
    if (mes == 2) {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
            return 29;
        }else{
            return 28;
        }
    }
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    }
    return 31;

}




/*Inicio funcion apartado 5 =================================================================================================== 5  -- NO TERMINADA -- */

void ListarServicioMensualPunto() {

    int id, punto, mes, anio, pos, dias, min, maxDia;
    float porcentaje = 0;

    PuntoCarga p;
    ocupacion Ocu;

    printf("Reservas Mensuales Punto de Recarga:\n");

    printf("Identificador de la electrolinera? ");
    scanf("%d", &id);

    printf("Numero de punto de recarga? ");
    scanf("%d", &punto);

    printf("Seleccion Mes? ");
    scanf("%d", &mes);

    printf("Seleccion Anio? ");
    scanf("%d", &anio);

        if (id < 1 || id > 10 || !electrolineras[id-1].usada) {
            printf("\nElectrolinera no valida.\n");
            return;
        }

        pos = id - 1;

        if (punto < 1 || punto > electrolineras[pos].rapidos + electrolineras[pos].medios + electrolineras[pos].lentos) {
            printf("\nPunto de carga no valido.\n");
            return;
        }

    p = electrolineras[pos].puntos[punto-1];

    /* Mostrar cabecera */
    printf("\n\n\t\tOcupacion Punto de Recarga: %d\n", punto);
    printf("\t\tElectrolinera: %s\n\n", electrolineras[pos].nombre);



  /* Funcion de calendario, no implementada */


    printf("Punto de Carga %d", punto);

    if (punto <= electrolineras[pos].rapidos){
        printf("-N3");
    }else if (punto <= electrolineras[pos].rapidos + electrolineras[pos].medios){
        printf("-N2");
    }else{
        printf("-N1");
    }


    if (p.reservada == true) {
        printf("\nDia de maxima ocupacion - %d/%d/%d (%2f%)\n", maxDia, mes, anio, porcentaje);
    } else {
        printf("\nSin reservas en este mes.\n");
    }

    printf("\nMostrar otro mes (S/N)? ");
    scanf(" %c", &confirmar);
}


/*Fin funcion apartado 5*/





/* Funcion extra accesible con la tecla I en el menu para ver el estado, sin modificaciones, de una electrolinera -- EXTRA -- */
void MostrarElectrolinera() {
    int id;
    int pos;

    printf("Mostrar electrolinera\n\n");
    printf("\tIdentificador (numero entre 1 y 10)? ");
    scanf("%d", &id);

    /* Validar id */
    if (id < 1 || id > 10) {
        printf("\nIdentificador no valido.\n");
        return;
    }

    pos = id - 1;

    /* Comprobar si esta usada */
    if (!electrolineras[pos].usada) {
        printf("\nLa electrolinera %d no tiene datos.\n", id);
        return;
    }

    /* Mostrar datos */
    printf("\nDatos de la electrolinera %d:\n\n", id);
    printf("\tNombre: %s\n", electrolineras[pos].nombre);
    printf("\tPuntos rapidos: %d\n", electrolineras[pos].rapidos);
    printf("\tPuntos medios: %d\n", electrolineras[pos].medios);
    printf("\tPuntos lentos: %d\n", electrolineras[pos].lentos);
    printf("\tTipo: %s\n", electrolineras[pos].tipo);
    printf("\tLatitud: %.6f\n", electrolineras[pos].latitud);
    printf("\tLongitud: %.6f\n", electrolineras[pos].longitud);
}


int main(){


  do{
/* Opciones principales */
  printf("GesELECTRERA: Gestion de electrolineras\n\n");
      printf("\tEditar electrolinera\t\t\t");
      printf("(Pulsar E)\n");

      printf("\tEditar punto de recarga\t\t\t");
      printf("(Pulsar P)\n");

      printf("\tReservar punto de recarga\t\t");
      printf("(Pulsar R)\n");

      printf("\tListar reservas de electrolinera\t");
      printf("(Pulsar L)\n");

      printf("\tListar servicio mensual punto\t\t");
      printf("(Pulsar M)\n");

      printf("\tSalir\t\t\t\t\t");
      printf("(Pulsar S)\n\n");

  printf("Teclear una opcion valida (E|P|R|L|M|S)?");

  scanf("%s", &Letra);

/* Fin opciones principales, con la opcion I muestra info de una electrolinera*/


  switch(Letra){
    case 'E':
      printf("\n======================================================\n\n");
      EditarElectrolinera();
      printf("\n======================================================\n\n");
    break;


    case 'P':
      printf("\n======================================================\n\n");
      EditarPuntoRecarga();
      printf("\n======================================================\n\n");
    break;


    case 'R':
      printf("\n======================================================\n\n");
      ReservarPuntoRecarga();
      printf("\n======================================================\n\n");
    break;


    case 'L':
      printf("\n======================================================\n\n");
      ListarReservas();
      printf("\n======================================================\n\n");
    break;


    case 'M':
      printf("\n======================================================\n\n");
      ListarServicioMensualPunto();
      printf("\n======================================================\n\n");
    break;

    case 'I':
      printf("\n======================================================\n\n");
      MostrarElectrolinera();
      printf("\n======================================================\n\n");
    break;

    case 'S':
      printf("\n\n======================================================\n\n");
      printf("Saliendo del programa...\n");
    break;

  }

  }while (Letra != 'S');
    return 0;

}
