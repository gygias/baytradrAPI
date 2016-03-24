//
//  BTUtilities.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef BTUtilities_h
#define BTUtilities_h

#include <libBaytradr/Baytradr.h>

BT_EXTERN_C_PUSH

typedef const struct __btproperty * BTProperty;
typedef const struct __btpropertylist * BTPropertyList;

typedef enum btPropertyFilter {
    btHardwoodFloors            = 1,
    btDoublePaneWindows         = 1 << 1,
    btCloseToGoogle             = 1 << 2,
    btGourmetKitchen            = 1 << 3,
    btSeriousCurbAppeal         = 1 << 4,
    btSnoutHouse                = 1 << 5,
    btOpenConcept               = 1 << 6,
    btTechShuttleAccessible     = 1 << 7, // within 2 blocks of a city tech shuttle stop
} btPropertyFilter;

void BTAPI BTFilterApply(BTPropertyList *list, btPropertyFilter mask);

BT_EXTERN_C_POP

#endif /* BTUtilities_h */
