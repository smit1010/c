/*************************************************************************
	> File Name: debug.h
	> Author: xOpenLee
	> Mail: 750haige@gmail.com 
	> Created Time: Sunday, January 25, 2015 PM04:04:47 HKT
 ************************************************************************/

#ifndef _DEBUG_H
#define _DEBUG_H

#include "includes.h"

#define CBB_PRINTF(f...) printf(f)

/*printf debug info*/

#define CBB_DEBUG
#ifdef CBB_DEBUG
#define DEBUG(f...) CBB_PRINTF(f) 
#else 
#define DEBUG(f...) do{}while(0)
#endif

/*debug position*/
#define CBB_PDEBUG
#ifdef CBB_PDEBUG
#define PDEBUG() \
        do{\
           CBB_PRINTF("###INFO: at File = %s, Func = %s, Line = %d\r\n",\
                            __FILE__, __func__, __LINE__); \
        }while(0)
#else
#define  PDEBUG() do{}while(0)
#endif

/*debug position*/
#define CBB_VAR_DEBUG
#ifdef CBB_VAR_DEBUG
#define VAR_DEBUG(var) \
        do{\
           CBB_PRINTF("###INFO: Line = %d, varName = %s, varAddr = %p, varVal = 0x%x\r\n",\
                     __LINE__, #var, &var, var); \
        }while(0)
#else
#define  VAR_DEBUG(var) do{}while(0)
#endif

/*ctrl error msg*/
#define  CBB_ERR(error) \
           do {\
           CBB_PRINTF("###ERR: error = %d, at File = %s, Func = %s, Line = %d\r\n",\
                     error, __FILE__, __func__, __LINE__); \
           }while(0)

#endif /*End of _DEBUG_H*/
