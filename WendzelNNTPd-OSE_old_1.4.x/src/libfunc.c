/*
 * WendzelNNTPd is distributed under the following license:
 *
 * Copyright (c) 2004-2009 Steffen Wendzel <steffen (at) ploetner-it (dot) de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "main.h"

#if defined(__WIN32__) || defined(NOSUPPORT_STRNDUP)
char *
strndup(char *in, int len)
{
    char *out;
    
    out = (char *) calloc(len + 1, sizeof(char));
    if (!out)
       return NULL;
    strncpy(out, in, len);
    return out;
}
#endif

/* concatenate strings (at least two strings are needed, max. 5 strings
 * are supported). */

char *
str_concat(char *str1, char *str2, char *str3, char *str4, char *str5)
{
	char *out;
	size_t len;
	
	if (str1 == NULL || str2 == NULL) {
		DO_SYSL("error: str1==NULL || str2==NULL")
		return NULL;
	}
	
	len = strlen(str1) + strlen(str2)
		+ (str3 == NULL ? 0 : strlen(str3))
		+ (str4 == NULL ? 0 : strlen(str4))
		+ (str5 == NULL ? 0 : strlen(str5));
	
	out = (char *) calloc(len + 1, sizeof(char));
	if (!out)
		return NULL;
	
	strncpy(out, str1, strlen(str1));
	strncpy(out + strlen(out), str2, strlen(str2));
	if (str3) strncpy(out + strlen(out), str3, strlen(str3));
	if (str4) strncpy(out + strlen(out), str4, strlen(str4));
	if (str5) strncpy(out + strlen(out), str5, strlen(str5));
	
	return out;
}


