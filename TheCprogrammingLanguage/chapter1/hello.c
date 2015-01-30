/*************************************************************************
	> File Name: hello.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Sunday, January 25, 2015 PM03:27:03 HKT
 ************************************************************************/

#include "../../cbb/includes.h"

#define LOWER 0
#define UPPER 300
#define STEP 20

#define OUT 1
#define IN 0
#define MAX_LINE 1000

static void print_hello_world()
{
    PDEBUG();
    printf("hello, world\r\n");
}

static void print_fahrenheit_celsius(const i32 lower, const i32 upper, const u32 step)
{
    i32 fahr = 0, c = 0;

    /*文中用while循环来控制，对比for来看，将循环条件的比较和改变分离不同的行，不利于阅读和理解*/
    for (fahr = lower; fahr <= upper; fahr += step)
    {
        /*think about 5/9 * (fahr -32), any fractional is discared*/
        c = 5 * (fahr -32) / 9;
        /*use %3d three digital width instead \t*/
        printf("###INFO: Fahrenheit = %d,\tCelsius = %d\r\n", fahr, c);
    }
}


static void print_fahrenheit_celsius_float(const float lower, const float upper, const u32 step)
{
    float fahr = 0, c = 0;

    for (fahr = lower; fahr <= upper; fahr += step)
    {
        /*it can use 5.0/9.0*/
        c = 5.0/9.0 * (fahr -32.0);
        /*3.0f print least three character wide , no decimal*/
        printf("###INFO: Fahrenheit = %3.0f,\tCelsius = %6.1f\r\n", fahr, c);
    }
}
static u8 file_copy()
{
    i32 input = 0;
    /*-1*/
    printf("EOF = %d\r\n", EOF);
    /*if you want to break, tap CTRL + d*/
    for( ; (input = getchar()) != EOF; putchar(input));
}

static void word_count()
{
    int c, nl, nw, nc, state;

    state = OUT;
    c = nl = nw = nc = 0;

    while((c = getchar()) != EOF)
    {
        ++nc;
        if ('\n' == c)
            ++nl;
        if (' ' == c || '\n' == c || '\t' == c)
            state = OUT;
        else if (OUT == state)
        {
            state = IN;
            ++nw;
        }
    }
    printf("###INFO: line = %d, word = %d, character = %d \r\n", nl, nw, nc);
}

static void array()
{
    i32 c = 0, i = 0, nwhite = 0, nother = 0;
#define DIGIAL_NUM 10
    i32 ndigit[DIGIAL_NUM];
    /*memset have a return pointer, return the firset n of ndigit*/
    memset(ndigit, 0x00, DIGIAL_NUM*sizeof(i32));

    while ((c = getchar()) != EOF)
    {
        if ('0' <= c && '9' >= c)
            /*smart*/
            ++ndigit[c - '0'];
        else if (' ' == c || '\n' == c || '\t' == c)
            ++nwhite;
        else
            ++nother;
    }

    for (i = 0; i < DIGIAL_NUM; i++)
        printf("digital %d has %d \r\n", i, ndigit[i]);
    printf("###INFO: white space = %d, other = %d\r\n", nwhite, nother);
}

static i32 power(const i32 base, u32 n)
{
    PDEBUG();
    if(0 == n)
        return 1;

    return power(base, --n)*base;
}

static int getline(char *s, const i32 lim)
{
    i32 c = 0, i = 0;
    if (NULL == s)
        return 0;

    /*for safe: i < lim -1*/
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
       s[i] = c;
    if (c == '\n') {
       s[i] = c;
        ++i;
    }

    s[i] = '\0';/*the null character, whose value is zero*/
    printf("###INFO: %s\r\n", s);
    return i;
}

static void copy(char *to, const char *from)
{
    if ((NULL == to) || (NULL == from))
        return;

    while((*to++ = *from++) != '\0');
}

i32 main()
{
    i32 ret = 0;
    i32 len = 0, max = 0;

    char line[MAX_LINE] = {0,};
    char longest[MAX_LINE] = {0,};

    PDEBUG();
#ifdef SHOW_PASS
    print_hello_world();
    print_fahrenheit_celsius(LOWER, UPPER, STEP);
    print_fahrenheit_celsius_float(LOWER, UPPER, STEP);
    file_copy();
    word_count();
    array();
    VAR_DEBUG(ret);
    ret = power(2, 5);
#endif

    while ((len = getline(line, max_line)) > 0) {
        if (len > max) { 
            printf("###info: the line %s\r\n", line);
            max = len;
            copy(longest, line);
            printf("###info: the longest %s\r\n", longest);
        }
    }

    return 0;
}
