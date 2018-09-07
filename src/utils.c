#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "utils.h"

/* ===== Concatenation of many strings ===== */

char* concat(int n_token, char *sep, char *token,...)
{
	int i;
	va_list vl;
	va_start(vl,token);

	char *concatenated = token;
	for(i=1; i<n_token; i++)
	{
		concatenated = strcat(strcat(concatenated,sep),va_arg(vl,char *));
	}

	va_end(vl);
	return concatenated;
}
