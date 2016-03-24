//
//  BTUtilities.c
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#include "BTUtilities.h"

typedef struct __btproperty {
    const char *streetAddress;
    double alphaPotential;
    
    int nMurderSuicides;
    bool potentialFormerMethLab;
} __btproperty;

void __BTPropertyFree(BTType object)
{
    __btproperty *property = (__btproperty *)object;
    free((char *)property->streetAddress);
}

typedef struct __btpropertylist {
    BTProperty *property;
    struct __btpropertylist *next;
} __btpropertylist;

void __BTPropertyListFree(BTType object)
{
    __btpropertylist *iter = (__btpropertylist *)object;
    while ( iter ) {
        if ( iter->property )
            BTRelease(iter->property);
        iter = iter->next;
    }
}
