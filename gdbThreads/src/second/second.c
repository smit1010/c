/*************************************************************************
	> File Name: second.c
	> Author: xopenlee
	> Mail: 750haige@gmail.com
	> Created Time: Saturday, August 08, 2015 PM09:01:05 HKT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include <pthread.h>

pthread_mutex_t second_mutex = PTHREAD_MUTEX_INITIALIZER;
#define SECOND_MUTEX_LOCK() pthread_mutex_lock(&second_mutex)
#define SECOND_MUTEX_ULOCK() pthread_mutex_unlock(&second_mutex)

int second(void)
{
    while(1) {
        SECOND_MUTEX_LOCK();
        printf("###INFO: %s\r\n", __FILE__);
        usleep(1000);
        SECOND_MUTEX_ULOCK();
    }

    return 0;
}
