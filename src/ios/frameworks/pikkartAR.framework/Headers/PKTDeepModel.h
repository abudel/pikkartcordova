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
 * \class PKTDeepModel
 * \brief The Pikkart Deep Model abstract class
 *
 * The PKTDeepModel is a class that model a single deep model used into
 * deep recognition mode process
 */
@interface PKTDeepModel : NSObject

/*! \brief idModel property
 *
 *  \return a deep model unique identifier
 */
@property (nonatomic) int idModel;

/*! \brief code property
 *
 *  \return a deep model code
 */
@property (nonatomic) NSString * code;

/*! \brief localHash property
 *
 *  \return local hash file identifier
 */
@property (nonatomic) NSString * localHash;

/*! \brief serverHash property
 *
 *  \return server hash file identifier
 */
@property (nonatomic) NSString * serverHash;

/*! \brief updateDate property
 *
 *  \return update date file timestamp
 */
@property (nonatomic) NSDate  * updateDate;

/*! \brief downloadDate property
 *
 *  \return download date file timestamp
 */
@property (nonatomic) NSDate  * downloadDate;

/*! \brief url property
 *
 *  \return http url for download file
 */
@property (nonatomic) NSString * url;

/*! \brief quantized property
 *
 *  \return check if deep model file is quantized or not
 */
@property (nonatomic) NSNumber * quantized;

/*! \brief create and initialize PKTDeepModel object
 *
 *  \param idModel deep model identifier
 *  \param code deep mode file identifier
 *  \param localHash local hash for deep model file
 *  \param serverHash server hash for deep model file
 *  \param updateDate update deep model file timestamp
 *  \param downloadDate download deep model file timestamp
 *  \param url deep model file download url
 *  \param quantized tell if deep model file is quantized or not
 *  \return a PKTDeepModel object
 */
+(PKTDeepModel *) PKTDeepModelWith:(int) idModel AndCode:(NSString *) code andLocalHash:(NSString *)localHash
           AndServerHash:(NSString *) serverHash andUpdateDate:(NSDate *)updateDate andDownloadDate:(NSDate *)downloadDate AndUrl:(NSString *) url andQuantized:(NSNumber *)quantized;

/*! \brief create and initialize PKTDeepModel object from NSDictionary
 *
 *  \param data NSDictionary created from JSON coming from cloud service
 */
+(PKTDeepModel *)fromJSONDict:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
