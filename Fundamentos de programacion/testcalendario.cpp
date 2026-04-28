/**************************************
* NOMBRE:#Jesus#
* PRIMER APELLIDO:#Lopez#
* SEGUNDO APELLIDO:#Perez#
* EMAIL:#jlopez6646@alumno.uned.es#
**************************************/


#include <stdio.h>
#include <stdlib.h>

typedef char *TipoMes;
typedef TipoMes TipoMes3[12];

TipoMes3 nombreMes = {
    "Enero     ", "Febrero   ", "Marzo     ", "Abril     ",
    "Mayo      ", "Junio     ", "Julio     ", "Agosto    ",
    "Septiembre", "Octubre   ", "Noviembre ", "Diciembre "
};

const int Fila = 6;
const int Columna = 27;
typedef int TipoMatriz[Fila][Columna];



/* Algoritmo de inicioM */



/* Numero de dias */



void Imprimir (const TipoMatriz matriz) {
    int inicioM = DiaSemana(anio, mes);
    int diasT = NumDias();
    int dia = 1;

    for (int i = 0; i < 6; i++) {
        if (dia > diasT && i == 5) {
            // No imprimir fila 6 si está vacía
        } else {
            for (int d = 0; d < 7; d++) {
                // --- COLUMNA 0 ---
                if (d == 0) {
                    if (i == 0 && d < inicioM) {
                        printf(" .");
                    } else if (dia <= diasT) {
                        printf("%2d", dia);
                        dia++;
                    } else {
                        printf(" .");
                    }
                }
                // --- COLUMNAS 1 A 6 ---
                else {
                    if (i == 0 && d < inicioM) {
                        printf("  ."); // Espacio + espacio + punto
                    } else if (dia <= diasT) {
                        printf("%3d", dia); // Espacio + 2 dígitos (Total 3)
                        dia++;
                    } else {
                        printf("  .");
                    }
                }

                // --- GESTIÓN DE ESPACIOS Y BARRA ---
                if (d == 4) {
                    printf(" |"); // Barra después del viernes
                } else if (d < 6) {
                    printf(" ");  // Espacio de separación (solo si NO es el último día)
                }
                // Si d == 6 (Domingo), no imprimimos nada después, evitando el espacio final
            }
            printf("\n");
        }
    }
}






int main () {

    int anio;
    int mes;
    TipoMatriz matriz = {0};

    printf("¿Mes (1..12)? ");
    scanf("%d", &mes);

    printf("¿Año (1601..3000)? ");
    scanf("%d", &anio);

    if (anio > 1600 && anio <= 3000 && mes >= 1 && mes <= 12) {

        printf("\n");
        printf("%10s%17d\n", nombreMes[mes - 1], anio);
        printf("===========================\n");
        printf("LU  MA  MI  JU  VI | SA  DO\n");
        printf("===========================\n");

        Imprimir(matriz);
    }

    return 0;
}
