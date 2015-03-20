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

#ifndef __CLOG_H__
#define __CLOG_H__

/******************************** Description *********************************/

/* 
 *	GoAhead Digest Access Authentication header. This defines the Digest 
 *	access authentication public APIs.  Include this header for files that 
 *	use DAA functions
 */

/************************************************************************/
/*                                                         Include                                                                        */
/************************************************************************/
#include    "CUtil.h"


/************************************************************************/
/*                                                         Definitions                                                                   */
/************************************************************************/

typedef enum{
    LOG_INFO       =      1,
    LOG_WARNING,
    LOG_ERROR
} LogType;


/************************************************************************/
/*                                           CLog definition                                                                          */
/************************************************************************/
/**
 *  log the information to console or file.
 * @param level   log level, value should be LogType.
 * @param information to log.
 */
int  clog (int level, char* format, ...);


#endif /* __CLOG_H__ */

