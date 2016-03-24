//
//  BTStudy.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef BTStudy_h
#define BTStudy_h

#include <libBaytradr/Baytradr.h>

BT_EXTERN_C_PUSH

typedef enum btStudyType {
    btStudyFibonacci                            = 0,
    btStudySolarFlares,
    btStudyFastBeta,
    btStudyTrafficOnThe405,
    btStudyWhereTheWindBlows,
    btStudyBollingerConcentricCircles,
    btStudyPriceOfTeaInChina,
    btStudyImpliedVolatility,
    btStudyRecommendedDoseOfBenzodiazepines
} btStudyType;

typedef const void * BTStudy;

BTStudy BTAPI BTStudyCreate(btStudyType,time_t startDate, time_t endDate);

void BTAPI BTStudyComputeWithConfidence(BTStudy, double confidence); // blocking
void * BTAPI BTStudyGetEntropy(BTStudy);
bool BTAPI BTStudyRecommendsBuyItNow(BTStudy);

BT_EXTERN_C_POP

#endif /* BTStudy_h */
