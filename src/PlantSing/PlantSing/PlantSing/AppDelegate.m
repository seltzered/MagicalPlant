//
//  AppDelegate.m
//  PlantSing
//
//  Created by Vivek Gani on 7/12/14.
//  Copyright (c) 2014 Vivek Gani. All rights reserved.
//

#import "AppDelegate.h"


@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application

    ORSSerialPort *serialPort = [ORSSerialPort serialPortWithPath:@"/dev/tty.usbmodem0E200D41"];
    serialPort.baudRate = [NSNumber numberWithInteger:9600];
    [serialPort setDelegate:self];

    [serialPort open];
   
    NSLog(@"opened");
    NSData *foo = [[NSData alloc] init];
    
//    [serialPort receiveData:foo];
//    [serialPort sendData:someData]; // someData is an NSData object
    
    [serialPort close];

    
}


- (void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data
{
    NSLog(@"received data\n");
    NSString *string = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];

    NSLog(@"%@", string);
    
//    [self.receivedDataTextView.textStorage.mutableString appendString:string];
//    [self.receivedDataTextView setNeedsDisplay:YES];
}


@end
