/**************************************
* NOMBRE: #Jesus#
* PRIMER APELLIDO: #Lopez#
* SEGUNDO APELLIDO: #Perez#
* EMAIL: #jlopez6646@alumno.uned.es#
***************************************/


#include <stdio.h>


int main(){


  int lado;
  int aux;

  printf("¿Lado del rombo?");
  scanf("%d",&lado);

  if (lado == 1) {
   printf("@");
  }


  else {

    for ( int vertical1 = lado; vertical1 >= 1; vertical1--){
      printf("\n");

      for (int i = 1; i < vertical1; i++){
       printf("O");
      }
    printf("@");

      for (int i = 1; i < lado; i++){
      if ( vertical1 == lado-i){
       printf(".");
      }


      }




    }








    /*FALTA un bucle para construir el rombo por la derecha
      if ( (vertical1 == lado-3) ){
       printf("o");
      }

      if ( (vertical1 == lado-3) ){
        printf(".");
      }


      if ( (vertical1 <= lado-4) && (vertical1 != lado)){
       printf("@");

      }

    for (int k = 1; k < lado-3; k++ ){
      if ( vertical1 == k){
          printf(".");
      }
    }

    for (int k = 1; k < lado-3; k++ ){
      if ( vertical1 == k){
          printf("o");
      }
    }

    for (int k = 1; k < lado-3; k++ ){
      if ( vertical1 == k){
          printf(".");
      }
    }

    for (int k = 1; k < lado-2; k++ ){
      if ( vertical1 == k){
          printf("@");
      }*/
    }






}



