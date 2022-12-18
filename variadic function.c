#include <stdio.h>
#include <stdarg.h>  /* va_list */

double suma (int n, ...)
{
    int i;
    double s, valor;
    va_list parametros;
    va_start(parametros, n);
    s = 0.0;
    while(i<n)
    {
        valor = va_arg(parametros, double);
        s += valor;
        i++;
    }
    va_end(parametros);
    return (s);
}

int main(void)
{
    double x;
    x = suma(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    printf("%lf \n", x);
    return (0);
}
/* Tutorial de Funciones Variádicas en Lenguaje C   https://www.youtube.com/watch?v=aTMuksnK32U*/
/* Variadic Functions: Variable parameters in a function - C course STEP by STEP (29)  
https://www.youtube.com/watch?v=XdRSseBIj-c */