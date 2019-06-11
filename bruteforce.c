/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tybbow <tybbow@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:17:59 by tybbow            #+#    #+#             */
/*   Updated: 2019/06/11 11:53:15 by tybbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define u_char unsigned char
#define GRN "\x1B[32m"
#define RST "\x1B[0m"

const	char alphaNum[] = {
	"abcdefghijklmnopqrstuvwxyz"
	"0123456789"
};

void	bruteForcing(u_char *currentPwd, int depth, int length)
{
	for (const char *c = alphaNum; *c; ++c)
	{
		currentPwd[depth] = *c;
		if (depth < (length - 1))
			bruteForcing(currentPwd, (depth + 1), length);
		printf(GRN "[!]" RST " Testing Password: %s\n", currentPwd);
	}
}

int		usage()
{
	printf("Usage : bruteForce v1.0 by Tybbow\n");
	printf("\tbruteforce (int) - int est la longueur de la chaine\n");
	printf("\tExemple : bruteforce 5\n");
	return (0xDEAD);
}
int		main(int ac, char **av)
{
	if (ac != 2 || !atoi(av[1]))
		return (usage());
	u_char *buffer = malloc((sizeof(u_char *) * atoi(av[1]) + 1));
	if (!buffer)
		return (0xDEAD);;
	memset(buffer, 'a', atoi(av[1]));
	buffer[atoi(av[1])] = 0;
	bruteForcing(buffer, 0, atoi(av[1]));
	return (0xDEAD);
}
