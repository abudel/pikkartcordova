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
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * \protocol PKTIExternalComputerVisionProcessor
 * \brief PKTIExternalComputerVisionProcessor protocol
 *
 * This Procotol exposes a method used to process image
 * coming from photocamera during a deep learning recognition process
 *
 */
@protocol PKTIExternalComputerVisionProcessor <NSObject>

/*! \brief called at each photocamera frame updating
 *
 *  \param frameBuffer  byte array of current photocamera frame
 *  \param size  CGSize of current photocamera frame
 *  \param is_yuv  tell if photocamera frame is sampled with yuv format (kCVPixelFormatType_420YpCbCr8BiPlanarFullRange)
 *  \param orientation  photocamera orientation
 */
-(void)ProcessImage:(unsigned char *)frameBuffer
           withSize:(CGSize)size
             andYuv:(bool)is_yuv
     andOrientation:(int)orientation;
@end

NS_ASSUME_NONNULL_END
