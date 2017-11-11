#include "fillit.h"

char *ft_realloc(char *str, int size)
{
	char *nstr;
	if (!(nstr = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	ft_memcpy(nstr, str, --size);
	return (nstr);
}
