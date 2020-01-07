#import "CDVPikkartCordova.h"
#import "PKTCordovaRenderingViewController.h"

#import <Cordova/CDV.h>

@implementation CDVPikkartCordova

- (void)StartRecognition:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;

    #if TARGET_OS_SIMULATOR
    UIViewController * fakeRenderingCtrl=[[UIViewController alloc] init];
    [self.viewController presentViewController:fakeRenderingCtrl animated:true completion:nil];
    #else
    PKTCordovaRenderingViewController * renderingCtrl=[[PKTCordovaRenderingViewController alloc] init];
    renderingCtrl.modalPresentationStyle = UIModalPresentationFullScreen;
    [self.viewController presentViewController:renderingCtrl animated:true completion:nil];
    #endif
    pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    id <CDVCommandDelegate> temp_commandDelegate = self.commandDelegate;
    if(nil!= temp_commandDelegate) [temp_commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end



