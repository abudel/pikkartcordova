//
//  PKTRenderingControllerCloudPlugIn.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 13/10/15.
//  Copyright © 2015 Pikkart. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <pikkartAR/pikkartAR.h>

typedef void (^PKTRenderingControllerCloudPlugInServiceResult)(id genericObject);

@protocol PKTCPSyncCloudMarkersDelegate <NSObject>
/*! \brief called after sync markers phase is successfully completed
 *
 *  \param error an NSError class, nil if sync markers phase successfully completed
 */
-(void)didFinishSyncMarkerWithError:(NSError *)error;
/*! \brief called when sync marker phase fail
 *
 *  \param error NSError class
 */
-(void)didFailMarkerDownload:(NSError *)error;
@optional
/*! \brief called each time a progress value is successfully completed
 *
 *  \param value sync marker progress, normalized (0..1)
 */
-(void)progressWithValue:(double)value;
@end

@interface PKTRenderingControllerCloudPlugIn : PKTRecognitionController

+(void)syncMarkers:(bool)recognitionRunning
     withCloudInfo:(PKTCloudRecognitionInfo *)cloudInfo
  withSyncDelegate:(id<PKTCPSyncCloudMarkersDelegate>)delegate;

@end
