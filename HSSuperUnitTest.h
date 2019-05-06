//
//  HSSuperUnitTest.h
//  HSYG
//
//  Created by suntao on 2017/9/21.
//  Copyright © 2017年 HSYG. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <UIKit/UIKit.h>
#import "HSCommon.h"
#import "CommonText.h"
#import "MYClassMethod.h"
#import "MBProgressHUD+Loading.h"
#import <objc/runtime.h>
#import <objc/message.h>
#import <OCMock/OCMock.h>

#define assertTrue(expr)                            XCTAssertTrue((expr), @"")
#define assertFalse(expr)                           XCTAssertFalse((expr), @"")
#define assertNil(expr)                             XCTAssertNil((expr), @"")
#define assertNotNil(expr)                          XCTAssertNotNil((expr), @"")
#define assertEqual(a1,a2)                          XCTAssertEqual((a1), (a2), @"")
#define assertEqualObjects(a1,a2)                   XCTAssertEqualObjects((a1), (a2), @"")
#define assertNotEqualObjects(a1,a2)                XCTAssertNotEqualObjects((a1), (a2), @"")
#define assertEqualWithAccuracy(a1,a2,acc)          XCTAssertEqualWithAccuracy((a1), (a2), (acc))
#define assertHUDMessageEqualObject(expr)           assertEqualObjects([MBProgressHUD showMessgae], expr);

#define WAIT                                                                                                \
do {                                                                                                        \
    [self expectationForNotification:@"HSYGUnitTestNotification" object:nil handler:nil];                   \
    [self waitForExpectationsWithTimeout:60 handler:nil];                                                   \
} while(0);

#define NOTIFI                                                                                              \
do {                                                                                                        \
    [[NSNotificationCenter defaultCenter] postNotificationName:@"HSYGUnitTestNotification" object:nil];     \
}while(0);

///类模拟
#define HSOCMClassMock(Clase) OCMClassMock([Clase class])
///部分模拟
#define HSOCMPartialMock(Object) OCMPartialMock(Object)
///严格模拟
#define HSOCMStrictClassMock(Class) OCMStrictClassMock([Class class])

///stub某方法，设置返回值
#define HSOCMStubAndReturn(expr, value) OCMStub(expr).andReturn(value)
///stub某方法，委托执行Object的expr2方法
#define HSOCMStubAndCall(expr1, Object, expr2) OCMStub(expr1).andCall(Object,@selector(expr2));
///期望某方法，设置返回值
#define HSOCMExpectAndReturn(expr, value) OCMExpect(expr).andReturn(value)

@interface HSSuperUnitTest : XCTestCase

///获取一个类的私有属性   propertyName想获取的属性 privateClass类的对象
-(id)GetPrivateProperty:(NSString *)propertyName PrivateClass:(id)privateClass;
///修改某个类的私有属性 
-(Ivar)ModifPrivateProperty:(NSString *)propertyName PrivateClass:(id)privateClass;

@end
