/*************************************************************************
	> File Name: main.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Wednesday, February 18, 2015 AM01:04:27 HKT
 ************************************************************************/

#include<stdio.h>
#include "queue.h"

int main(void)
{
    int j, k, h, t;
    Queue *myQ = NULL;
    myQ = Queue_create();
    k = 1000;

    for (j = 0; j < QUEUE_SIZE; j ++) {
        h = myQ->head;
        myQ->insert(myQ, k);
        printf("#info: insert %d at position %d size = %d\r\n\
                ", k--, h, myQ->getSize(myQ));
    }

    printf("#info: queue size = %d\r\n", myQ->getSize(myQ));
    for (j = 0; j < QUEUE_SIZE; j ++) {
        t = myQ->tail;
        myQ->remove(myQ);
        printf("#info: remove %d at position %d size = %d\r\n\
                ", k--, t, myQ->getSize(myQ));
    }

    return 0;
}
