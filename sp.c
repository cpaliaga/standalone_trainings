#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_rows(char const *s, char c, size_t *rows, size_t *row)
{
	size_t	nb;
	size_t	i;

	row = 0;
	if (!s)
		return (0);
	i = -1;
	nb = 0;
	while (s[++i] != '\0')
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				nb++;
	if (nb == 0)
		return (0);
	else
		*rows = nb;
	return(1);
}

int main()
{
	size_t	rows;
	size_t	row;

	char *s01 = "             ";
	if (ft_rows(s01, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s02 = "0 0 0 0 0 0 0 0 0";
	if (ft_rows(s02, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s03 = "      split       this for   me  !       ";
	if (ft_rows(s03, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s04 = "                  olol";
	if (ft_rows(s04, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s05 = "olol                     ";
	if (ft_rows(s05, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s06 = "";
	if (ft_rows(s06, ' ', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);

	char *s07 = "\0aa\0bb";
	if (ft_rows(s07, '\0', &rows, &row) == 0)
		printf("Error en cadena ");
	printf("rows %zu row %zu \n", rows, row);
	return (0);
}
