#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nodito{
    float x;
    struct nodito *sigs;}TNODITO;
typedef TNODITO *TSUBLISTA;

typedef struct nodo{
    float a,b;
    TSUBLISTA sub;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

void cargalista(TLISTA *pl);
void muestra(TLISTA lista);

int main(void){
    TLISTA lista;
    cargalista(&lista);
    muestra(lista);
    return 0;
}

void muestra(TLISTA lista){
    TSUBLISTA auxs;
    while(lista!=NULL){
        printf("[%6.2f %6.2f]---->",lista->a,lista->b);
        auxs=lista->sub;
        while(auxs!=NULL){
            printf("%6.2f",auxs->x);
            auxs=auxs->sigs;}
        printf("\n");
        lista=lista->sig;
    }
}

void cargalista(TLISTA *pl){
    TLISTA aux;
    TSUBLISTA auxs;
    float a,b,x;
    *pl=NULL;
    printf("Ingresar intervalo de reales (*) Finalizar\n");
    while(scanf("%f %f",&a,&b)){
        aux=(TLISTA)malloc(sizeof(NODO));
        aux->a=a; aux->b=b;
        aux->sub=NULL; aux->sig=*pl;*pl=aux;
        printf("Ingresar reales sublista (*) finalizar\n");
        while(scanf("%f",&x)){
            auxs=(TSUBLISTA)malloc(sizeof(TNODITO));
            auxs->x=x;
            auxs->sigs=aux->sub;
            aux->sub=auxs;
            printf("Ingresar reales sublista (*) finalizar\n");}
        fflush(stdin);
        printf("Ingresar intervalo de reales (*) Finalizar\n");}
    }
