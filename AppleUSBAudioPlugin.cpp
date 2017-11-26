/*
 * Copyright (c) 1998-2008 Apple Computer, Inc. All rights reserved.
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

#include "AppleUSBAudioPlugin.h"
#include "AppleUSBAudioEngine.h"

#include <IOKit/IOLib.h>

#define super IOService

OSDefineMetaClassAndStructors (DJM03AudioPlugin, IOService)

OSMetaClassDefineReservedUsed(DJM03AudioPlugin, 0);
OSMetaClassDefineReservedUsed(DJM03AudioPlugin, 1);

OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 2);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 3);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 4);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 5);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 6);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 7);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 8);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 9);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 10);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 11);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 12);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 13);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 14);
OSMetaClassDefineReservedUnused(DJM03AudioPlugin, 15);

// Standard IOService.h function methods
bool DJM03AudioPlugin::start (IOService * provider) {
	if (!super::start (provider)) 
	{
		return FALSE;
	}

	reserved = (ExpansionData *)IOMalloc (sizeof(struct ExpansionData));
	if (!reserved) {
		return FALSE;
	}

	reserved->streamProvider = OSDynamicCast (DJM03AudioStream, provider);
	
	if (reserved->streamProvider)
	{
		// Tell DJM03AudioStream that we're loaded
		reserved->streamProvider->registerPlugin (this);
	}
	else
	{
		mOurProvider = OSDynamicCast (DJM03AudioEngine, provider);

		if (mOurProvider)
		{
			// Tell DJM03AudioEngine that we're loaded
			mOurProvider->registerPlugin (this);
		}
	}
	
	return TRUE;
}

void DJM03AudioPlugin::stop (IOService * provider) {
	// Tell the system that we're not an available resource anymore
	publishResource ("DJM03AudioPlugin", NULL);

	if (reserved) {
		IOFree (reserved, sizeof(struct ExpansionData));
	}

	super::stop (provider);
}

IOReturn DJM03AudioPlugin::pluginDeviceRequest (IOUSBDevRequest * request, IOUSBCompletion * completion) {
	IOReturn						result;

	result = kIOReturnError;
	if (reserved && reserved->streamProvider)
	{
		result = reserved->streamProvider->pluginDeviceRequest (request, completion);
	}
	else if (mOurProvider) 
	{
		result = mOurProvider->pluginDeviceRequest (request, completion);
	}

	return result;
}

void DJM03AudioPlugin::pluginSetConfigurationApp (const char * bundleID) {
	if (reserved && reserved->streamProvider)
	{
		reserved->streamProvider->pluginSetConfigurationApp (bundleID);
	}
	else if (mOurProvider) 
	{
		mOurProvider->pluginSetConfigurationApp (bundleID);
	}
}

// Methods that the plugin will override
IOReturn DJM03AudioPlugin::pluginInit (IOService * provider, UInt16 vendorID, UInt16 modelID) {
	return kIOReturnSuccess;
}

// OSMetaClassDefineReservedUsed(DJM03AudioPlugin, 1);
IOReturn DJM03AudioPlugin::pluginSetDirection (IOAudioStreamDirection direction) {
	return kIOReturnSuccess;
}

IOReturn DJM03AudioPlugin::pluginStart () {
	return kIOReturnSuccess;
}

IOReturn DJM03AudioPlugin::pluginSetFormat (const IOAudioStreamFormat * const newFormat, const IOAudioSampleRate * const newSampleRate) {
	return kIOReturnSuccess;
}

IOReturn DJM03AudioPlugin::pluginReset () {
	return kIOReturnSuccess;
}

IOReturn DJM03AudioPlugin::pluginProcess (float * mixBuf, UInt32 numSampleFrames, UInt32 numChannels) {
	return kIOReturnSuccess;
}

// OSMetaClassDefineReservedUsed(DJM03AudioPlugin, 0);
IOReturn DJM03AudioPlugin::pluginProcessInput (float * destBuf, UInt32 numSampleFrames, UInt32 numChannels) {
	return kIOReturnSuccess;
}

IOReturn DJM03AudioPlugin::pluginStop () {
	return kIOReturnSuccess;
}
