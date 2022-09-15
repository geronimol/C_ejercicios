#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "tdapilad.h"

typedef struct nodito{
    char nombre[20];
    int tiempo;
    struct nodito *sigs;}TNODITO;
typedef TNODITO *TSUBLISTA;

typedef struct nodol{
    char cod[5];
    float tiempo;
    int cant;
    TSUBLISTA sub;
    struct nodol *sig;}NODOL;
typedef NODOL *TLISTA;

void cargapila(TPILA *p);
void muestrapila(TPILA *p);
void cargalista(TLISTA *pl);
void muestralista(TLISTA lista);
void inserta(TSUBLISTA auxs,TELEMENTOP *a);

int main(void){
    TPILA p;
    TLISTA lista,aux;
    TELEMENTOP a;
    cargapila(&p);
    cargalista(&lista);

    while(!vaciap(p)){
        sacap(&p,&a);
        aux=lista;
        while(aux!=NULL && strcmp(a.codigo,aux->cod)){

            aux=aux->sig;}
        if(aux!=NULL && a.tiempo < aux->tiempo){
            inserta(lista->sub,&a);}
            }
    /*muestralista(lista);
    cargapila(&p);
    muestrapila(&p);*/
    return 0;}

void inserta(TSUBLISTA auxs,TELEMENTOP *a);{
    TSUBLISTA nuevo,ant,act;
    nuevo=(TSUBLISTA)malloc(sizeof(TNODITO));
    strcpy(nuevo->nombre,a.nombre);
    nuevo->tiempo=a.tiempo;
    if(auxs==NULL){
        nuevo->sigs=auxs;
        auxs=nuevo;}
    else{
        act=auxs;
        while(act!=NULL){
            ant=act;
            act=act->sigs;}
        ant->sigs=nuevo;
        nuevo->sigs=act;}
}

void muestralista(TLISTA lista){
    TSUBLISTA auxs;
    while(lista!=NULL){
        printf("[%s %10.2f %d]--> ",lista->cod,lista->tiempo,lista->cant);
        auxs=lista->sub;
        while(auxs!=NULL){
            printf("%s %d ",auxs->nombre,auxs->tiempo);
            auxs=auxs->sigs;}
        printf("\n");
        lista=lista->sig;}
}

void cargalista(TLISTA *pl){
    TLISTA nuevo;
    TSUBLISTA auxs;
    char cod[5],nom[20];
    int cant,tiem;
    float tiempo;
    *pl=NULL;
    printf("Ingresar cod deporte\n");
    while(gets(cod)!=NULL){
        nuevo=(TLISTA)malloc(sizeof(NODOL));
        strcpy(nuevo->cod,cod);
        printf("Ingresar tiempo promedio\n");
        scanf("%f",&tiempo);
        fflush(stdin);
        nuevo->tiempo=tiempo;
        printf("Ingresar cant deportistas\n");
        scanf("%d",&cant);
        fflush(stdin);
        nuevo->cant=cant;
        nuevo->sub=NULL;
        nuevo->sig=*pl;
        *pl=nuevo;
        printf("Ingresar nombre SUBLISTA \n");
        while(gets(nom)!=NULL){
            auxs=(TSUBLISTA)malloc(sizeof(TNODITO));
            strcpy(auxs->nombre,nom);
            printf("Ingresar tiempo SUBLISTA \n");
            scanf("%d",&tiem);
            fflush(stdin);
            auxs->tiempo=tiem;
            auxs->sigs=nuevo->sub;
            nuevo->sub=auxs;
            printf("Ingresar nombre SUBLISTA \n");}
        printf("Ingresar cod deporte\n");
        }
}


void muestrapila(TPILA *p){
    TELEMENTOP a;
    while(!vaciap(*p)){
        sacap(p,&a);
        puts(a.nombre);
        puts(a.codigo);
        printf("%d \n",a.tiempo);}
    }

void cargapila(TPILA *p){
    TELEMENTOP a;
    iniciap(p);
    printf("Ingresar nombre (PILA) CTRLZ F\n");
    while(gets(a.nombre)!=NULL){
        printf("Ingresa codigo (PILA)\n");
        gets(a.codigo);
        printf("Ingresar tiempo (PILA)\n");
        scanf("%d",&a.tiempo);
        fflush(stdin);
        ponep(p,a);
        printf("Ingresar nombre (PILA) CTRLZ F\n");}
}

