#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct nodo{
    int n;
    struct nodo *sig;}NODO;
typedef NODO *TLISTA;

void leevec(int a[], int *n);
void escvec(int v[], int n);
void cargalista(TLISTA *pl);
void muestra(TLISTA lista);
void insertal(TLISTA *pl, int elem);
void inserta(TLISTA *lista, int v[], int n);


int main(void){
    TLISTA lista;
    int v[20],n;
    cargalista(&lista);
    leevec(v,&n);
    inserta(&lista,v,n);
    printf("Resultadooooo!\n");
    muestra(lista);
    /*escvec(v,n);*/
    return 0;
}

void inserta(TLISTA *lista, int v[], int n){
    int i;
    for(i=0;i<n;i++)
        insertal(lista,v[i]);}

void insertal (TLISTA *pl, int elem){
    TLISTA nuevo, ant, act ;
    nuevo= (TLISTA)malloc(sizeof(NODO));
    nuevo->n=elem;
    if (*pl == NULL || (*pl)->n > elem) /*inserta principio*/{
        nuevo->sig = *pl; *pl= nuevo;}
    else{
        act= *pl;
        while (act != NULL && elem > act->n)/*inserta en el medio o al final*/{
            ant = act ; act = act->sig;}
        ant->sig = nuevo;
        nuevo->sig = act;}
}

void muestra(TLISTA lista){
    while(lista!=NULL){
        printf("%d\n",lista->n);
        lista=lista->sig;}
}

void cargalista(TLISTA *pl){
    TLISTA nuevo;
    int n;
    *pl=NULL;
    printf("Ingresar numeros para la lista (*)=F\n");
    while(scanf("%d",&n)){
        nuevo=(TLISTA)malloc(sizeof(NODO));
        nuevo->n=n;
        nuevo->sig=*pl;
        *pl=nuevo;}
    fflush(stdin);
    }

void leevec(int a[], int *n){
    int i;
    printf("Ingresar cant elem vector\n");
    scanf("%d",n);
    for(i=0;i<*n;i++){
        printf("Ingrese el elemento %d\n",i+1);
        scanf("%d",&a[i]);}
    }
void escvec(int v[], int n){
    int i;
    for (i=0;i<n;i++)
        printf("Elemento %d: %d\n",i+1,v[i]);
    }
