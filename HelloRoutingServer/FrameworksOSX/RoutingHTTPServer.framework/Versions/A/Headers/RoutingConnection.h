#import <Foundation/Foundation.h>
#import <CocoaHTTPServer/HTTPConnection.h>
@class RoutingHTTPServer;

@interface RoutingConnection : HTTPConnection {
	RoutingHTTPServer *http;
	NSDictionary *headers;
}

@end
