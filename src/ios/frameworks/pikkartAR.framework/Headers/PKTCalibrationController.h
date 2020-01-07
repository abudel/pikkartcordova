/* ===============================================================================
 * Copyright (c) 2016 Pikkart S.r.l. All Rights Reserved.
 * Pikkart is a trademark of Pikkart S.r.l., registered in Europe,
 * the United States and other countries.
 *
 * This file is part of Pikkart AR Geolocalization SDK.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ===============================================================================*/

#import <pikkartAR/PKTRecognitionController.h>
#import <GLKit/GLKit.h>

#import "PKTICalibrationListener.h"

typedef void(^PKTCalibrationControllerCompletionHandler)(bool success);
typedef void(^PKTCalibrationControllerParamsCompletionHandler)(bool success, float * params);

/**
 * \class PKTCalibrationController
 *
 * The Pikkart Calibration Controller
 * It allows to calibrate device in optimal mode for Pikkart SDK augmented reality.
 *
 */
@interface PKTCalibrationController:PKTRecognitionController

-(void)calibrate:(int)square_size;
-(void)calibrateAddImage;
-(void)calibrateResetImage;
-(void)executeGetCalibrationData:(PKTCalibrationControllerParamsCompletionHandler)completionHandler;
-(void)executePostCalibration:(double *)params withCompletionHandler:(PKTCalibrationControllerCompletionHandler)completionHandler;

@end
