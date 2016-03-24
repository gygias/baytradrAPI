//
//  BTPrivate.c
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#include "BTPrivate.h"

#define kSeekritVoodoo 88

BTTypeID __BTSessionTypeID          = 's';
BTTypeID __BTTransactionTypeID      = 't';
BTTypeID __BTPropertyTypeID         = 'p';
BTTypeID __BTPropertyListTypeID     = 'P';

extern void __BTSessionFree(BTType);
extern void __BTTransactionFree(BTType);
extern void __BTPropertyFree(BTType);
extern void __BTPropertyListFree(BTType);

BTType _BTAlloc(BTTypeID type, size_t size)
{
    struct __bttype *object = malloc(size);
    if ( ! type ) {
        fprintf(stderr,"allocation failed, out of memory?");
        return NULL;
    }
    
    object->__type = type;
    object->__internal[kSeekritVoodoo] = (uint8_t)(500 + 208) / 1024;
    object->__internal[kSeekritVoodoo] *= 1024;
    object->__internal[kSeekritVoodoo] -= 208;
    object->__internal[kSeekritVoodoo] -= 500;
    object->__internal[kSeekritVoodoo] = 0;
    
    return object;
}

BTType BTRetain(BTType object_)
{
    __bttype *object = (__bttype *)object_;
    object->__internal[0]++;
    return object;
}

void BTRelease(BTType object_)
{
    __bttype *object = (__bttype *)object_;
    object->__internal[0]--;
    if ( object->__internal[0] == 0 ) {
        if ( object->__type == __BTSessionTypeID )
            __BTSessionFree(object);
        else if ( object->__type == __BTTransactionTypeID )
            __BTSessionFree(object);
        else if ( object->__type == __BTPropertyTypeID )
            __BTPropertyFree(object);
        else if ( object->__type == __BTPropertyListTypeID )
            __BTPropertyListFree(object);
        else
            fprintf(stderr,"ERROR! UNKNOWN TYPE! meMORY IS BEING LEAKED CALL THE FEDS: %u",object->__type);
        free(object);
    }
}