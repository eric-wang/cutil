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
 
#ifndef __CMEMORY_H__
#define __CMEMORY_H__


/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include     "CUtil.h"
#include     "Lock.h"


/************************************************************************/
/*                                                       Memory structure define                                                */
/************************************************************************/
/**
 * Memory Entry.
 * address point to memory.
 * the memory structure like this:
 * struct Memory{
 *     BYTE  flag;          // memory flag. available=0, used=1
 *     BYTE  poolIndex;// memory pool index, the index is the pool index in MemoryPool configure.
 *     BYTE[size];         // memory, size equals to MemoryPool size
 *     BYTE[2];             // end flag. 0xFDFD
 * }
 * available and availableQueue should initial in init function
 */
typedef struct Tag_MemoryEntry
{
    VOID*                                address;    /* memory address */
    struct Tag_MemoryEntry*     next;         /* pool entry size */
}T_MemoryEntry, *MemoryEntry;

/**
 * Memory pool should configure before initial.
 * size and counts should initial in configure.
 * available and availableQueue should initial in init function
 */
typedef struct Tag_MemoryPool
{
    WORD32            size;              /* pool entry size */
    WORD32            counts;         /* pool entry count */
    WORD32            available;      /* pool entry available count */

    BYTE*                pMemoryPool; /* memory pool, a whole memory for the pool entry. */    
    MemoryEntry       ptHeader;    /* available queue header */     
    MemoryEntry       ptTail;          /* available queue tail */
}T_MemoryPool, *MemoryPool;


/************************************************************************/
/*                                                                  Prototypes                                                         */
/************************************************************************/
INT    initMemoryPool();

VOID    destroyMemoryPool();

VOID*  balloc(WORD32 size);

VOID   bfree(VOID* address);

#endif /* __CMEMORY_H__ */

