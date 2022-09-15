#include "tdapila.h"
void iniciap(TPILA *p)
{
   p->tope=0;
};
int vaciap(TPILA pila)
{
    return pila.tope==0;
};
int llenap(TPILA pila)
{
     return pila.tope==MAXPILA;
};
void ponep(TPILA *p, TELEMENTOP elem)
{

    p->vp[(p->tope)++]=elem;
};
void sacap(TPILA *p, TELEMENTOP *pelem)
{
    --(p->tope);
    *pelem= p->vp[ p->tope];
};
void consultap(TPILA pila, TELEMENTOP *pelem)
{
    *pelem= pila.vp[pila.tope -1];
};
