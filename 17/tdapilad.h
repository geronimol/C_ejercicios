typedef struct TELEMENTOP{
    char nombre[20];
    char codigo[5];
    int tiempo;
    }TELEMENTOP;
typedef  struct{
    TELEMENTOP dato ;
    struct nodop *sig;}NODOP;
typedef  NODOP  *TPILA;
void iniciap(TPILA *p);
int vaciap(TPILA pila);
int llenap(TPILA pila);
void ponep(TPILA *p, TELEMENTOP elem);
void sacap(TPILA *p, TELEMENTOP *pelem);
void consultap(TPILA pila, TELEMENTOP *pelem);
