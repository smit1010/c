/*************************************************************************
	> File Name: main.c
	> Author: xopenlee
	> Mail: 750haige@gmail.com
	> Created Time: Monday, August 10, 2015 PM08:33:35 HKT
 ************************************************************************/

#include<stdio.h>

#include "first.h"
#include "second.h"
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int ret = 0;
    pthread_t thread_idA, thread_idB;

    printf("#INFO: %s\r\n", __FILE__);
    
    if (( ret = pthread_create(&thread_idA, NULL, (void*)&first, NULL)) != 0) {
        printf("###ERR: thread_idA ret = %d\r\n", ret);
        return -1;
    }
    
    if (( ret = pthread_create(&thread_idB, NULL, (void*)&second, NULL)) != 0) {
        printf("###ERR: thread_idB ret = %d\r\n", ret);
        return -2;
    }

    if(pthread_join(thread_idA, &ret) != 0){
        printf("###ERR: pthread_join err\r\n");
        return -3;
    }

    if(pthread_join(thread_idB, &ret) != 0){
        printf("###ERR: pthread_join err\r\n");
        return -3;
    }

    return 0;
}
