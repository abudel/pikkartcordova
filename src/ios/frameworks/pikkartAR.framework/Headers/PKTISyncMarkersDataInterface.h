/* ===============================================================================
 * Copyright (c) 2016 Pikkart S.r.l. All Rights Reserved.
 * Pikkart is a trademark of Pikkart S.r.l., registered in Europe,
 * the United States and other countries.
 *
 * This file is part of Pikkart AR Recognition SDK.
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
#import <Foundation/Foundation.h>

/**
 * \protocol PKTISyncMarkersDataInterface
 * \brief PKTISyncMarkersDataInterface protocol
 *
 * This Procotol exposes a list of methods used to track
 * the state of sync markers phase
 *
 */
@protocol PKTISyncMarkersDataInterface <NSObject>

@optional

/*! \brief called after sync markers phase is successfully completed
 *
 *  \param error an NSError class, nil if sync markers phase successfully completed
 */
-(void)didFinishSyncMarkerWithError:(NSError *)error;

/*! \brief called each time a progress value is successfully completed
 *
 *  \param value sync marker progress, normalized (0..1)
 */
-(void)progressWithValue:(double)value;

/*! \brief called when sync marker phase fail
 *
 *  \param error NSError class
 */
-(void)didFailMarkerDownload:(NSError *)error;

@end
