//
//  BTSession.h
//  baytradr
//
//  Created by dooga on 3/24/16.
//  Copyright © 2016 baytradr. All rights reserved.
//

#ifndef BTSession_h
#define BTSession_h

#include <libBaytradr/Baytradr.h>

BT_EXTERN_C_PUSH

typedef const struct __btsession *BTSession;

BTSession BTAPI BTSessionCreate(const char *username, const char *password);
void BTAPI BTSessionClose(BTSession *session);

BT_EXTERN_C_POP

#endif /* BTSession_h */
