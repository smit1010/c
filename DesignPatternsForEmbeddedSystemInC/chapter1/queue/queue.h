/*************************************************************************
	> File Name: queue.h
	> Author: xOpenLee
	> Mail: 750haige@gmail.com 
	> Created Time: Wednesday, February 18, 2015 AM12:27:16 HKT
 ************************************************************************/

#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_SIZE 10

typedef struct Queue Queue;

struct Queue {
    int buffer[QUEUE_SIZE];
    int head;
    int size;
    int tail;
    int (*isFull)(Queue *const me);
    int (*isEmpty)(Queue *const me);
    int (*getSize)(Queue *const me);
    void (*insert)(Queue *const me, int k);
    int (*remove)(Queue *const me);
};

/*constructors and destructors*/
void Queue_Init(Queue *const me, 
    int (*isFull)(Queue *const me),
    int (*isEmpty)(Queue *const me),
    int (*getSize)(Queue *const me),
    void (*insert)(Queue *const me, int k),
   int (*remove)(Queue *const me));

void Queue_Cleanup(Queue *const me);

/*operations*/
int Queue_isFull(Queue *const me);
int Queue_isEmpty(Queue *const me);
int Queue_getSize(Queue *const me);
void Queue_insert(Queue *const me, int k);
int Queue_remove(Queue *const me);
Queue *Queue_create(void);
void Queue_Destory(Queue *const me);

#endif
