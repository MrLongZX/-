//
//  HSSuperUnitTest.m
//  HSYG
//
//  Created by suntao on 2017/9/21.
//  Copyright © 2017年 HSYG. All rights reserved.
//

#import "HSSuperUnitTest.h"

@implementation HSSuperUnitTest

-(id)GetPrivateProperty:(NSString *)propertyName PrivateClass:(id)privateClass{
    Ivar ivar = class_getInstanceVariable([privateClass class], [propertyName UTF8String]);
    return object_getIvar(privateClass, ivar);
}

-(Ivar)ModifPrivateProperty:(NSString *)propertyName PrivateClass:(id)privateClass{
    unsigned  int count = 0;
    Ivar *members = class_copyIvarList([privateClass class], &count);
    
    for (int i = 0; i < count; i++)
    {
        Ivar var = members[i];
        //你想要的属性
        const char * youWantProperty = ivar_getName(var);
        //属性的类型
        //const char *memberType = ivar_getTypeEncoding(var);
        if ([[NSString stringWithFormat:@"%s",youWantProperty] isEqualToString:propertyName]) {
            return  members[i];
        }
    }
    return nil;
}

@end
