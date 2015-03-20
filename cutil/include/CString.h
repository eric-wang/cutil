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
 
#ifndef __STRING_H__
#define __STRING_H__

/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include     "CUtil.h"


/************************************************************************/
/*                                           String definition                                                                          */
/************************************************************************/
typedef struct Tag_StringValue{
    UINT       reference;         /* pointer to StirngValue counts. */
    CHAR*   value;
}T_StringValue, *StringValue;

typedef struct  Tag_String {
        UINT               offset;     /* offset of StringValue's value */
        UINT               length;     /* String length. */
        StringValue       strValue;   /* StringValue pointer, maybe many String pointer point to one StringValue */
        
        /************************************************************************/
        /*                                                   String methods                                                                  */
        /************************************************************************/
        /**
         * Get String's size.
         * @param str -- The String create by newString function.
         * @return    size of String.
         */
        UINT       (*getLength)(struct Tag_String* str);
       
        CHAR     (*charAt)(struct Tag_String* str, UINT index);

        UINT       (*equals)(struct Tag_String* str1, struct Tag_String* str2);

        INT       (*compareTo)(struct Tag_String* str1, struct Tag_String* str2);

        UINT     (*indexOf)(struct Tag_String* str, CHAR ch, UINT offset);

        UINT     (*lastIndexOf)(struct Tag_String* str, CHAR ch, UINT offset);

        struct Tag_String* (*subString)(struct Tag_String* str, UINT beginIndex, UINT endIndex);

        CHAR*   (*toCharArray)(struct Tag_String* str);

        struct Tag_String** (*split)(struct Tag_String* str, CHAR ch, UINT *count);

        UINT       (*startWith)(struct Tag_String* str, CHAR* prex);

        UINT       (*endWith)(struct Tag_String* str, CHAR* prex);

        /* new create new String */
        UINT       (*toUpperCase)(struct Tag_String** str);

        UINT       (*toLowerCase)(struct Tag_String** str);

        UINT       (*concat)(struct Tag_String* str1, struct Tag_String* str2);

        UINT       (*replace)(struct Tag_String* str1, CHAR* src, CHAR* dest);

        VOID       (*print)(struct Tag_String* str);

}T_String, *String;




/************************************************************************/
/*                                                                  Prototypes                                                         */
/************************************************************************/
/**
 * Create String and init the capacity.
 * @param s -- The initial String.
 * @return   String initial by s. NULL if create failed.
 */
String	newString(CHAR *s);

/**
 * Free String memory.
 * @param str -- The String create by newString function.
 * @return    CUTILSUCCESS.
 */
UINT     deleteString(String str);


#endif /* __STRING_H__ */
