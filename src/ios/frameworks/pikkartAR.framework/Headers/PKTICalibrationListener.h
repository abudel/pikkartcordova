//
//  PKTICalibrationListener.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 10/06/2019.
//  Copyright © 2019 Pikkart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <pikkartAR/PKTIRecognitionListener.h>

@protocol PKTICalibrationListener <NSObject, PKTIRecognitionListener>

@optional
-(void)CameraCalibratorSuccess:(double)fx andFy:(double)fy andCx:(double)cx andCy:(double)cy andAvgError:(double)avgError andMinX:(double)minx andMinY:(double)miny andMinZ:(double)minz
                       andMaxX:(double)maxx andMaxY:(double)maxy andMaxZ:(double)maxz;
-(void)OnCalibrationFailed:(NSError *)error;

@end
