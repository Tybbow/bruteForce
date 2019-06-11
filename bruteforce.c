/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tybbow <tybbow@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:17:59 by tybbow            #+#    #+#             */
/*   Updated: 2019/06/11 11:15:07 by tybbow           ###   ########.fr       */
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

void	bruteForcing(char *currentPwd, int len)
{
	for (const char *c = alphaNum; *c; ++c)
	{
		currentPwd[len] = *c;
		if (len < (strlen(currentPwd) - 1))
			bruteForcing(currentPwd, (len + 1));
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
	char *buffer = malloc((sizeof(char *) * atoi(av[1]) + 1));
	if (!buffer)
		return (0xDEAD);;
	memset(buffer, 'a', atoi(av[1]));
	buffer[atoi(av[1])] = 0;
	bruteForcing(buffer, 0);
	return (0xDEAD);
}
