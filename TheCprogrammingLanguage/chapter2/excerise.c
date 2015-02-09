/*************************************************************************
	> File Name: excerise.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Monday, February 09, 2015 PM09:53:22 HKT
 ************************************************************************/

#include<stdio.h>
#include "malloc.h"
#include "../../cbb/includes.h"

static int chapter_strlen(char *s)
{
    int i = 0;
    if (NULL == s)
        return 0;

    while(s[i] != '\0')
        ++i;
    return i;
}

static int chapter_atoi(char *s)
{
    int i = 0, n = 0;

    if (NULL == s)
        return 0;

    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10*n + (s[i] - '0');

    return n;
}

/*disadvantage is the s may be overflow*/
static int chapter_strcat(char *s, const char *d)
{
    int i = 0, j= 0;
    if ((NULL == s) || (NULL == d))
        return 0;

    while(s[i] != '\0')
        i++;
    /*very smart use for the string end of symbol \0 ,
     * instead of the first of the d character*/
    while((s[i++] = d[j++]) != '\0');
}

int main()
{
    int ret = 0;
    int sizeof_len = 0;
    char str[] = "chapter_strlen";
    char str_atoi[] = "1234";
    char str_src[] = "first";/*the array waste of memory*/
    char str_des[] = "second";

    PDEBUG();

    ret = chapter_strlen(str);
    VAR_DEBUG(ret);

    sizeof_len = sizeof(str);
    VAR_DEBUG(sizeof_len);

    ret = chapter_atoi(str_atoi);
    VAR_DEBUG(ret);

    str_src = realloc(sizeof(str_des));
    if (NULL == str_src) {
        CBB_ERR(str_src);
        return -1;
    }

    ret = chapter_strcat(str_src, str_des);
    DEBUG("%s \r\n", str_src);
}
