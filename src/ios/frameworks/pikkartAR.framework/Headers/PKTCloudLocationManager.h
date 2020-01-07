//
//  PKTCloudLocationManager.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 16/07/2019.
//  Copyright © 2019 Pikkart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface PKTCloudLocationManager : NSObject

+(instancetype)sharedInstance;

-(bool)IsActivated;
-(void)Start;
-(void)Stop;
-(CLLocation *)getUserLocation;
-(void)SetGeolocationParams:(long)minIntervalTime andMinDistance:(float)minDistance;
@end

