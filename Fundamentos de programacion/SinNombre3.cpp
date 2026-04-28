

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

const int maxTar = 100;

typedef char tipoTexto [31];

typedef struct Tarjeta {
  tipoTexto nombre;
  float saldo;
  float descuento;
  int horasG;
  bool disponible;
  int id;
};

typedef Tarjeta nTarjetas[maxTar];

typedef struct Operacion{
  nTarjetas tarjeta;

  void NuevoCliente(int &contador);
  void AbanoTarjeta();
  void CargoTarjeta();
  void EstadoTarjeta();

};




void Operacion::NuevoCliente(int &contador){

    int i = contador;
      strcpy(tarjeta[i].nombre ,"NO nulo");
      tarjeta[i].saldo = 22;
      tarjeta[i].descuento = 1;
      tarjeta[i].horasG = 5;
      tarjeta[i].disponible = false;
      tarjeta[i].id = contador;

    contador = contador + 1;

}



int main () {
    int contador = 0;
    int opcion;
    Operacion o;



    do {
      printf("Elige una opcion 1, 2 o 3:\n");
      scanf ("%d", &opcion);


        switch(opcion){

          case 1:
                  o.NuevoCliente(contador);
                  break;

          case 2:
                  printf("Imprimiendo datos:\n");
                  printf("Numero de contador de tarjetas: %d\n", contador);
                  printf("Id de tarjeta: %d\n", o.tarjeta[contador-1].id);

                  break;

          case 3:
                  printf("Saliendo");
                  break;

        }





    }while (opcion != 3);
    return 0;





}
