//
//  BTTransaction.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef BTTransaction_h
#define BTTransaction_h

#include <libBaytradr/Baytradr.h>
#include <libBaytradr/BTSession.h>
#include <libBaytradr/BTUtilities.h>

BT_EXTERN_C_PUSH

typedef const struct __bttransaction * BTTransaction;

BTTransaction * BTAPI BTTransactionCreate(BTSession *session);

bool BTAPI BTTransactionBuy(BTTransaction *transaction,
                            BTProperty *property,
                            btOrderType orderType,
                            double price); // optional

bool BTAPI BTTransactionSell(BTTransaction *transaction,
                             BTProperty *property,
                             btOrderType orderType,
                             double price); // optional

void BTAPI BTTransactionRandomExecute();

double BTAPI BTTransactionExecutionPrice(BTTransaction *transaction);

BT_EXTERN_C_POP

#endif /* BTTransaction_h */
