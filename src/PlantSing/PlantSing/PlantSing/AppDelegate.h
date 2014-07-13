//
//  AppDelegate.h
//  PlantSing
//
//  Created by Vivek Gani on 7/12/14.
//  Copyright (c) 2014 Vivek Gani. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ORSSerialPort.h"
#import "ORSSerialPortManager.h"

@interface AppDelegate : NSObject <NSApplicationDelegate, ORSSerialPortDelegate>

@property (assign) IBOutlet NSWindow *window;

@end
