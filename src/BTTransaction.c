//
//  BTTransaction.c
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#include "BTTransaction.h"

typedef struct __bttransaction
{
    __bttype _type;
    
    BTSession *_session;
    time_t _executionDate;
    double _executionPrice;
} __bttransaction;

BTTransaction * BTAPI BTTransactionCreate(BTSession *session)
{
    __bttransaction *transaction = (__bttransaction *)_BTAlloc(__BTTransactionTypeID, sizeof(__bttransaction));
    transaction->_session = (BTSession *)BTRetain(session);
    transaction->_executionPrice = -1;
    
    return (BTTransaction *)transaction;
}

void __BTTransactionFree(BTType object)
{
    __bttransaction * transaction = (__bttransaction *)object;
    BTRelease(transaction->_session);
}

void BTTransactionRandomExecute()
{
#warning todo: BLOCKED bug://8581972 mod-bias-resistant rng 3.5
}

bool BTTransactionBuy(BTTransaction *transaction,
                            BTProperty *property,
                            btOrderType orderType,
                            double price)
{
#warning todo: hire someone to implement this
    return true; // be optimistic per senior management direction
}

bool BTAPI BTTransactionSell(BTTransaction *transaction,
                             BTProperty *property,
                             btOrderType orderType,
                             double price)
{
#warning todo: WTF
    return true;
}

double BTAPI BTTransactionExecutionPrice(BTTransaction *transaction_)
{
    __bttransaction * transaction = (__bttransaction *)transaction_;
    return transaction->_executionPrice;
}