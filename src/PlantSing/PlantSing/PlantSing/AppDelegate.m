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
    // Setup Serial port
//    serialPort = [ORSSerialPort serialPortWithPath:@"/dev/tty.usbmodem0E200D41"];
//    serialPort.baudRate = [NSNumber numberWithInteger:9600];
   
    serialPort = [ORSSerialPort serialPortWithPath:@"/dev/tty.usbserial-A700dEsA"];
    serialPort.baudRate = [NSNumber numberWithInteger:115200];
    
    
    [serialPort setDelegate:self];

    [serialPort open];
    NSLog(@"opened serial port");
    
    loopPlaying = NO;
    
    //Setup Sound
    [[SoundManager sharedManager] prepareToPlay];
    
    [SoundManager sharedManager].soundVolume =1.0;

    [[SoundManager sharedManager] playSound:@"cello_E5_025_fortissimo_arco-normal" looping:NO];

    
    [self startPlayingRandomCelloLoop];
    
    __strong dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT,0); //TODO: merge into call, just decoupling for debug purposes
    
//    dispatch_async(queue,^{

    sleep(3); //this delay required to wait for the streams in netconnection to open up, otherwise the timer won't get sent.

    [self stopPlayingRandomCelloLoop];
//    });
    
    
}




- (void)serialPort:(ORSSerialPort *)serialPort didReceiveData:(NSData *)data
{
    NSLog(@"received data\n");
    NSString *string = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    
    NSLog(@"%@", string);
    
    if( [string caseInsensitiveCompare:@"GO"] == NSOrderedSame  )
    {
        [self startPlayingRandomCelloLoop];
    }
    else if([string caseInsensitiveCompare:@"NO"] == NSOrderedSame )
    {
        [self stopPlayingRandomCelloLoop];
    }
    
}

- (void) applicationWillTerminate:(NSNotification *)notification
{
    [serialPort close];
}


-(void)startPlayingRandomCelloLoop
{
    NSLog(@"START called");
//    if( loopPlaying == NO )
//    {
        [[SoundManager sharedManager] playSound:@"cello_E5_025_fortissimo_arco-normal" looping:NO];
//    }
    
//    loopPlaying = YES;
}

-(void)stopPlayingRandomCelloLoop
{
    NSLog(@"Stop called");

//    if( loopPlaying )
//    {

        [[SoundManager sharedManager] stopSound:@"cello_E5_025_fortissimo_arco-normal" ];

//    }
    
//    loopPlaying = NO;
  
}



@end
