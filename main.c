#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"

#define N 10

int main() {

    srand(getpid());
    int i,j;
    float numCartas[10] = { 1.0,2.0,3.0,4.0,5.0,6.0,7.0,10.0,11.0,12.0};
    int carta;
    char palo[N];
    int cantJugadores, cantRondas;

/// DEFIRNIR LA CANTIDAD DE JUGADORES

    do{
        printf("Seleccione la cantidad de jugadores: ");
        scanf("%d", &cantJugadores);
        printf("Seleccione la cantidad de rondas: ");
        scanf("%d", &cantRondas);
    } while(cantJugadores > 5);

    float arr[cantJugadores][cantRondas];
    int jugadores[cantJugadores];


/// REPARTIR CARTAS
    repartir(numCartas, palo, jugadores, cantJugadores, carta);
    printf("\n");
    for(i=0; i<(cantJugadores+1);i++){
        printf("Jugadores: %d\n", jugadores[(i)]);
    }

// MEDIO PUNTO Y ACUMULADOR



// PEDIR O PLANTARSE

    pedirPlantarse(jugadores, cantJugadores, numCartas);
//    pedir(jugadores, numCartas, cantJugadores);


    printf("\n");
    for(i=0; i<(cantJugadores+1);i++){
        printf("Jugadores: %d\n", jugadores[(i)]);
    }

}

// FUNCIONES

float selCarta(int a, float b[]) { // a: carta - b: array de cartas
    int i;
    for(i=0; i<1; i++){
        a = b[rand() % 10];
    }
    printf("%d \n", a);
    return a;
}

char *selPalo(char b[N]) { // b: palos de las cartas
    int  n = 1+rand() % 4;
    if(n == 1) {strcpy(b, "Oro");}
    if(n == 2) {strcpy(b, "Copa");}
    if(n == 3) {strcpy(b, "Espada");}
    if(n == 4) {strcpy(b, "Basto");}
//    printf(" de %s", b);
}

void repartir(float a[], char b[N], int c[], int d, int e) {  // a: cartas - b: palos- c: array jugadores y banca - d: cantidad de jugadores - e: variable pibot
    int i;
    for(i=0; i<(d+1); i++){
        c[i] = selCarta(e, a);
        printf("\n");
//        printf("JUGADOR %d: %d", i, c[i]);
        selPalo(b);
    }
    printf("\n");
}

float medioPunto(float a) {
    if(a >9) {
       return a = 0.5;
    } else {
        return a;
    }
}

int pedirPlantarse(int a[], int b, float c[]){ // a: array banca y jugadores - b: cantindad de jugadores - c: array de cartas
        int selec, i, x;

        float puntos,carta,medio;

        for(i = 0; i<b+1; i++){
            float acum = 0.0;
            puntos = a[i];
            acum += medioPunto(puntos);
            printf("\n");
            printf("PUNTOS JUGADOR %d: %.1f\n", i,acum);

            do{

                printf("\n");
                printf("PEDIR: 0\n");
                printf("PLANTARSE: 1\n");
                scanf("%d", &selec);

                carta = selCarta(x, c);
                medio = medioPunto(carta);
                acum += medio;

                printf("PUNTOS JUGADOR %d -->: %.1f\n", i,acum);
                printf("---------------------------------------------------\n");
//                printf("PUNTOS NOSE: %.1f\n", acum);

            } while(selec == 0);
            a[i] = acum;
            printf("JUGADOR [%d]: %d\n", i, a[i]);
            printf("TOTAL: %.1f\n\n", acum);
            printf("---------------------------------------------------\n");
        }
}





