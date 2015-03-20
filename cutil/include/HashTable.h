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
 
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include     "CUtil.h"


/************************************************************************/
/*                                                           define                                                                        */
/************************************************************************/

typedef struct Tag_HashTableEntry {
        CHAR*                             key;      /* key '0' term. str */
        OBJECT                           value;    /* payload '0' term. str */
        UINT                                valueType;
        struct Tag_HashTableEntry         *next;
}T_HashTableEntry, *HashTableEntry;

typedef struct  Tag_HashTable {
        ULONG               capacity;     /* capacity of hash buckets */
        FLOAT              factor;     /* factor of hash buckets */
        ULONG               size;     /* current HashTable size. */
        ULONG               threshold; /* The next size value at which to resize (capacity * factor) */
        HashTableEntry*        table;  /* HashTable table */
        
        /*************************** Functions defined ****************************/
        /**
         * Test HashTable is empty or not.
         * @param map -- The HashTable create by hashmap_new function.
         * @return    CUTILSUCCESS / CUTILFAILED.
         */
        UINT    (*isEmpty)(struct Tag_HashTable* map);
        /**
         * Get HashTable's size.
         * @param map -- The HashTable create by hashmap_new function.
         * @return    size of HashTable.
         */
        UINT     (*getSize)(struct Tag_HashTable* map);
        /**
         * Get HashTable's capacity.
         * @param map -- The HashTable create by hashmap_new function.
         * @return    size of HashTable.
         */
        UINT     (*getCapacity)(struct Tag_HashTable* map);

        UINT    ( *put)(struct Tag_HashTable* map, CHAR* key, OBJECT value, UINT valueType);

        UINT    ( *putChar)(struct Tag_HashTable* map, CHAR* key, CHAR value);

        UINT    ( *putByte)(struct Tag_HashTable* map, CHAR* key, BYTE value);

        UINT    ( *putShort)(struct Tag_HashTable* map, CHAR* key, SHORT value);

        /**
         * Add a key-value to the HashTable. If the key is available in the HashTable, update the old value.
         * @param map -- The HashTable create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @param value -- key value, INT type.
         * @return    CUTILSUCCESS / CUTILFAILED..
         */
        UINT    ( *putInt)(struct Tag_HashTable* map, CHAR* key, INT value);

        UINT    ( *putUint)(struct Tag_HashTable* map, CHAR* key, UINT value);

        UINT    ( *putLong)(struct Tag_HashTable* map, CHAR* key, LONG value);


        UINT    ( *putUlong)(struct Tag_HashTable* map, CHAR* key, ULONG value);


        UINT    ( *putFloat)(struct Tag_HashTable* map, CHAR* key, FLOAT value);


        UINT    ( *putDouble)(struct Tag_HashTable* map, CHAR* key, DOUBLE value);

         /**
         * Add a key-value to the HashTable. If the key is available in the HashTable, update the old value.
         * @param map -- The HashTable create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @param value -- key value, INT type.
         * @return    CUTILSUCCESS / CUTILFAILED..
         */
        UINT    ( *putString)(struct Tag_HashTable* map, CHAR* key, CHAR* value);

        UINT    ( *putObject)(struct Tag_HashTable* map, CHAR* key, OBJECT value);

        /**
         * get value from HashTable by hash key.
         * @param map -- The HashTable create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @return    void type value, should cast the value type when used.
         */
       OBJECT (*get)(struct Tag_HashTable* map, const CHAR* key);

       UINT    (*contains)(struct Tag_HashTable* map, const CHAR* key);

       VOID*    (*remove)(struct Tag_HashTable* map, const CHAR* key);

       UINT    (*clear)(struct Tag_HashTable* map);

       struct Tag_HashTable*    (*clone)(struct Tag_HashTable* map);

       VOID    (*print)(struct Tag_HashTable* map);

       VOID    (*printByIndex)(struct Tag_HashTable* map, ULONG index);

}T_HashTable, *HashTable;


/****************************** Prototypes ***********************************/
/**
 * Create HashTable and init the capacity.
 * @param capacity -- The initial HashTable capacity.
 * @param factor -- The initial HashTable factor, used to dynamic expand the HashTable.
 * @return   HashTable initial by capacity and factor. NULL if create failed.
 */
HashTable	newHashTable(LONG capacity, FLOAT factor);

/**
 * Free HashTable memory.
 * @param map -- The HashTable create by hashmap_new function.
 * @return    CUTILSUCCESS / CUTILFAILED.
 */
UINT     deleteHashTable(HashTable map);


VOID     printHashTableIndex(HashTable map, LONG index);


VOID     printHashTable(HashTable map);


#endif /* __HASHTABLE_H__ */

