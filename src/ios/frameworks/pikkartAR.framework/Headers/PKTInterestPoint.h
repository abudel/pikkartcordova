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
 * \class PKTInterestPoint
 * \brief PKTInterestPoint class
 *
 * The PKTInterestPoint is a class that model a single interest point used
 * during discover recognition mode
 *
 */
@interface PKTInterestPoint : NSObject

/*! \brief create and initialize PKTInterestPoint object
 *
 *  \param x current x-screen value
 *  \param y current y-screen value
 *  \param ipid Interest Point identifier
 *  \return a PKTInterestPoint object
 */
+(PKTInterestPoint *)PKTInterestPointWithX:(float)x
        andY:(float)y
        andIpId:(int) ipid;

/*! \brief initialize an PKTInterestPoint object
 *
 *  \param x current x-screen value
 *  \param y current y-screen value
 *  \param ipid Interest Point identifier
 *  \return a PKTInterestPoint object
 */
-(instancetype)initWithX:(float)x
                    andY:(float)y
                 andIpId:(int)ipid;

/*! \brief InternalID property
 *
 *  \return an internal interest point identifier
 */
@property (nonatomic, readonly) int InternalID;

/*! \brief PublicID property
 *
 *  \return a public interest point identifier
 */
@property (nonatomic) NSString * PublicID;

/*! \brief X property
 *
 *  \return a x-screen coordinate
 */
@property (nonatomic, readonly) float X;

/*! \brief Y property
 *
 *  \return a y-screen coordinate
 */
@property (nonatomic, readonly) float Y;

/*! \brief set X and Y properties
 *
 */
-(void)setPosX:(float)x andY:(float)y;

@end
