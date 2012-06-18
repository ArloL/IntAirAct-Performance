#import <Foundation/Foundation.h>
#import <RestKit/RKObjectManager.h>

@interface RKObjectManager (Blocks) <RKObjectLoaderDelegate>

- (RKObjectLoader *)loaderWithResourcePath:(NSString *)resourcePath handler:(void (^)(RKObjectLoader *loader, NSError *error))handler;

- (id)loaderWithURL:(RKURL *)URL handler:(void (^)(RKObjectLoader *loader, NSError *error))handler;

- (void)loadObjectsAtResourcePath:(NSString*)resourcePath withLoaderHandler:(void (^)(RKObjectLoader *loader, NSError *error))handler;

- (void)putObject:(id<NSObject>)object handler:(void (^)(RKObjectLoader *loader, NSError *error))handler;

- (void)loadObjectsAtResourcePath:(NSString*)resourcePath handler:(void (^)(NSArray * objects, NSError * error))handler;

- (void)loadObjectAtResourcePath:(NSString*)resourcePath handler:(void (^)(NSObject * object, NSError * error))handler;

- (void)loadDictionaryAtResourcePath:(NSString*)resourcePath handler:(void (^)(NSDictionary * dictionary, NSError * error))handler;

@end