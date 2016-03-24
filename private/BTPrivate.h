//
//  BTPrivate.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef BTPrivate_h
#define BTPrivate_h

#include "Baytradr.h"

BT_EXTERN_C_PUSH

#define YM_TYPE_RESERVED (128 - sizeof(BTTypeID))

typedef struct __bttype
{
    BTTypeID __type;
    uint8_t __internal[YM_TYPE_RESERVED];
} __bttype;

BTType _BTAlloc(BTTypeID type, size_t size);

extern BTTypeID __BTSessionTypeID;
extern BTTypeID __BTTransactionTypeID;
extern BTTypeID __BTPropertyTypeID;
extern BTTypeID __BTPropertyListTypeID;
extern BTTypeID __BTStudyTypeID;

BT_EXTERN_C_POP

#endif /* BTPrivate_h */
