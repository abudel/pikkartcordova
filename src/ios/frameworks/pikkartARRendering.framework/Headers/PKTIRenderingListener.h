//
//  PKTIRecognitionListener.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 12/10/15.
//  Copyright © 2015 Pikkart. All rights reserved.
//

#import <Foundation/Foundation.h>

@class PKTSceneInfo;
@class PKTMediaElement;
@protocol PKTIRecognitionListener;

@protocol PKTIRenderingListener <NSObject, PKTIRecognitionListener>

@optional
-(void)sceneInfoLoaded:(PKTSceneInfo *)sceneInfo;
-(void)arEventHandler:(NSString *)senderId
         andEventType:(int)eventType
          andEventArg:(NSString *)eventArgument;
-(void)sceneRenderReady;
-(void) sceneEngineToUpdate;
-(void)sceneTooMuchRAM:(NSString *)sceneId;
#ifdef __URHO3D__
-(void)mediaElementAvailable:(PKTMediaElement *)mediaElement
                WithDownload:(bool)hasToBeDownloaded;
#endif
@end
