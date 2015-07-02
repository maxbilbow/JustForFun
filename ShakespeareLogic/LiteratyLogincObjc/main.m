//
//  main.m
//  LiteratyLogincObjc
//
//  Created by Max Bilbow on 02/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "Shakespeare.m"


@interface Poetry : NSObject
///For whom the bell tolls
+ (void)askAboutTheBell:(NSString*)question;
@end

@implementation Poetry

+ (void)askAboutTheBell:(NSString *)question
{
    if (question != nil) {
        @throw [NSException exceptionWithName:@"Bell Tolls Exception"
                                       reason:@"\nAsk NOT for whom the bell tolls. It tolls for thee!"
                                     userInfo:nil];
        
    } else {
        printf("\nVery good\n");
    }
}

@end

int main(int argc, const char * argv[]) {
    @try {
        [Poetry askAboutTheBell:@"For whom does the bell toll?"];
    }
    @catch (NSException *exception) {
        NSLog([exception reason],"@");
    }
    @finally {
        [Poetry askAboutTheBell:nil];
    }
    
    return 0;
}



