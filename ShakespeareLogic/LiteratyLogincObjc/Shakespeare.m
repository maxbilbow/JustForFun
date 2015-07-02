//
//  Shakespeare.m
//  ShakespeareLogic
//
//  Created by Max Bilbow on 02/07/2015.
//  Copyright © 2015 Rattle Media. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Shakespeare Logic
 Because Swift is such a readable programming language,
 I have begun an ambitious project to rewrite all of Shakespeare’s literature in it...
 And compare it with Others
 */
@interface Shakespeare : NSObject
///To be or not to be...
+ (void)toBe:(bool)toBe;
@end


@implementation Shakespeare

+ (void)toBe:(bool)toBe
{
    if (toBe || !toBe) {
        printf("That is the Question\n");
    }
}

@end
