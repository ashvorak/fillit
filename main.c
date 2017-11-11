/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurok <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:25:37 by amazurok          #+#    #+#             */
/*   Updated: 2017/09/12 17:06:52 by amazurok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_error(void)
{
	ft_putstr("error\n");
	exit (1);
}
/*
int		elem_size(char *str)
{
	int	i;
	int num;

	i = 0;
	num = 0;
	while (str[i])
		if (str[i] == "\n" && str[i + 1] == "\n")
			num++;
		else if (str[i] == "\n" && str[i + 1] == "\0")
			num++;
	return (num);
}
*/

void	check_str(char *str)
{
	int w;
	int h;

	w = 1;
	h = 1;
	while (*str)
	{
		((*str != '.' && *str != '#' && *str != '\n') ? ft_error() : 0);
		((w == 5 && *str != '\n') ? ft_error() : 0);
		((w == 5 && h == 4) && (*(str + 1) != '\n') ? ft_error() : 0);
		if (w == 5 && h == 4)
		{
			w = 1;
			h = 1;
			str++;
		}
		else if (w == 5 && h != 4)
		{
			w = 1;
			h++;
		}
		else
			w++;
		str++;
	}
}

char	*ft_read(int argc, char *file_name)
{
	int		i;
	int		fd;
	int		size;
	char	buf[1];
	char	*str;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		if ((fd = open(file_name, O_RDONLY)) == -1)
			ft_error();
		while (read(fd, buf, 1))
		{
			str = ft_realloc(str, size++);
			str[i++] = buf[0];
		}
		close(fd);
		return (str);
	}
	return (NULL);
}

int		main(int argc, char *argv[])
{
	char	*str;

	str = ft_read(argc, argv[1]);
	check_str(str);
	printf("%s\n", str);
	return (0);
}
