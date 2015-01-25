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

static void printHelloWorld()
{ 
    PDEBUG();
    printf("hello, world\r\n");
}

static void printFahrenheitCelsius(const i32 lower, const i32 upper, const u32 step)
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


static void printFahrenheitCelsiusFloat(const float lower, const float upper, const u32 step)
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

i32 main()
{
    PDEBUG();
    printHelloWorld();
    printFahrenheitCelsius(LOWER, UPPER, STEP);
    printFahrenheitCelsiusFloat(LOWER, UPPER, STEP);
    return 0;
}
