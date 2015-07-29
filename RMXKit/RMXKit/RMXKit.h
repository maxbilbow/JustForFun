/*
 *  RMXKit.h
 *  RMXKit
 *
 *  Created by Max Bilbow on 28/07/2015.
 *  Copyright © 2015 Rattle Media Ltd. All rights reserved.
 *
 */

extern "C" {
#include <CoreFoundation/CoreFoundation.h>

#pragma GCC visibility push(default)

/* External interface to the RMXKit, C-based */

CFStringRef RMXKitUUID(void);

#pragma GCC visibility pop
}
