/*************************************************************************
	> File Name: queue.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com 
	> Created Time: Wednesday, February 18, 2015 AM12:39:32 HKT
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include "queue.h"
void Queue_Init(Queue *const me, 
    int (*isFull)(Queue *const me),
    int (*isEmpty)(Queue *const me),
    int (*getSize)(Queue *const me),
    void (*insert)(Queue *const me, int k),
    int (*remove)(Queue *const me)) {
    
    if(NULL == me)
        return;

    me->head = 0;
    me->size = 0;
    me->tail = 0;

    me->isFull = isFull;
    me->isEmpty = isEmpty;
    me->getSize = getSize;
    me->insert = insert;
    me->remove = remove;
}

void Queue_Cleanup(Queue *const me) {
    
}

int Queue_isFull(Queue *const me) {
    return ((me->head + 1) % QUEUE_SIZE == me->tail);
}

int Queue_isEmpty(Queue *const me) {
    return (me->head == me->tail);
}

int Queue_getSize(Queue *const me) {
    return me->size;
}

void Queue_insert(Queue *const me, int k) {
    if (!me->isFull(me)) {
        me->buffer[me->head] = k;
        me->head = (me->head + 1) % QUEUE_SIZE;
        me->size ++;
        printf("size = %d\r\n", me->size);
        printf("head = %d\r\n", me->head);
        printf("tail = %d\r\n", me->tail);
    }
}

int Queue_remove(Queue *const me) {
    int value = -9999;
    if (!me->isEmpty(me)) {
        value = me->buffer[me->tail];
        me->tail = (me->tail + 1) % QUEUE_SIZE;
        --me->size;
    }

    return value;
}

Queue *Queue_create(void) {
    Queue *me = (Queue*) malloc (sizeof(Queue));
    if (NULL != me){
        Queue_Init(me, Queue_isFull, Queue_isEmpty, Queue_getSize, \
                Queue_insert, Queue_remove);
    }
    return me;
}

void Queue_Destroy(Queue *const me) {
    if (me != NULL) {
        Queue_Cleanup(me);
    }
    free(me);
}

