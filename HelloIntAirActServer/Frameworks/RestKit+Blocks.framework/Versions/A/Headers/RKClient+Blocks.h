#import <Foundation/Foundation.h>
#import <RestKit/RestKit.h>

extern NSString *kNDidLoadResponse;
extern NSString *kNDidFailLoadResponse;

@interface RKClient (Blocks) <RKRequestDelegate>

- (RKRequest *)requestWithResourcePath:(NSString *)resourcePath withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

- (RKRequest *)get:(NSString *)resourcePath withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

- (RKRequest *)get:(NSString *)resourcePath queryParams:(NSDictionary *)queryParams withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

- (RKRequest *)post:(NSString *)resourcePath params:(NSObject<RKRequestSerializable> *)params withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

- (RKRequest *)put:(NSString *)resourcePath params:(NSObject<RKRequestSerializable> *)params withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

- (RKRequest *)delete:(NSString *)resourcePath withCompletionHandler:(void (^)(RKResponse *response, NSError *error))handler;

@end