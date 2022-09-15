#include "tdapilad.h"
#include <stdio.h>
void iniciap(TPILA *p)
    {
    *p=NULL;
    }
int vaciap(TPILA pila)
    {
     return pila==NULL;
    }

void ponep(TPILA *p, TELEMENTOP elem)
    {
     TPILA nuevo;
     nuevo= (TPILA)malloc(sizeof(NODOP));
     nuevo->sig= *p; nuevo->dato=elem;
     *p=nuevo;
    }


void sacap(TPILA *p, TELEMENTOP *pelem)
    {
     TPILA aux;
     *pelem= (*p)->dato;    aux= *p;
     *p=(*p)->sig; free(aux);
    }



void consultap(TPILA pila, TELEMENTOP *pelem)
    {
     if(pila != NULL)
        *pelem= pila->dato;
    }
