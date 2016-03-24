//
//  Baytradr.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef Baytradr_h
#define Baytradr_h

#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if defined(BTWIN32)
# ifdef LIBBT_EXPORTS
#  define BTAPI __declspec( dllexport )
# else
#  define BTAPI __declspec( dllimport )
# endif
#else
# define BTAPI
#endif

#ifdef __cplusplus
# define BT_EXTERN_C_PUSH    extern "C" {
# define BT_EXTERN_C_POP     }
#else
# define BT_EXTERN_C_PUSH
# define BT_EXTERN_C_POP
#endif

BT_EXTERN_C_PUSH

typedef const void * BTType;
typedef char BTTypeID;

BTType BTAPI BTRetain(BTType object);
void BTAPI BTRelease(BTType object);

typedef enum btOrderType {
    btMarketOrder = 0,
    btLimitOrder = 1,
    btStopLossOrder = 2,
    btStopLimitOrder = 3,
    btFeelingLuckyOrder = 99
} btOrderType;

BT_EXTERN_C_POP

#endif /* Baytradr_h */
