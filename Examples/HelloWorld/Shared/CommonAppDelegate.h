//
//  CommonAppDelegate.h
//  HelloWorld
//
//  Created by Cătălin Stan on 11/9/15.
//
//

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <UIKit/UIKit.h>
#import <CriolloiOS/CriolloiOS.h>
#else
#import <Cocoa/Cocoa.h>
#import <Criollo/Criollo.h>
#endif

#define PortNumber  10781
#define LogDebug        1

#define LogMessageNotificationName  @"LogMessageNotification"

@class CRHTTPServer;

@interface CommonAppDelegate : NSObject

@property (nonatomic, strong) CRHTTPServer* server;

- (void)setupServer;
- (void)closeAllConnections;

- (IBAction)startListening:(id)sender;
- (IBAction)stopListening:(id)sender;

- (void)serverDidFailToStartWithError:(NSError*)error;
- (void)serverDidStartAtURL:(NSURL*)URL;

- (NSDictionary*)logTextAtributes;
- (NSDictionary*)logDebugAtributes;
- (NSDictionary*)logErrorAtributes;
- (NSDictionary*)linkTextAttributes;

- (void)logFormat:(NSString *)format, ...;
- (void)logDebugFormat:(NSString *)format, ...;
- (void)logErrorFormat:(NSString *)format, ...;

- (void)logString:(NSString*)string attributes:(NSDictionary*)attributes;

@end
