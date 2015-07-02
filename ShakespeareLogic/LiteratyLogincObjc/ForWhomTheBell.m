//
//  ForWhomTheBell.m
//  ShakespeareLogic
//
//  Created by Max Bilbow on 02/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Poetry : NSObject
///For whom the bell tolls
+ (void)askAboutTheBell:(NSString*)question error:(NSError **)errorPtr;
@end

@implementation Poetry

+ (void)askAboutTheBell:(NSString *)question error:(NSError **)errorPtr
{
    if (question != nil) {
        *errorPtr = [NSError errorWithDomain:@"Ask NOT for whom the bell tolls. It tolls for thee!"
                                        code:0
                                    userInfo:nil];
    } else {
        printf("Very good");
    }
}

@end