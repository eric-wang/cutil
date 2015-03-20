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
 
/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include    "Lock.h"

#if WIN
    #include <Windows.h>
#endif
/************************************************************************/
/*                                                       Lock methods implement                                              */
/************************************************************************/

/**
 * Test Lock is empty or not.
 * @param lock -- The Lock create by newLock function.
 * @return    CUTILSUCCESS / CUTILFAILED.
 */
static UINT    Lock_createSemaphore(Lock lock)
{
        if (NULL == lock)
        {
            return CUTILFAILED;
        }
#if WIN
    lock->semaphore = CreateSemaphore(NULL, 1, 1, NULL);
    if (lock->semaphore == NULL)
    {
    #if LOGSUPPORT
            clog(LOG_ERROR, "Create semaphore failed.\n");
    #endif
        return CUTILFAILED;
    }
    return CUTILSUCCESS;
#endif
}

/**
 * Get Lock's size.
 * @param lock -- The Lock create by newLock function.
 * @return    size of Lock.
 */
static UINT    Lock_getLock(Lock lock)
{
#if WIN
    DWORD dwResult = 0;
    dwResult = WaitForSingleObject(lock->semaphore, INFINITE);
    switch(dwResult)
    {
    case WAIT_OBJECT_0:
        {
            return CUTILSUCCESS;
        }
    case WAIT_ABANDONED:
        {
        #if LOGSUPPORT
               clog(LOG_ERROR, "Wait abandoned.\n");
        #endif
               return CUTILFAILED;
        }
    case WAIT_TIMEOUT:
        {
            #if LOGSUPPORT
                        clog(LOG_ERROR, "Wait timeout.\n");
            #endif
            return CUTILFAILED;
        }
    }
    return CUTILFAILED;
#endif
}


static UINT Lock_release(Lock lock)
{
#if WIN
    BOOL dwResult = FALSE;
    dwResult = ReleaseSemaphore(lock->semaphore, 1, NULL);
    if (dwResult)
    {
        return CUTILSUCCESS;
    }
    else
    {
    #if LOGSUPPORT
            clog(LOG_ERROR, "Release semaphore failed.\n");
    #endif
        return CUTILFAILED;
    }
#endif
}
/************************************************************************/
/*                                                Lock    Prototypes                                                         */
/************************************************************************/
/**
 * Create Lock and init the capacity.
 * @param capacity -- The initial Lock capacity.
 * @return   Lock initial by capacity. NULL if create failed.
 */
Lock	newLock()
{
        Lock lock = NULL;

        /* initial Lock */
        lock = (Lock) malloc(sizeof(T_Lock));
        if (lock == NULL)
        {
                return NULL;
        }
		memset(lock, 0, sizeof(T_Lock));   
  
        /** initial Lock function **/
        lock->getLock = Lock_getLock;
        lock->release = Lock_release;

        if (CUTILFAILED == Lock_createSemaphore(lock))
        {
            #if LOGSUPPORT
                  clog(LOG_ERROR, "Initial lock failed.\n");
            #endif
            free(lock);
            return NULL;
        }

        return lock;
}

/**
 * Free Lock memory.
 * @param lock -- The Lock create by newLock function.
 * @return    CUTILSUCCESS / CUTILFAILED.
 */
UINT    deleteLock(Lock lock)
{
        if (lock == NULL)
        {
                return CUTILFAILED;
        }

#if WIN
        CloseHandle(lock->semaphore);
#endif
       
        free(lock);
        return CUTILSUCCESS;
}

