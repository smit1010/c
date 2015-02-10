/*************************************************************************
	> File Name: excerise.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Monday, February 09, 2015 PM09:53:22 HKT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
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

static u32 next_rand = 1;

static void chapter_set_seed_for_rand(u32 seed)
{
    next_rand = seed;
}
static int chapter_rand(void)
{
    u32 next_rand = next_rand * 1103515245  + 12345;
    return (unsigned int )(next_rand >> 16) % 32768;
}

static void chapter_disp_rand()
{
    u32 ret = 0;
    chapter_set_seed_for_rand(156);
    while(1) {
         ret = chapter_rand();
         VAR_DEBUG(ret);
    }
}

static u32 get_bits(u32 x, int start_bit, int bit_num)
{
    return (x >> (start_bit + 1 -bit_num))&(~(~0<<bit_num));
}
int main()
{
    int ret = 0;
    int sizeof_len = 0;
    char str[] = "chapter_strlen";
    char str_atoi[] = "1234";
    char str_src[100] = "first";/*the array waste of memory*/
    char str_des[] = "second";
    u32 get_bit = 0x17;
#define OCT_DIG '\123'
    printf("OCT_DIG = %d\r\n", OCT_DIG);
#define HEX_DIG '\xAB'
    printf("HEX_DIG = 0x%x\r\n", HEX_DIG);

    PDEBUG();

    ret = chapter_strlen(str);
    VAR_DEBUG(ret);

    sizeof_len = sizeof(str);
    VAR_DEBUG(sizeof_len);

    ret = chapter_atoi(str_atoi);
    VAR_DEBUG(ret);


    ret = chapter_strcat(str_src, str_des);
    DEBUG("%s \r\n", str_src);

    ret = get_bits(get_bit, 3, 2);
    VAR_DEBUG(ret);

}
