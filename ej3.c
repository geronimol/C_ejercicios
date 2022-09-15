#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct nodo{
    int entero;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

void cargalista(TLISTA *pl);
void muestra(TLISTA lista);

int main(void){
    TLISTA lista,par=NULL,impar=NULL,act,sig,ant;
    int i=0;
    printf("Ingresar numeros enteros. (*)Finalizar\n");
    cargalista(&lista);

    while(lista!=NULL){
        act=lista; sig=act->sig;
        if(act->entero%2==0){
            if(i==0){
                i++;
                par=act;}
            else{
                ant->sig=act;}
            act->sig=NULL;
            ant=act;}
        else
            {act->sig=impar;
                impar=act;}
        lista=sig;
    }

    printf("PARES\n");
    muestra(par);
    printf("IMPARES\n");
    muestra(impar);
    return 0;
    }

void cargalista(TLISTA *pl){
    TLISTA nuevo;
    int n;
    *pl=NULL;
    while(scanf("%d",&n)){
        nuevo=(TLISTA)malloc(sizeof(NODO));
        nuevo->entero=n;
        nuevo->sig=*pl;
        *pl=nuevo;}
    }
void muestra(TLISTA lista){
    while(lista!=NULL){
        printf("%d\n",lista->entero);
        lista=lista->sig;}
    }
