/*************************************************************************
	> File Name: CachedQueue.h
	> Author: xOpenLee
	> Mail: 750haige@gmail.com 
	> Created Time: Friday, February 20, 2015 AM09:15:22 HKT
 ************************************************************************/

#ifndef _CACHEDQUEUE_H
#define _CACHEDQUEUE_H
#include "queue.h"

typedef struct CachedQueue CachedQueue;

struct CachedQueue {
    Queue *queue;
    char filename[80];
    int numberElemementOnDisk;
    Queue *outputQueue;

    int (*isFull)(CachedQueue *const me);
    int (*isEmpty)(CachedQueue *const me);
    int (*getSize)(CachedQueue *const me);
    void (*insert)(CachedQueue *const me, int k);

    void (*remove)(CachedQueue *const me);
    void (*flush)(CachedQueue *const me);
    void (*load)(CachedQueue *const me);
};

void CachedQueue_Init(CachedQueue *const me, char *fName,
    int (*isFull)(CachedQueue *const me),
    int (*isEmpty)(CachedQueue *const me),
    int (*getSize)(CachedQueue *const me),
    void (*insert)(CachedQueue *const me, int k),
    void (*remove)(CachedQueue *const me),

    void (*flush)(CachedQueue *const me),
    void (*load)(CachedQueue *const me));

void CachedQueue_Cleanup(CachedQueue *const me);

int CachedQueue_isFull(CachedQueue *const me);
int CachedQueue_isEmpty(CachedQueue *const me);
int CachedQueue_getSize(CachedQueue *const me);
int CachedQueue_remove(CachedQueue *const me);
int CacheddQueue_flush(CachedQueue *const me);
int CachedQueue_load(CachedQueue *const me);

CachedQueue *CachedQueue_Create(void);
void CachedQueue_Destroy(CachedQueue *const me);
#endif
