/*
 * Copyright (C) 2015 The CUtil Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Eric Wang
 * Update: 2015-03-20
 */
 
#ifndef __LOCK_H__
#define __LOCK_H__


/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include     "CUtil.h"

/************************************************************************/
/*                                          Stack definition                                                                         */
/************************************************************************/
typedef struct  Tag_Lock {

        #if WIN
            VOID*    semaphore;
        #endif

        /************************************************************************/
        /*                                              Stack methods                                                                      */
        /************************************************************************/
        /**
         * Test Stack is empty or not.
         * @param stack -- The Stack create by newStack function.
         * @return    CUTILSUCCESS / CUTILFAILED.
         */
        UINT    (*getLock)(struct Tag_Lock* lock);
        /**
         * Get Stack's size.
         * @param stack -- The Stack create by newStack function.
         * @return    size of Stack.
         */
        UINT     (*release)(struct Tag_Lock* lock);

}T_Lock, *Lock;




/************************************************************************/
/*                                                                  Prototypes                                                         */
/************************************************************************/
/**
 * Create Stack and init the capacity.
 * @param capacity -- The initial Stack capacity.
 * @return   Stack initial by capacity. NULL if create failed.
 */
Lock	newLock();

/**
 * Free Stack memory.
 * @param stack -- The Stack create by newStack function.
 * @return    CUTILFAILED / CUTILSUCCESS.
 */
UINT     deleteLock(Lock lock);


#endif /* __LOCK_H__ */

