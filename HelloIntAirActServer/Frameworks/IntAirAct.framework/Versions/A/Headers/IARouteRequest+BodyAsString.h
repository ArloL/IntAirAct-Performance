#import <RoutingHTTPServer/RoutingHTTPServer.h>

/** An extension of RouteRequest to be able to return the body as a string. */
@interface RouteRequest (BodyAsString)

/** @return The body of the request as a string. */
-(NSString *)bodyAsString;

@end
