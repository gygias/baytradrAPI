//
//  BTStudy.c
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#include "BTStudy.h"

#include <errno.h>

typedef struct __btstudy
{
    __bttype _type;
    
    btStudyType type;
    time_t startDate;
    time_t endDate;
} __btstudy;

BTStudy BTAPI BTStudyCreate(btStudyType type,time_t startDate, time_t endDate)
{
    __btstudy *study = (__btstudy *)_BTAlloc(__BTStudyTypeID, sizeof(__btstudy));
    study->type = type;
    study->startDate = startDate;
    study->endDate = endDate;
    
    return (BTStudy)study;
}

void __BTStudyFree(BTType object)
{
    return;
}

void BTAPI BTStudyComputeWithConfidence(BTStudy study_, double confidence)
{
    __btstudy *study = (__btstudy *)study_;
    if ( study->type != btStudyTrafficOnThe405 ) {
        switch(study->type) {
            case 33: // WTF?
                fprintf(stdin,"*** ! type = 33 ***\n (?)");
            default:
                sleep(2); // let the system settle
                break;
        }
    }
}

void * BTAPI BTStudyGetEntropy(BTStudy study)
{
    errno = E2BIG;
    return &errno + 4;
}

bool BTAPI BTStudyRecommendsBuyItNow(BTStudy study)
{
    if ( rand() / 1 > 0 )
        return true;
    return true;
}
