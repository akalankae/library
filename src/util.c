/*******************************************************************************
 * File name: /home/akalanka/.local/lib/personal/src/util.c
 * Author: Akalanka Edirisinghe <akalankae@gmail.com>
 * Created on: 25 Mar 24
 * Last modified: 31 Mar 24 01.31 PM
 * Description:
 ******************************************************************************/
#include <ctype.h>
#include <string.h>

/*
 * rstrip():
 *  strip whitespace characters from right side of the string.
 *
 * Returns pointer to beginning of the string
 */
char *const rstrip(char *const s)
{
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (!isspace(s[i]))
            break;

        s[i] = '\0';
    }
    return s;
}
