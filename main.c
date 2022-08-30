
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define AR_ENTEROS "enteros.dat"

#define ESC 27
#define DIM 5

void menu();
int factorial(int x);
int potencia(int x, int y);
int cargaArregloRandom(int a[], int v, int dim);
void mostrarArregloRecursivo(int a[], int validos, int c);
void mostrarArregloRecursivoInvertido(int a[], int validos, int c);
int capicua(int a[], int u, int c);
int sumaRecursiva(int a[],int validos, int c);
int BuscarMenorRecursivo(int a[], int validos, int c);
void arreglo2archivoCompleto(int a[],int v);
void muestraArchivoEntero();
int BuscarMenorArchiRecursivo(FILE *pArchEnteros);
int cuentaEnterosArch(FILE*pArchEnteros);
void InvertirEnterosArch(FILE*pArchEnteros, int c,int u);

int main()
{



}

//EJERCICIO 1
int factorial(int x)
{
    int respuesta;

    if(x==0)
    {
        respuesta =1;
    }
    else{
        respuesta=x*factorial(x-1);
    }
    return respuesta;
}

//EJERCICIO 2
int potencia(int x, int y)
{
    int respuesta;

    if(y==1)
    {
        respuesta=x;
    }
    else{
        respuesta=x*potencia(x,(y-1));
    }

    return respuesta;
}

//EJERCICIO 3
int cargaArregloRandom(int a[], int v, int dim)
{
    for(; v<dim; v++)
    {
        a[v] = rand()%10;
    }

    return v;
}

void mostrarArregloRecursivo(int a[], int validos, int c)
{
    if(c<validos)
    {
        printf("%d -", a[c]);
        mostrarArregloRecursivo(a, validos,c+1);
    }
}

//EJERCICIO 4

void mostrarArregloRecursivoInvertido(int a[], int validos, int c)
{
    if(c<validos)
    {
        mostrarArregloRecursivoInvertido(a,validos, c+1);
        printf("%d - ", a[c]);
    }
}


//EJERCICIO 5

int capicua(int a[], int u, int c)
{
    int respuesta =1;

    if(c<u)
    {
        if(a[c]== a[u])
        {
            respuesta =capicua(a, c+1,u-1);
        }
        else
        {
            respuesta=0;
        }
    }

    return respuesta;
}

//EJERCICIO 6

int sumaRecursiva(int a[], int validos,int c)
{
    int suma =0;
    if(c<validos)
    {
        suma = a[c] + sumaRecursiva(a,validos,c+1);
    }
    return suma;
}


//EJERCICIO 7

int BuscarMenorRecursivo(int a[], int validos, int c)
{
    int menor;
    if(c== validos-1)
    {
        menor = a[c];
    }
    else{
        menor= BuscarMenorRecursivo(a, validos, c+1);
        if(a[c]<menor)
        {
            menor= a[c];
        }
    }
    return menor;
}

//EJERCICIO 8
