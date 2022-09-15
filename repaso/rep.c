#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"tdacolad.h"

typedef struct nodito{
    int fichas;
    struct nodito *sigs;}TNODITO;
typedef TNODITO *TSUBLISTA;

typedef struct nodol{
    char nombre[20];
    int puntaje;
    int coincidencias;
    TSUBLISTA sub;
    struct nodol *sig;}NODOL;
typedef NODOL *TLISTA;

void cargalista(TLISTA *pl);
void muestralista(TLISTA lista);
void cargacola(TCOLA *c);
void muestracola(TCOLA c);
void insertaordenado(TLISTA *pl,TLISTA nodos);

int main(void){
    TLISTA lista,aux,winners;
    TSUBLISTA ant,act,auxs;
    TCOLA c;
    int n,sinfichas=0,mayor=-1,ganadores=0;
    char ganador[20];
    cargacola(&c);
    cargalista(&lista);

    while(!vaciac(c) && !sinfichas){
        sacac(&c,&n);
        aux=lista;
        while(aux!=NULL && !sinfichas){
            act=aux->sub;
            while(act!=NULL && act->fichas!=n){
                ant=act;
                act=act->sigs;}
            if(act!=NULL){
                strcpy(ganador,aux->nombre);
                aux->puntaje+=40;
                if(aux->sub == act)
                    aux->sub=act->sigs;
                else
                    ant->sigs=act->sigs;
                free(act);
                if(aux->sub==NULL)
                    sinfichas++;}
            aux=aux->sig;}

        aux=lista;
        while (aux!=NULL){
            if(strcmp(aux->nombre,ganador)!=0){
                auxs=aux->sub;
                while(auxs!=NULL){
                    if(auxs->fichas % 100== n){
                        aux->coincidencias++;
                        aux->puntaje+=10;}
                    else
                        if(auxs->fichas%10==n){
                            aux->puntaje+=5;
                            aux->coincidencias++;}
                    auxs=auxs->sigs;}}
            aux=aux->sig;}}

    muestralista(lista);

    aux=lista;
    while(aux!=NULL){
        if(aux->puntaje>mayor){
            mayor=aux->puntaje;
            strcpy(ganador,aux->nombre);}
        aux=aux->sig;}

    aux=lista;
    while(aux!=NULL){
        if(aux->puntaje=mayor)
            insertaordenado(&winners,aux);
        aux=aux->sig;}

    if(winners!=NULL){
        printf("Ganadores:\n");
        muestralista(winners);}
    else
        printf("No hay ganadores!\n");
    /*muestracola(c);*/
    return 0;}

void insertaordenado(TLISTA *pl,TLISTA nodos){
    TLISTA nuevo,ant,act;
    *pl=NULL;
    nuevo=(TLISTA)malloc(sizeof(NODOL));
    strcpy(nuevo->nombre,nodos->nombre);
    nuevo->puntaje=nodos->puntaje;
    nuevo->coincidencias=nodos->coincidencias;
    nuevo->sub=NULL;
    if(*pl==NULL || (*pl)->coincidencias > nodos->coincidencias){
        nuevo->sig=*pl;
        *pl=nuevo;}
    else{
        act=*pl;
        while(act!=NULL && (*pl)->coincidencias < nodos->coincidencias){
            ant=act;act=act->sig;}
        if(act!=NULL){
            nuevo->sig=act;
            ant->sig=nuevo;}
        }
    }

void muestralista(TLISTA lista){
    TSUBLISTA auxs;
    while(lista!=NULL){
        printf("[%s %d %d] -->",lista->nombre,lista->puntaje,lista->coincidencias);
        auxs=lista->sub;
        while(auxs!=NULL){
            printf("%d ",auxs->fichas);
            auxs=auxs->sigs;}
        printf("\n");
        lista=lista->sig;}
}

void cargalista(TLISTA *pl){
    TLISTA nuevo;
    TSUBLISTA auxs;
    char nombre[20];
    int puntaje,coincidencias,fichas;
    *pl=NULL;
    printf("Ingresar nombre LISTA CTRLZ F\n");
    while(gets(nombre)!=NULL){
        nuevo=(TLISTA)malloc(sizeof(NODOL));
        strcpy(nuevo->nombre,nombre);
        printf("Ingresar puntaje LISTA\n");
        scanf("%d",&puntaje);
        fflush(stdin);
        nuevo->puntaje=puntaje;
        printf("Ingresar coincidencias LISTA\n");
        scanf("%d",&coincidencias);
        fflush(stdin);
        nuevo->coincidencias=coincidencias;
        nuevo->sub=NULL;
        nuevo->sig=*pl;
        *pl=nuevo;
        printf("Ingresar fichas SUBLISTA (*)F\n");
        while(scanf("%d",&fichas)){
            auxs=(TSUBLISTA)malloc(sizeof(TNODITO));
            auxs->fichas=fichas;
            auxs->sigs=nuevo->sub;
            nuevo->sub=auxs;
            printf("Ingresar fichas SUBLISTA (*)F\n");}
        fflush(stdin);
        printf("Ingresar nombre LISTA CTRLZ F\n");}
}

void cargacola(TCOLA *c){
    int n;
    iniciac(c);
    printf("Ingresar numeros COLA\n");
    while(scanf("%d",&n))
        ponec(c,n);
    fflush(stdin);
}
void muestracola(TCOLA c){
    int n;
    while(!vaciac(c)){
        sacac(&c,&n);
        printf("%d",n);}
}
