//
//  main.m
//  pgfd
//
//  Created by Max Bilbow on 13/08/2015.
//  Copyright © 2015 Max Bilbow. All rights reserved.
//

#import <Foundation/Foundation.h>

NSMutableArray * solution(int N, NSMutableArray *A) {
    NSUInteger max = 0;
    NSMutableArray * counters = [[NSMutableArray alloc]initWithCapacity:N];
    NSUInteger M = [A count];
    for (int i=0; i<M; ++i) {
        int n = (int)[A objectAtIndex:i];
        if (n < N + 1) {
            int newVal = (int)[counters objectAtIndex:n-1] + 1;
            [counters setObject:@(newVal) atIndexedSubscript:n-1];//  = @(newVal);
            if (newVal > max) {
                max = newVal;
            }
        } else if (n == N + 1) {
            for (int j=0; j<N; ++j) {
                [counters setObject:@(max) atIndexedSubscript:j];
            }
        } else {
            printf("ERROR: A[%i] = %i\n",i,n);
        }
    }
    
    return counters;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
    }
    return 0;
}
