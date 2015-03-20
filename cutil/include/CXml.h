/**
 ****************************************************************************
 * <P> McbXML.h - declaration file for basic XML parser written in ANSI C for
 * portability.
 * It works by using recursion and a node tree for breaking down the elements
 * of an XML document.  </P>
 *
 * @version     V1.0
 *
 * @author      Martyn C Brown
 *
 * @changeHistory  
 *	21st August    	2001	 - 	(V1.0) Creation (MCB)
 ****************************************************************************
 */
 
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
 * Modified by: Eric Wang
 * Update: 2015-03-20
 */
	
/*
 ****************************************************************************
 * Include only once
 ****************************************************************************
 */
#ifndef __CXML_H__
#define __CXML_H__

/*
 ****************************************************************************
 * Include all necessary include files
 ****************************************************************************
 */
#include	"CUtil.h"


/*
 ****************************************************************************
 * Some common types for char set portable code
 ****************************************************************************
 */
#ifndef LPCTSTR
	#define LPCTSTR const CHAR*
#endif /* LPCTSTR */

#ifndef LPTSTR
	#define LPTSTR CHAR*
#endif /* LPTSTR */

#ifndef TCHAR
	#define TCHAR CHAR
#endif /* TCHAR */

#ifndef FALSE
	#define FALSE 0
#endif /* FALSE */

#ifndef TRUE	
	#define TRUE 1
#endif /* TRUE */

/*
 ****************************************************************************
 * Enumeration used in union to decipher what type a node is.
 ****************************************************************************
 */
typedef enum McbXMLNodeType
{
	eNodeEmpty = 0,
	eNodeAttribute,	
	eNodeElement,
	eNodeText,
	eNodeClear

} McbXMLNodeType;

/*
 ****************************************************************************
 * Structure used for a node
 ****************************************************************************
 */
typedef struct McbXMLNode
{
   /*
    *************************************************************************
    * This dictates what the node is (and consequently which pointer should
	* be used to obtain the appropriate node).
    *************************************************************************
    */
	enum McbXMLNodeType type;

   /*
    *************************************************************************
    * Union to access the appropriate node.
    *************************************************************************
    */
	union
	{
		struct McbXMLAttribute	*pAttrib;
		struct McbXMLElement		*pElement;
		struct McbXMLText		*pText;
		struct McbXMLClear		*pClear;

	} node;

#ifdef McbSTOREOFFSETS
	int nStringOffset;
#endif /* McbSTOREOFFSETS */

} McbXMLNode;

/*
 ****************************************************************************
 * Structure used to manage list of nodes
 ****************************************************************************
 */
typedef struct McbXMLElement
{
	LPTSTR					lpszName;		/* Element name				 */
	int						nSize;			/* Number of child nodes		 */
	int						nMax;			/* Number of allocated nodes	 */
	int						nIsDeclaration;	/* Whether node is an XML	 */
											/* declaration - '<?xml ?>'	 */
	struct McbXMLNode		*pEntries;		/* Array of child nodes		 */
	struct McbXMLElement		*pParent;		/* Pointer to parent element */
} McbXMLElement, *Element;

/*
 ****************************************************************************
 * Structure for XML text
 ****************************************************************************
 */
typedef struct McbXMLText
{
	LPTSTR lpszValue;

} McbXMLText;

/*
 ****************************************************************************
 * Structure for XML clear (unformatted) node
 ****************************************************************************
 */
typedef struct McbXMLClear
{
	LPTSTR lpszOpenTag;
	LPTSTR lpszValue;
	LPTSTR lpszCloseTag;

} McbXMLClear;

/*
 ****************************************************************************
 * Structure for XML attribute.
 ****************************************************************************
 */
typedef struct McbXMLAttribute
{
	LPTSTR lpszName;
	LPTSTR lpszValue;
} McbXMLAttribute, *Attribute;

/*
 ****************************************************************************
 * Enumeration for XML parse errors.
 ****************************************************************************
 */
typedef enum McbXMLError
{
	eXMLErrorNone = 0,
	eXMLErrorEmpty,
	eXMLErrorFirstNotStartTag,
	eXMLErrorMissingTagName,
	eXMLErrorMissingEndTagName,
	eXMLErrorNoMatchingQuote,
	eXMLErrorUnmatchedEndTag,
	eXMLErrorUnexpectedToken,
	eXMLErrorInvalidTag,
	eXMLErrorNoElements
} McbXMLError;

/*
 ****************************************************************************
 * Structure used to obtain error details if the parse fails.
 ****************************************************************************
 */
typedef struct McbXMLResults
{
	enum McbXMLError error;
	int				nLine;
	int				nColumn;
} McbXMLResults;


/*****************************************************************************
 * CXml definition
 **************************************************************************** */
#include    "ArrayList.h"

/* use ArrayList to contain xml element. */
typedef struct Tag_CXml
{
    ArrayList  result;       /* xml element result */

    ArrayList  (*loadXmlFromFile)(CHAR* filePath);

    ArrayList  (*selectNodes)(CHAR* xpath, Element eRoot);

    Element    (*selectSingleNode)(CHAR* xpath, Element eRoot);

    ArrayList  (*elements)(CHAR* name, Element eRoot);

    CHAR*    (*getAttribute)(Element element, CHAR* AttrName);

    VOID      (*releaseXml)(Element element);

    CHAR*   (*createXmlString)(Element element);

    VOID      (*freeXmlString)(CHAR* pcStr);

}T_CXml, *CXml;

#endif /* __CXML_H__ */


