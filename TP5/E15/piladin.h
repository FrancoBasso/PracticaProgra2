typedef char TElementoP[20];
typedef struct nodop
{
    TElementoP dato;
    struct nodop *sig;
} nodop;
typedef nodop *TPila;
void poneP(TPila *P, TElementoP x);
void sacaP(TPila *P, TElementoP *x);

int VaciaP(TPila P);
void IniciaP(TPila *P);