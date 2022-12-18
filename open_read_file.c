# include <stdio.h>
# include <stdlib.h>
/* Dependencias para read() y close() */
# include <unistd.h>
/* Dependencias para open() */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
/* Dependencias para SIZE_MAX*/
# include <stdint.h>

# define BUFF_SIZE 200

char	*read_a_file(char *url)
{
	int		fd;
	ssize_t	read_bytes;
	char	*buff;

    /** CREATE A MALLOC WITH BEHAVIOR CONTROL **/
	/** CREAR UN MALLOC CON CONTROL DEL COMPORTAMIENTO **/
	if ((BUFF_SIZE * sizeof(char)) > SIZE_MAX)
		return (NULL);
	buff = malloc (BUFF_SIZE + 1 * sizeof(char));
	if (!buff)
		return (NULL);
	
    /** OPEN THE FILE **/
	/** ABRIR EL ARCHIVO **/
	fd = open((char *)url, O_RDONLY);
	if (fd == -1)
		return (NULL);
	//printf("File descriptor %d\n", fd);
    
	/** READ THE FILE AND PUT THE CONTENT IN MALLOC **/
	/** LEER EL ARCHIVO Y PONER EL CONTENIDO EN MALLOC **/
	read_bytes = read(fd, buff, BUFF_SIZE);
    
    /** CLOSE THE STRING ​**/
	/** CIERRAS LA CADENA **/
	buff[read_bytes + 1] = '\0';
	//printf("Bytes leidos %zu\n", read_bytes);
	
	/** CLOSE THE FILE **/
    /** CERRAR EL ARCHIVO **/
	if (close (fd) == -1)
		return (NULL);
	
	return (buff);
}

int main()
{
	char url[] = "quijote.txt";
	char *r = read_a_file(url);
    printf("%s \n", r);
	r = NULL;
	free(r);
    return 0;
}

/**
 * No hay un límite fijo para el tamaño de una matriz en C.
 * El tamaño de cualquier objeto individual, incluido cualquier objeto de matriz, 
 * está limitado por SIZE_MAX, el valor máximo de tipo size_t, que es el resultado 
 * del operador sizeof. (No está del todo claro si el estándar C permite objetos de 
 * más de SIZE_MAX bytes, pero en la práctica dichos objetos no son compatibles; 
 * consulte la nota al pie). Dado que SIZE_MAX está determinado por la implementación 
 * y no puede ser modificado por ningún programa, eso impone un límite superior de 
 * SIZE_MAX bytes para cualquier objeto individual. (Ese es un límite superior, no un 
 * límite superior mínimo; las implementaciones pueden, y normalmente lo hacen, imponer 
 * límites más pequeños).
 * El ancho del tipo void*, un tipo de puntero genérico, impone un límite superior al 
 * tamaño total de todos los objetos en un programa en ejecución (que puede ser mayor 
 * que el tamaño máximo de un solo objeto).
 * El estándar C impone límites inferiores, pero no superiores, a estos tamaños fijos. 
 * Ninguna implementación C conforme puede admitir objetos de tamaño infinito, 
 * pero en principio puede admitir objetos de cualquier tamaño finito. 
 * Los límites superiores los imponen las implementaciones individuales de C, 
 * los entornos en los que operan y la física, no el lenguaje.
 * For example, a conforming implementation could have SIZE_MAX equal to 21024-1, 
 * which means it could in principle have objects up to 179769313486231590772930519078902473
 * 3617976978942306572734300811577326758055009631327084773224075360211201138798713933576587
 * 8976881441662249284743063947412437776789342486548527630221960124609411945308295208500576
 * 8838150682342462881473913110540827237163350510684586298239947245938479716304835356329624
 * 224137215 bytes.
 * Buena suerte para encontrar hardware que realmente admita dichos objetos.
 * Nota al pie: No existe una regla explícita de que ningún objeto puede ser más grande que 
 * SIZE_MAX bytes. No podría aplicar útilmente el operador sizeof a dicho objeto, pero 
 * como cualquier otro operador, sizeof puede desbordarse; eso no significa que no pueda 
 * realizar operaciones en dicho objeto. Pero en la práctica, cualquier implementación 
 * sensata hará que size_t sea lo suficientemente grande como para representar el tamaño de 
 * cualquier objeto que admita.
 * **/
/**
 * There is no fixed limit to the size of an array in C.
 * The size of any single object, including of any array object, is limited by SIZE_MAX,
 * the maximum value of type size_t, which is the result of the sizeof operator.
 * (It's not entirely clear whether the C standard permits objects larger than SIZE_MAX 
 * bytes, but in practice such objects are not supported; see footnote.) Since SIZE_MAX 
 * is determined by the implementation, and cannot be modified by any program, that imposes 
 * an upper bound of SIZE_MAX bytes for any single object. (That's an upper bound, 
 * not a least upper bound; implementations may, and typically do, impose smaller limits.)
 * The width of the type void*, a generic pointer type, imposes an upper bound on the 
 * total size of all objects in an executing program (which may be larger than the 
 * maximum size of a single object).
 * The C standard imposes lower bounds, but not upper bounds, on these fixed sizes. 
 * No conforming C implementation can support infinite-sized objects, but it can in 
 * principle support objects of any finite size. Upper bounds are imposed by individual 
 * C implementations, by the environments in which they operate, and by physics, not by the 
 * language.
 * For example, a conforming implementation could have SIZE_MAX equal to 21024-1, 
 * which means it could in principle have objects up to 1797693134862315907729305190789024733617
 * 976978942306572734300811577326758055009631327084773224075360211201138798713933576587897688144
 * 166224928474306394741243777678934248654852763022196012460941194530829520850057688381506823424
 * 62881473913110540827237163350510684586298239947245938479716304835356329624224137215 bytes.
 * Good luck finding hardware that actually supports such objects.
 * Footnote: There is no explicit rule that no object can be bigger than SIZE_MAX bytes. 
 * You couldn't usefully apply the sizeof operator to such an object, 
 * but like any other operator, sizeof can overflow; that doesn't mean you couldn't perform operations 
 * on such an object. But in practice, any sane implementation will make size_t 
 * big enough to represent the size of any object it supports.*/
/**There's nothing in the standard that forbids objects bigger than SIZE_MAX bytes, 
 * but in practice any reasonable implementation that can support objects bigger than, say, 
 * 2**32 bytes will make size_t wider than 32 bits. An implementation that lets you 
 * define such large objects but doesn't bother to make size_t big enough to hold their 
 * size might be conforming, but it would be perverse.  */
/*https://stackoverflow.com/questions/9386979/what-is-the-maximum-size-of-an-array-in-c*/