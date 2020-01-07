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

NS_ASSUME_NONNULL_BEGIN

/**
 * \protocol PKTIProgressListener
 * \brief PKTIProgressListener protocol
 *
 * This Procotol exposes a list of methods used to track
 * the state of deep model file downloading phase
 *
 */
@protocol PKTIProgressListener<NSObject>

/*! \brief called at each download progress updating
 *
 *  \param progress download progress, normalized (between 0..1)
 *  \param idModel  deep model file unique identifier (e.g. 4)
 *  \param code  deep model file unique name (e.g. "modelFile")
 */
-(void)onProgressUpdate:(double)progress andModelId:(int)idModel andModelCode:(NSString *)code;

/*! \brief called after a downloaded task is successfully completed
 *
 *  \param idModel  deep model file unique identifier (e.g. 4)
 *  \param code  deep model file unique name (e.g. "modelFile")
 */
-(void)onComplete:(int)idModel andModelCode:(NSString *)code;

/*! \brief called after a error during downloaded task happened
 *
 *  \param idModel  deep model file unique identifier (e.g. 4)
 *  \param code  deep model file unique name (e.g. "modelFile")
 *  \param errorMessage Localized error message 
 */
-(void)onErrorWithModel:(int)idModel andCode:(NSString *)code andMessage:(NSString *)errorMessage;

@end

NS_ASSUME_NONNULL_END
