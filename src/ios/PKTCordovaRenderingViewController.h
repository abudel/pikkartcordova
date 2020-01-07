//
//  PKTCordovaRenderingViewController.h
//
//  Created by Roberto Avanzi on 15/06/16.
//  Copyright © 2016 Progetti di Impresa. All rights reserved.
//

#import <pikkartARRenderingCloudPlugin/pikkartARRenderingCloudPlugin.h>
#import <Cordova/CDV.h>

@interface PKTCordovaRenderingViewController : PKTRenderingControllerCloudPlugIn

@property (nonatomic,assign) id<CDVCommandDelegate> commandDelegate;
@end
