#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int fd;
	int i;
	char *nbr[2000];
	int count;
	int part1;
	int part2;

	i = 0;
	fd = open("teste.txt", O_RDONLY);
	count = 0;
	while (count < 2000)
	{
		nbr[count] = get_next_line(fd);
		count ++;
	}
	nbr[count] = '\0';
 	while (nbr[i+1])
	{
		if (atoi(nbr[i]) < atoi(nbr[i+1]))
			part1++;
		i++;
	}
	i = 0;
	count = 0;
	while (nbr[i+3])
	{
		if ((atoi(nbr[i]) + atoi(nbr[i+1]) + atoi(nbr[i+2])) < (atoi(nbr[i+1]) + atoi(nbr[i+2]) + atoi(nbr[i+3])))
			part2++;
		i++;
	}
	return (printf("part1: %d\n", part1) && printf("part2: %d\n", part2));
}
