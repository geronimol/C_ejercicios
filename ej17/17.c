#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "tdapila.h"

void cargapila(TPILA *p);
void muestrapila(TPILA *p);

int main(void){
    TPILA p;
    cargapila(&p);
    muestrapila(&p);

    return 0;}

void cargapila(TPILA *p){
    char pal[20];
    iniciap(p);
    printf("Ingresar palabra\n");
        while(gets(pal)!=NULL){
            ponep(p,pal);
        }
    }
void muestrapila(TPILA *p){
    char pal[20];
    while(!vaciap(*p)){
        sacap(p,pal);
        printf("%s",pal);
    }

    }
