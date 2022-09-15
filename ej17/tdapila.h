#define MAXPILA   100
typedef struct {
    char palabra[20];}TELEMENTO;
typedef struct TELEMENTO *TELEMENTOP;

typedef  struct{
    TELEMENTOP vp[MAXPILA] ;
    int tope;}TPILA;
void iniciap(TPILA *p);
int vaciap(TPILA pila);
int llenap(TPILA pila);
void ponep(TPILA *p, TELEMENTOP elem);
void sacap(TPILA *p, TELEMENTOP *pelem);
void consultap(TPILA pila, TELEMENTOP *pelem);
