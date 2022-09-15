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
void ponelista(TLISTA *pl,TLISTA *l);

int main(void){
    TLISTA lista1,lista2,lista3=NULL,aux,cabeza;
    printf("Lista 1:\n");
    cargalista(&lista1);
    fflush(stdin);
    printf("Lista 2:\n");
    cargalista(&lista2);
    fflush(stdin);
    printf("Lista 1:\n");
    muestra(lista1);
    printf("Lista 2:\n");
    muestra(lista2);

    while(lista1!=NULL && lista2!=NULL){
        if(lista1->entero < lista2->entero){
            aux=lista1;
            lista1=lista1->sig;}
        else{
            aux=lista2;
            lista2=lista2->sig;}
        if(lista3==NULL)
            cabeza=aux;
        else
            lista3->sig=aux;
        lista3=aux;
            }
    if(lista1!=NULL){
        ponelista(&lista1,&lista3);}
            /*
            while(lista1!=NULL){
                aux=lista1;
                lista1=lista1->sig;
                aux->sig=lista3;
                lista3=aux;}}*/
    else{
        if(lista2!=NULL){
            ponelista(&lista2,&lista3);}
                /*
                while(lista2!=NULL){
                    aux=lista2;
                    lista2=lista2->sig;
                    aux->sig=lista3;
                    lista3=aux;}*/
        }

    printf("Lista 3:\n");
    muestra(cabeza);

    return 0;}

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
void ponelista(TLISTA *pl,TLISTA *l){
    TLISTA aux,act=*pl,sig=(*pl)->sig;
    while(*pl!=NULL){
                aux=*pl;
                *pl=(*pl)->sig;
                (*l)->sig=aux;
                *l=aux;}}
