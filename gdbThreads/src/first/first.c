/*************************************************************************
	> File Name: first.c
	> Author: xopenlee
	> Mail: 750haige@gmail.com
	> Created Time: Saturday, August 08, 2015 PM09:01:05 HKT
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t first_mutex = PTHREAD_MUTEX_INITIALIZER;
#define FIRST_MUTEX_LOCK() pthread_mutex_lock(&first_mutex)
#define FIRST_MUTEX_ULOCK() pthread_mutex_unlock(&first_mutex)


extern pthread_mutex_t second_mutex ;
int first(void)
{
    while(1) {
        FIRST_MUTEX_LOCK();
        printf("###INFO: %s\r\n", __FILE__);
        usleep(500000);
        FIRST_MUTEX_ULOCK();
    }
    return 0;
}
