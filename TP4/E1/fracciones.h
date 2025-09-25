typedef struct
{
    int num, den;
} Tfracc;
Tfracc crear(int a, int b);
int denominador(Tfracc frac);
int numerador(Tfracc frac);
Tfracc sumar(Tfracc f1, Tfracc f2);
Tfracc restar(Tfracc f1, Tfracc f2);
Tfracc multiplicar(Tfracc f1, Tfracc f2);
Tfracc dividir(Tfracc f1, Tfracc f2);
Tfracc simplificar(Tfracc f1);
int iguales(Tfracc f1, Tfracc f2);
