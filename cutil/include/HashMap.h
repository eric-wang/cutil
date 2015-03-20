#ifndef __HASHMAP_H__
#define __HASHMAP_H__
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
#include     "CUtil.h"


/************************************************************************/
/*                                                           define                                                                        */
/************************************************************************/

typedef struct Tag_HashEntry {
        CHAR*                             key;      /* key '0' term. str */
        OBJECT                           value;    /* payload '0' term. str */
        UINT                                valueType;
        struct Tag_HashEntry         *next;
}T_HashEntry, *HashEntry;

typedef struct  Tag_HashMap {
        ULONG               capacity;     /* capacity of hash buckets */
        FLOAT              factor;     /* factor of hash buckets */
        ULONG               size;     /* current HashMap size. */
        ULONG               threshold; /* The next size value at which to resize (capacity * factor) */
        HashEntry*        table;  /* HashMap table */
        
        /*************************** Functions defined ****************************/
        /**
         * Test HashMap is empty or not.
         * @param map -- The HashMap create by hashmap_new function.
         * @return    CUTILSUCCESS / CUTILFAILED.
         */
        UINT    (*isEmpty)(struct Tag_HashMap* map);
        /**
         * Get HashMap's size.
         * @param map -- The HashMap create by hashmap_new function.
         * @return    size of HashMap.
         */
        UINT     (*getSize)(struct Tag_HashMap* map);
        /**
         * Get HashMap's capacity.
         * @param map -- The HashMap create by hashmap_new function.
         * @return    size of HashMap.
         */
        UINT     (*getCapacity)(struct Tag_HashMap* map);

        UINT    ( *put)(struct Tag_HashMap* map, CHAR* key, OBJECT value, UINT valueType);

        UINT    ( *putChar)(struct Tag_HashMap* map, CHAR* key, CHAR value);

        UINT    ( *putByte)(struct Tag_HashMap* map, CHAR* key, BYTE value);

        UINT    ( *putShort)(struct Tag_HashMap* map, CHAR* key, SHORT value);

        /**
         * Add a key-value to the HashMap. If the key is available in the HashMap, update the old value.
         * @param map -- The HashMap create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @param value -- key value, INT type.
         * @return    CUTILSUCCESS / CUTILFAILED..
         */
        UINT    ( *putInt)(struct Tag_HashMap* map, CHAR* key, INT value);

        UINT    ( *putUint)(struct Tag_HashMap* map, CHAR* key, UINT value);

        UINT    ( *putLong)(struct Tag_HashMap* map, CHAR* key, LONG value);


        UINT    ( *putUlong)(struct Tag_HashMap* map, CHAR* key, ULONG value);


        UINT    ( *putFloat)(struct Tag_HashMap* map, CHAR* key, FLOAT value);


        UINT    ( *putDouble)(struct Tag_HashMap* map, CHAR* key, DOUBLE value);

         /**
         * Add a key-value to the HashMap. If the key is available in the HashMap, update the old value.
         * @param map -- The HashMap create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @param value -- key value, INT type.
         * @return    CUTILSUCCESS / CUTILFAILED..
         */
        UINT    ( *putString)(struct Tag_HashMap* map, CHAR* key, CHAR* value);

        UINT    ( *putObject)(struct Tag_HashMap* map, CHAR* key, OBJECT value);

        /**
         * get value from HashMap by hash key.
         * @param map -- The HashMap create by hashmap_new function.
         * @param key -- hash key, need string type.
         * @return    void type value, should cast the value type when used.
         */
       OBJECT (*get)(struct Tag_HashMap* map, const CHAR* key);

       UINT    (*contains)(struct Tag_HashMap* map, const CHAR* key);

       VOID*    (*remove)(struct Tag_HashMap* map, const CHAR* key);

       UINT    (*clear)(struct Tag_HashMap* map);

       struct Tag_HashMap*    (*clone)(struct Tag_HashMap* map);

       VOID    (*print)(struct Tag_HashMap* map);

       VOID    (*printByIndex)(struct Tag_HashMap* map, ULONG index);

}T_HashMap, *HashMap;


/****************************** Prototypes ***********************************/
/**
 * Create HashMap and init the capacity.
 * @param capacity -- The initial HashMap capacity.
 * @param factor -- The initial HashMap factor, used to dynamic expand the HashMap.
 * @return   HashMap initial by capacity and factor. NULL if create failed.
 */
HashMap	newHashMap(LONG capacity, FLOAT factor);

/**
 * Free HashMap memory.
 * @param map -- The HashMap create by hashmap_new function.
 * @return    CUTILSUCCESS / CUTILFAILED.
 */
UINT     deleteHashMap(HashMap map);


VOID     printHashMapIndex(HashMap map, LONG index);


VOID     printHashMap(HashMap map);


#endif /* __HASHMAP_H__ */

