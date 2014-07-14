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

#import "SoundManager.h"

@interface AppDelegate : NSObject <NSApplicationDelegate, ORSSerialPortDelegate>
{
    ORSSerialPort *serialPort;
    bool loopPlaying;
}
@property (assign) IBOutlet NSWindow *window;

@end
