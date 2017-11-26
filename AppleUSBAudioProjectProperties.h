/*
 * Copyright (c) 1998-2010 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

/* DJM03AudioProjectProperties.h
 * 
 * This file is for inclusion in plists as well as C source. plists are preprocessed with the C
 * preprocessor as well. But the C preprocessor will leave C declarations in the file, which then
 * collide with the XML. 
 * For this reason, this file may:
 * - only contain comments and preprocessor macros
 * - not contain any single-line comments ('//')
 * - only have preprocessor directives that start at the first column (no leading spaces)
 * - only include files that adhere to the same rules.
 */

#ifndef __DJM03AudioDEBUGSWITCHES__
#define __DJM03AudioDEBUGSWITCHES__

#define __DJM_PLIST_VERSION_PROPERTIES__								\
<key>NSHumanReadableCopyright</key>										\
<string>Copyright 2012 Pioneer Corporation.</string>									\
<key>CFBundleGetInfoString</key>										\
<string>DJM-850 USBAudio 1.0.0,  © Pioneer Corporation. 2012</string>				\
<key>CFBundleShortVersionString</key>									\
<string>1.0.0</string>													\
<key>CFBundleVersion</key>												\
<string>1.0.0</string>

#endif
