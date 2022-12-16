#include <stdio.h>

int main()
{
    printf("It's %zu bit void * \n", sizeof(void *)); 
    printf("It's %zu bit system \n", sizeof(void *) * 8); 
    return (0);
}
/** What C code can check whether the OS is 32 bit or 64 bit? 
 * 
 * How can I know how many bits my operating system has?
 * A byte contains 8 bits; but the size of (void *) depends on the operating system. 
 * So multiplying the bytes by 8 bits we get the total bits of the operating system.
 * 
 * ¿Como puedo saber cuántos bits tiene mi sistema operativo?
 * Un byte contiene 8 bits; pero el tamaño de (void *) depende del sistema operativo. 
 * Por lo que multiplicando los bytes por 8 bits obtenemos los bits totales 
 * del sistema operativo.
 * 
 * **/