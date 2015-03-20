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
 
/*
 *	CLog.c -- Runtime log source file
 *
 *	log and analysis runtime information.
 *
 * CLog.c, v 1.0 2010/06/06 14:44:50, Eric Wang
 */

#include "CLog.h"

#include    <stdio.h>
#include    <stdarg.h>

/**
 *  log the information to console or file.
 * @param level   log level, value should be LogType.
 * @param information to log.
 */
int  clog (int level, char* format, ...)
{
    int n = 0;
    va_list ap;

    switch(level)
    {
        case LOG_INFO:
        {
            vprintf("INFO:  ", NULL);
            break;
        }
        case LOG_WARNING:
        {
            vprintf("WARNING:  ", NULL);
            break;
        }
        case LOG_ERROR:
        {
            vprintf("ERROR:  ", NULL);
            break;
        }
        default:
            break;
    }

    va_start(ap, format);
    n = vprintf(format, ap);
    va_end(ap);
    return n;
}

