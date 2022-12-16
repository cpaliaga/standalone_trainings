/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_my_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caliaga- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:28:30 by caliaga-          #+#    #+#             */
/*   Updated: 2022/12/14 17:47:43 by caliaga-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

char *get_my_bits(unsigned char c)
{
	int octet[8];
	char *bits;
	int i;

	octet[0] = 1;
	octet[1] = 2;
	octet[2] = 4;
	octet[3] = 8;
	octet[4] = 16;
	octet[5] = 32;
	octet[6] = 64;
	octet[7] = 128;
	bits = malloc(9 * sizeof(char));
	if (!bits)
		return (NULL);
	i = -1;
	while (++i < 8)
	{
		if ((c & octet[i]) != 0)
			bits[i] = '1';
		else
			bits[i] = '0';
	}
	return(bits);
}

int main()
{
	unsigned char c = '*';
	char *bits = get_my_bits(c);
	int i = 0;
	while (i < 8)
		printf("%c", bits[i++]);
	printf("\n");

	return (0);
}
