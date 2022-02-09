//
// Created by Nahuel on 2/2/2022.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define N 10

//SELECCION DE CARTA
float selCarta(int a, float b[]);

// SELECCION DE PALO

char *selPalo(char b[N]);

// REPARTIR
void repartir(float a[], char b[N], int c[], int d, int e);

float medioPunto(float a);

// PEDIR CARTAS MAS CONTADOR DE PUNTOS

int pedirPlantarse(int a[], int b, float c[]);

//int pedir(int arrayJugadores[], float arrayCartas[], int cantJugadores);