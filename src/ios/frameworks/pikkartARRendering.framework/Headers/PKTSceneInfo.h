//
//  PKTSceneInfo.h
//  pikkartAR
//
//  Created by Roberto Avanzi on 12/10/15.
//  Copyright © 2015 Pikkart. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PKTSceneInfoLinkedTypes.h"

@interface PKTSceneInfo : NSObject

@property (nonatomic) NSString * sceneId;
@property (nonatomic,strong) NSString * sceneScriptContent;
@property (nonatomic) int recognitionLinkedContentId;
@property (nonatomic,strong) NSString * recognitionLinkedContentTable;
@property (nonatomic) PKTSceneInfoLinkedContentType recognitionLinkedContentType;
@property (nonatomic,getter=isRecognitionOnly) bool recognitionOnly;
@property (nonatomic) NSNumber * engineVersion;
@property (nonatomic, getter=isCacheEnabled) bool cacheEnabled;
@property (nonatomic) NSDate * downloadDate;
-(bool)isObsolete;

@end
