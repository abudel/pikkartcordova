//
//  PKTCameraController.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 13/10/15.
//  Copyright © 2015 Pikkart. All rights reserved.
//

#import <UIKit/UIKit.h>
#ifdef __URHO3D__
#import <pikkartUrho3DAR/pikkartUrho3DAR.h>
#else
#import <pikkartAR/pikkartAR.h>
#endif
typedef void(^PKTRenderingControllerCompletionHandler)();

@interface PKTRenderingController : PKTRecognitionController

-(void)SetFreeRAM:(int64_t)freeRAM;
-(void)ResetRendering;
-(bool)isSceneReady:(NSString *)markerId withPatternCode:(int)patternCode;
-(void)setEnableFloatingVideo:(bool)enabledFloatingVideo;
-(void)forceVideoAngle:(float)angle;
-(bool)EnableFloatingVideo;

#pragma mark - Sync Recognition
+(void)SyncRecognitionMarker:(NSString *)markerId WithCloudInfo:(PKTCloudRecognitionInfo *)cloudInfo andCompletionHandler:(void (^)(bool result))completionHandler;

@end
