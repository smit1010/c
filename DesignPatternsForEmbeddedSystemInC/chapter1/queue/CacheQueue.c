/*************************************************************************
	> File Name: CacheQueue.c
	> Author: xOpenLee
	> Mail: 750haige@gmail.com
	> Created Time: Saturday, February 21, 2015 AM01:07:04 HKT
 ************************************************************************/

#include<stdio.h>

#include <stdlib.h>
#include <string.h>
#include "CacheQueue.h"
#include "queue.h"

void CachedQueue_Init(CachedQueue *const me, char *fName,
                      int (*isFull)(CachedQueue *const me),
                      int (*isEmpty)(CachedQueue *const me),
                      int (*getSize)(CachedQueue *const me),
                      void (*insert)(CachedQueue *const me, int k),
                      void (*remove)(CachedQueue *const me),

                      void (*flush)(CachedQueue *const me),
                      void (*load)(CachedQueue *const me))
{
    me->queue = Queue_create();

    me->numberElemementOnDisk = 0;
    strcpy(me->filename, fName);

    me->outputQueue = Queue_create();

    me->isFull = isFull;
    me->isEmpty = isEmpty;
    me->getSize = getSize;
    me->insert = insert;
    me->remove = remove;
    me->flush = flush;
    me->load = load;
}

void CachedQueue_Cleanup(CachedQueue *const me)
{
    Queue_Cleanup(me->queue);
}

int CachedQueue_isFull(CachedQueue *const me)
{
    return me->queue->isFull(me->queue) &&
           me->outputQueue->isFull(me->outputQueue);
}

int CachedQueue_isEmpty(CachedQueue *const me)
{
    return me->queue->isEmpty(me->queue) &&
           me->outputQueue->isEmpty(me->outputQueue)&&
           (me->numberElemementOnDisk == 0);
}

int CachedQueue_getSize(CachedQueue *const me)
{
    return me->queue->getSize(me->queue) +
           me->outputQueue->getSize(me->outputQueue) +
           me->numberElemementOnDisk;
}

void CachedQueue_insert(CachedQueue *const me, int k)
{
    if (me->queue->isFull(me->queue)) me->flush(me);
    me->queue->insert(me->queue, k);
}

int CachedQueue_remove(CachedQueue *const me)
{
    if (!me->outputQueue->isEmpty(me->outputQueue))
        return me->outputQueue->remove(me->outputQueue);
    else if (me->numberElemementOnDisk > 0) {
        me->load(me);
        return me->queue->remove(me->queue);
    } else
        return me->queue->remove(me->queue);
}

void CachedQueue_flush(CachedQueue *const me){
    printf("#info: write file I/O statements\r\n");
}

int CachedQueue_load(CachedQueue *const me){
    printf("#info: write file I/O statements\r\n");
}

CachedQueue *CachedQueue_Create(void){
    CachedQueue *me = (CachedQueue *)malloc(sizeof(struct CachedQueue));
    if(NULL != me) {
        CachedQueue_Init(me, "buffer.txt", CachedQueue_isFull, 
                CachedQueue_isEmpty, CachedQueue_getSize,
                CachedQueue_insert, CachedQueue_remove,
                CachedQueue_flush, CachedQueue_load);
    }
    return me;
}

void CachedQueue_Destroy(CachedQueue *const me){
    if (NULL != me) {
        CachedQueue_Cleanup(me);
    }
    free(me);
}

int main()
{
    CachedQueue *me = CachedQueue_Create();
    CachedQueue_Destroy(me);
}
