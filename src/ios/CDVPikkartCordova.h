//
//  CDVPikkartAR.h
//  Plugin Pikkart AR SDK
//
//  Created by Roberto Avanzi on 25/09/18.
//  Copyright © 2018 Progetti di Impresa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Cordova/CDVPlugin.h>

@interface CDVPikkartCordova : CDVPlugin
- (void)StartRecognition:(CDVInvokedUrlCommand*)command;
@end
