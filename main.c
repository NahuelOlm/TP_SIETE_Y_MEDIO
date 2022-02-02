#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"

#define N 10

int main() {

    srand(getpid());
    int i,j;
    float b[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,10.0,11.0,12.0};
    int pedir;
    int jugardor;
    char palo[N];

/// DEFIRNIR LA CANTIDAD DE JUGADORES

    int cantJugadores, cantRondas;

    do{
        printf("Seleccione la cantidad de jugadores: ");
        scanf("%d", &cantJugadores);
        printf("Seleccione la cantidad de rondas: ");
        scanf("%d", &cantRondas);
    } while(cantJugadores > 5);

    float arr[cantJugadores][cantRondas];

/// REPARTIR CARTAS

    selCarta(jugardor, b);
    selPalo(palo);

// PEDIR O PLANTARSE




/// ARRAY "BASE DE DATOS"

    for(i = 0; i < (cantJugadores + 1); i++){
        for(j=0; j<cantRondas; j++){
                arr[i][j] = b[rand() % 10];
        }
    }

    printf("\n");
    for(i=0; i<(cantJugadores + 1); i++){
        for(j=0; j<cantRondas; j++){
            printf("%.1f ",arr[i][j]);
        }
        printf("\n");
    }


}

// FUNCIONES

int selCarta(int a, float b[]) {
    int i;
    for(i=0; i<1; i++){
        a = b[rand() % 10];
    }
    printf("Carta: %d ", a);
}

void selPalo(char b[N]) {
    int  n = 1+rand() % 4;
    if(n == 1) {strcpy(b, "Oro");}
    if(n == 2) {strcpy(b, "Copa");}
    if(n == 3) {strcpy(b, "Espada");}
    if(n == 4) {strcpy(b, "Basto");}
    printf("de %s", b);
}