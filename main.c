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
  int numero, pot,ban, val=0,option,cant;
  int ejercicio;
  int arreglosEnteros[DIM];
  srand(time(NULL));
  val = cargaArregloRandom(arreglosEnteros,val,DIM);

  do{
    system("cls");
    menu();
    printf("\nIngrese por teclado el ejercicio que quiere ver...\n");
    scanf("%i", &ejercicio);

    switch(ejercicio)
    {

    case 1:
    printf("\n Ingrese un numero\n");
    scanf("%d", &numero);
    printf("\n El factorial del numero %d es %d\n", numero,factorial(numero));
        break;
  case 2:
    printf("\nIngrese la potencia del numero \n");
    scanf("%d", &pot);
    printf("\n El numero %d elevado a la potencia %d es %d\n", numero,pot, potencia(numero,pot));
        break;
    case 3:
    mostrarArregloRecursivo(arreglosEnteros,val,0);
        break;
    case 4:
        mostrarArregloRecursivoInvertido(arreglosEnteros,val,0);
        break;
    case 5:
        ban = capicua(arreglosEnteros,val,0);
        if(ban==0)
        {
            printf("\nNo es capicua\n");
        }
        else
        {
            printf("\nEs capicua\n");
        }
        break;

    case 6:
        printf("\n La suma del arreglo es de %d:\n", sumaRecursiva(arreglosEnteros,val,0));
        break;

    case 7:
        printf("\n El menor del arreglo es %d\n", BuscarMenorRecursivo(arreglosEnteros,val,0));
        break;

    case 8:
        arreglo2archivoCompleto(arreglosEnteros,val);
        FILE*pArchInt =fopen(AR_ENTEROS, "r+b");
        muestraArchivoEntero();
        printf("\nEl menor del archivo de enteros es: %d\n", BuscarMenorArchiRecursivo(pArchInt));
        break;

    case 9:
        cant = cuentaEnterosArch(pArchInt);
        InvertirEnterosArch(pArchInt, 0, cant);
        muestraArchivoEntero();
        break;

    default:
        printf("\nOpcion Incorrecta\n");
    }
      printf("\nDesea Continuar? Presiones ESC para salir...");
      option = getch();
  } while(option!=ESC);

return 0;
}

void menu()
{
    printf("\n\t\t\t\t\tTRABAJO PRACTICO 3 - RECURSIVIDAD - PROGRAMACION II \n\n");
    printf("1. Calcular el factorial de un numero en forma recursiva.\n");
    printf("2. Calcular la potencia de un numero en forma recursiva\n");
    printf("3. Recorrer un arreglo y mostrarlo de forma recursiva\n");
    printf("4. Recorrer un arreglo comenzando desde la posicion 0 y mostrar sus elementos en forma invertida(recursivo)\n");
    printf("5. Determinar de forma recursiva si un arreglo es capicua\n");
    printf("6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el valor de la suma\n");
    printf("7. Buscar el menor elemento de forma recursiva\n");
    printf("8. Buscar el menor elemento de un archivo de numeros enteros de forma recursiva(desde el mismo archivo)\n");
    printf("9. Invertir los elementos de un archivo de numeros enteros de forma recursiva\n");
    printf("10.Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva\n");
    printf("11.Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso de forma recursiva. NO usar arreglos\n");
    printf("12.Determinar si un arreglo contiene un determinado elemento de forma recursiva.\n");


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

void arreglo2archivoCompleto(int a[], int v)
{
    FILE *pArchEnteros = fopen(AR_ENTEROS,"ab");
    if(pArchEnteros)
    {
        fwrite(a,sizeof(int),v,pArchEnteros);
        fclose(pArchEnteros);
    }
}

void muestraArchivoEntero()
{
    FILE*pArchEnteros =fopen(AR_ENTEROS, "rb");

    int num;

    if(pArchEnteros)
    {
        while(fread(&num,sizeof(int),1, pArchEnteros)>0)
        {
            printf("%d", num);
        }

        fclose(pArchEnteros);
    }
    printf("\n");
}

int BuscarMenorArchiRecursivo(FILE*pArchEntero)
{
   int menor, aux;

   if(fread(&aux, sizeof(int), 1,pArchEntero)==0)
   {
       fseek(pArchEntero, sizeof(int)*(-1), SEEK_END);
       fread(&menor, sizeof(int),1 , pArchEntero);
   }
   else
   {
       menor = BuscarMenorArchiRecursivo(pArchEntero);
       if(aux<menor)
       {
           menor=aux;
       }
   }
   return menor;
}

//EJERCICIO 9

int cuentaEnterosArch(FILE *pArchEnteros)
{
    int total= 0;

    fseek(pArchEnteros, 0, SEEK_END);
    total= ftell(pArchEnteros) / sizeof(int);

    return total;
}

void InvertirEnterosArch(FILE * pArchEnteros, int c, int u)
{
    int inicio, aux, fin;

    if(c<u)
    {
        fseek(pArchEnteros,c*sizeof(int), SEEK_SET);
        if(fread(&aux,sizeof(int),1,pArchEnteros)>0)
        {
            inicio = aux;
        }

        fseek(pArchEnteros,(u-1)*sizeof(int),SEEK_SET);
        if(fread(&aux,sizeof(int),1,pArchEnteros)>0)
        {
            fin= aux;
        }

        fseek(pArchEnteros,c*sizeof(int), SEEK_SET);
        fwrite(&fin, sizeof(int),1, pArchEnteros);
        fseek(pArchEnteros,(u-1)*sizeof(int),SEEK_SET);
        fwrite(&inicio,sizeof(int),1, pArchEnteros);

        InvertirEnterosArch(pArchEnteros,c+1,u-1);

    }
}
