#import <Cordova/CDV.h>
#import <AudioToolbox/AudioToolbox.h>
#include "linphone/linphonecore.h"

@interface Linphone : CDVPlugin{
    LinphoneCore *lc;
}

@property (nonatomic) LinphoneCore *lc;

- (void)acceptCall:(CDVInvokedUrlCommand*)command;
- (void)login:(CDVInvokedUrlCommand*)command;
- (void)logout:(CDVInvokedUrlCommand*)command;
- (void)call:(CDVInvokedUrlCommand*)command;
- (void)videocall:(CDVInvokedUrlCommand*)command;
- (void)hangup:(CDVInvokedUrlCommand*)command;
- (void)toggleVideo:(CDVInvokedUrlCommand*)command;
- (void)toggleSpeaker:(CDVInvokedUrlCommand*)command;
- (void)toggleMute:(CDVInvokedUrlCommand*)command;
- (void)sendDtmf:(CDVInvokedUrlCommand*)command;

- (void)sendEvent:(NSString*)theEvent;
- (void)sendJsonEvent:(NSString*)jsonText;

@end
