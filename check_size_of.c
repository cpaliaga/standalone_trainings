#include <stdio.h>
#include <stdint.h>

int main()
{
    printf ("El Tipo <char>         tiene un tamaño de %zd bytes\n", sizeof (char));    
    printf ("El Tipo <short int>    tiene un tamaño de %zd bytes\n", sizeof (short int));
    printf ("El Tipo <int>          tiene un tamaño de %zd bytes\n", sizeof (int));
    printf ("El Tipo <float>        tiene un tamaño de %zd bytes\n", sizeof (float));
    printf ("El Tipo <long>         tiene un tamaño de %zd bytes\n", sizeof (long));
    printf ("El Tipo <long long>    tiene un tamaño de %zd bytes\n", sizeof (long long));
    printf ("El Tipo <double>       tiene un tamaño de %zd bytes\n", sizeof (double));
    printf ("El Tipo <long double>  tiene un tamaño de %zd bytes\n", sizeof (long double));
    printf ("El Tipo <size_t>       tiene un tamaño de %zd bytes\n", sizeof (size_t));
    printf ("El Tipo <void *>       tiene un tamaño de %zd bytes\n", sizeof (void *));
    printf ("El Tipo <char *>       tiene un tamaño de %zd bytes\n", sizeof (char *));
    printf ("El Tipo <short int *>  tiene un tamaño de %zd bytes\n", sizeof (short int *));
    printf ("El Tipo <int *>        tiene un tamaño de %zd bytes\n", sizeof (int *));
    printf ("El Tipo <float *>      tiene un tamaño de %zd bytes\n", sizeof (float *));
    printf ("El Tipo <long *>       tiene un tamaño de %zd bytes\n", sizeof (long *));
    printf ("El Tipo <long long *>  tiene un tamaño de %zd bytes\n", sizeof (long long *));
    printf ("El Tipo <double *>     tiene un tamaño de %zd bytes\n", sizeof (double *));
    printf ("El Tipo <long double *>tiene un tamaño de %zd bytes\n", sizeof (long double *));
    printf ("La Constante <SIZE_MAX> de stdin tiene un tamaño de %zd bytes\n", sizeof (SIZE_MAX));
    return (0);
}
/**
 * size_t which is an 'unsigned int' and all pointer types (*)
 * they have the default size imposed by the operating system.
 * 
 * size_t que es un 'unsigned int' y todos los tipos de puntero (*) 
 * tienen el tamaño que por defecto les impone el sistema operativo.
 * 
 * https://clibre.io/blog/por-secciones/codigo/item/424-calcular-tamano-en-c-sizeof-strlen-uso-y-errores-comunes
 * **/